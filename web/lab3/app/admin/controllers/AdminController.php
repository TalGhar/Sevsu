<?php

class AdminController extends Controller
{
    function checkIsAuth()
    {
        if (!isset($_SESSION['isAdmin'])) {
            header('Location:/lab3/admin/Auth');
            exit;
        }
    }
}