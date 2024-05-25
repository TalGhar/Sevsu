/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.talghar.backend.controllers;

import com.talghar.backend.models.TestModel;

import java.util.ArrayList;
import java.util.List;
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
public class TestModelController {

    private List<TestModel> test = createList();

    @RequestMapping(value = "/test", method = RequestMethod.GET,
            produces = "application/json")
    public List<TestModel> getTest() {
        return test;
    }

    private static List<TestModel> createList() {
        List<TestModel> tempTest = new ArrayList<>();

        TestModel test = new TestModel();
        test.setID(1);
        TestModel test2 = new TestModel();
        test2.setID(2);
        tempTest.add(test);
        tempTest.add(test2);

        return tempTest;
    }

}
