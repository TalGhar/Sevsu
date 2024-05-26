///*
// * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
// * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
// */
//package com.talghar.backend.controllers;
//
//import com.talghar.backend.models.LoginRequest;
//
//import java.net.MalformedURLException;
//
//import java.util.logging.Level;
//import java.util.logging.Logger;
//
//import org.springframework.http.HttpStatus;
//import org.springframework.http.ResponseEntity;
//import org.springframework.web.bind.annotation.CrossOrigin;
//import org.springframework.web.bind.annotation.PostMapping;
//import org.springframework.web.bind.annotation.RequestBody;
//import org.springframework.web.bind.annotation.RequestMapping;
//import org.springframework.web.bind.annotation.RestController;
//
//import java.io.File;
//import java.lang.reflect.InvocationTargetException;
//import java.nio.charset.StandardCharsets;
//import java.util.Base64;
//import java.util.HashMap;
//import java.util.Map;
//
//import java.util.Properties;
//
//import org.hyperledger.fabric.sdk.exception.CryptoException;
//import org.hyperledger.fabric.sdk.security.CryptoSuite;
//import org.hyperledger.fabric.sdk.security.CryptoSuiteFactory;
//import org.hyperledger.fabric_ca.sdk.EnrollmentRequest;
//import org.hyperledger.fabric_ca.sdk.HFCAClient;
//import org.hyperledger.fabric_ca.sdk.exception.EnrollmentException;
//import org.hyperledger.fabric_ca.sdk.exception.InvalidArgumentException;
//import org.springframework.beans.factory.annotation.Autowired;
//import org.springframework.security.authentication.AuthenticationManager;
//import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
//import org.springframework.security.core.Authentication;
//import org.springframework.security.core.context.SecurityContextHolder;
//
///**
// *
// * @author talghar
// */
//@RestController
//@CrossOrigin(origins = "http://localhost:3000")
//@RequestMapping("/api/auth")
//public class AdminAuthController {
//
//    @PostMapping("/login")
//    public ResponseEntity<?> login(@RequestBody LoginRequest loginRequest) {
//        System.out.println(loginRequest.getUsername());
//        System.out.println(loginRequest.getPassword());
//
//        try {
//
//            String caCertPEM = new File(System.getProperty("user.dir")).getParentFile() + "/idemix-network/organizations/peerOrganizations/org1.example.com/ca/ca.org1.example.com-cert.pem";
//            Properties props = new Properties();
//            props.put("pemFile", caCertPEM);
//            props.put("allowAllHostNames", "true");
//            CryptoSuite cryptoSuite = CryptoSuiteFactory.getDefault().getCryptoSuite();
//            HFCAClient caClient = HFCAClient.createNewInstance("https://localhost:7054", props);
//            caClient.setCryptoSuite(cryptoSuite);
//            final EnrollmentRequest enrollmentRequestTLS = new EnrollmentRequest();
//            enrollmentRequestTLS.addHost("localhost");
//            caClient.enroll(loginRequest.getUsername(), loginRequest.getPassword(), enrollmentRequestTLS);
//
//            //Encoding to make expiration token on frontend
//            Map<String, String> response = new HashMap<>();
//            String token = encodeCredentials(loginRequest.getUsername(), loginRequest.getPassword());
//            response.put("expirationToken", token);
//            
//            return ResponseEntity.ok(token);
//
//        } catch (MalformedURLException | EnrollmentException | ClassNotFoundException | IllegalAccessException | InstantiationException | NoSuchMethodException | InvocationTargetException | CryptoException | InvalidArgumentException | org.hyperledger.fabric.sdk.exception.InvalidArgumentException ex) {
//            System.out.println("Ты не прав");
//            return ResponseEntity.status(HttpStatus.UNAUTHORIZED).body(loginRequest);
//        }
//    }
//
//    private String encodeCredentials(String username, String password) {
//        String credentials = username + ":" + password;
//        byte[] encodedBytes = Base64.getEncoder().encode(credentials.getBytes(StandardCharsets.UTF_8));
//        return new String(encodedBytes, StandardCharsets.UTF_8);
//    }
//}
