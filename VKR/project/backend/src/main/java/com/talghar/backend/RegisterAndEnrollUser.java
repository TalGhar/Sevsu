/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.talghar.backend;

import java.io.File;
import java.nio.file.Paths;
import java.security.PrivateKey;
import java.util.Properties;
import java.util.Set;
import org.hyperledger.fabric.gateway.IdemixEnrollmentSerialized;
import org.hyperledger.fabric.gateway.Identities;

import org.hyperledger.fabric.gateway.Identity;
import org.hyperledger.fabric.gateway.Wallet;
import org.hyperledger.fabric.gateway.Wallets;
import org.hyperledger.fabric.gateway.X509Identity;

import org.hyperledger.fabric.sdk.Enrollment;
import org.hyperledger.fabric.sdk.User;
import org.hyperledger.fabric.sdk.idemix.IdemixCredential;
import org.hyperledger.fabric.sdk.idemix.IdemixSignature;
import org.hyperledger.fabric.sdk.identity.IdemixEnrollment;

import org.hyperledger.fabric.sdk.security.CryptoSuite;
import org.hyperledger.fabric.sdk.security.CryptoSuiteFactory;
import org.hyperledger.fabric_ca.sdk.Attribute;
import org.hyperledger.fabric_ca.sdk.EnrollmentRequest;
import org.hyperledger.fabric_ca.sdk.HFCAClient;
import org.hyperledger.fabric_ca.sdk.RegistrationRequest;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 *
 * @author talghar
 */
@CrossOrigin(origins = "http://localhost:3000")
@RestController
public class RegisterAndEnrollUser {

    static {
        System.setProperty("org.hyperledger.fabric.sdk.service_discovery.as_localhost", "true");
    }

    @RequestMapping(value = "/registerUser")
    public static void main(String[] args) throws Exception {

        String enrollmentId = "testUser11";
        String caCertPEM = new File(System.getProperty("user.dir")).getParentFile() + "/idemix-network/organizations/peerOrganizations/org1.example.com/ca/ca.org1.example.com-cert.pem";

        Properties props = new Properties();
        props.put("pemFile", caCertPEM);
        props.put("allowAllHostNames", "true");
        HFCAClient caClient = HFCAClient.createNewInstance("https://localhost:7054", props);

        CryptoSuite cryptoSuite = CryptoSuiteFactory.getDefault().getCryptoSuite();

        caClient.setCryptoSuite(cryptoSuite);

        Wallet wallet = Wallets.newFileSystemWallet(Paths.get("wallet"));

        if (wallet.get(enrollmentId) != null) {
            System.out.println("The user " + enrollmentId + " already registered in wallet");
            return;
        }

        X509Identity adminIdentity = (X509Identity) wallet.get("admin");
        if (adminIdentity == null) {
            System.out.println("\"admin\" needs to be enrolled and added to the wallet first");
            return;
        } else {
            System.out.println("\"admin\" have already enrolled and found at the wallet");
        }

        User admin = new User() {

            @Override
            public String getName() {
                return "admin";
            }

            @Override
            public Set<String> getRoles() {
                return null;
            }

            @Override
            public String getAccount() {
                return null;
            }

            @Override
            public String getAffiliation() {
                return "org1.department1";
            }

            @Override
            public Enrollment getEnrollment() {
                return new Enrollment() {

                    @Override
                    public PrivateKey getKey() {
                        return adminIdentity.getPrivateKey();
                    }

                    @Override
                    public String getCert() {
                        return Identities.toPemString(adminIdentity.getCertificate());
                    }
                };
            }

            @Override
            public String getMspId() {
                return "Org1MSP";
            }

        };

        RegistrationRequest registrationRequest = new RegistrationRequest(enrollmentId);
        registrationRequest.setAffiliation("org1.department1");
        registrationRequest.setEnrollmentID(enrollmentId);
        Attribute testAttr = new Attribute("Test", "GaleninAK");
        registrationRequest.addAttribute(testAttr);

        EnrollmentRequest enrollmentRequest = new EnrollmentRequest();
        enrollmentRequest.addAttrReq("Test");

        String enrollmentSecret = caClient.register(registrationRequest, admin);

        Enrollment enrollment = caClient.enroll(enrollmentId, enrollmentSecret, enrollmentRequest);

        IdemixEnrollment idemixEnrollment = (IdemixEnrollment) caClient.idemixEnroll(enrollment, "Org1IdemixMSP");
        System.out.println("\nIdemix Enrollment IPK: " + idemixEnrollment.getIpk());
        System.out.println("\nIdemix enrollment MSP: " + idemixEnrollment.getMspId());

        Identity user = Identities.newX509Identity("Org1MSP", enrollment);
        wallet.put(enrollmentId, user);

        Identity id = Identities.newIdemixIdentity("Org1IdemixMSP", idemixEnrollment);
        System.out.println(id.getMspId());
        wallet.put(enrollmentId + "Idemix", id);

        System.out.println("Successfully enrolled user " + enrollmentId + " and imported it into the wallet");

        
    }

}
