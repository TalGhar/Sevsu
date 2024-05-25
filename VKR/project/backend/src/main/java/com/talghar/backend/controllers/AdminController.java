/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.talghar.backend.controllers;

import java.io.IOException;
import java.nio.file.Paths;
import org.hyperledger.fabric.gateway.Wallet;
import org.hyperledger.fabric.gateway.Wallets;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

/**
 *
 * @author talghar
 */
@CrossOrigin(origins = "http://localhost:3000")
@RestController

public class AdminController {

    @RequestMapping(value = "/admin", method = RequestMethod.GET,
            produces = "application/json")
    public boolean check() throws IOException {
        Wallet wallet = Wallets.newFileSystemWallet(Paths.get("wallet"));
        return wallet.get("admin") != null;
    }
}
