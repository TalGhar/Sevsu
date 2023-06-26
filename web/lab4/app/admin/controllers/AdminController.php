<?php

class AdminController extends Controller
{
    function checkIsAuth()
    {
        if (!isset($_SESSION['isAdmin'])) {
            header('Location:/lab4/admin/Auth');
            exit;
        }
    }
}