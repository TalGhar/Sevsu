/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.talghar.backend.models;

/**
 *
 * @author talghar
 */
public class LoginRequest {

    private String username;
    private String userSecret;

    public String getUsername() {
        return username;
    }

    public String getUserSecret() {
        return userSecret;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public void setUserSecret(String userSecret) {
        this.userSecret = userSecret;
    }

}
