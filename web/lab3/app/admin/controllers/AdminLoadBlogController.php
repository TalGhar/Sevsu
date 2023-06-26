<?php

require_once "app/admin/controllers/AdminController.php";

class AdminLoadBlogController extends AdminController
{

    function __construct()
    {
        $this->model = new AdminLoadBlogModel();
        $this->view = new View();
    }

    function indexAction()
    {
        $this->checkIsAuth();
        $this->view->render('AdminLoadBlogView.php', 'Загрузка сообщений блога', null, 'admin_layout.php', 'admin/');
    }

    function loadAction()
    {
        $this->checkIsAuth();
        if ($_FILES["file"]["name"] != "uploads.csv") {
            $error = "Необходимо выбрать файл uploads.csv";
            $this->view->render('AdminLoadBlogView.php', 'Загрузка сообщений блога', $error, 'admin_layout.php', 'admin/');
        } else {
            $this->model->uploadPosts($_FILES);
            $this->view->render('AdminLoadBlogView.php', 'Загрузка сообщений блога', null, 'admin_layout.php', 'admin/');
        }
    }

}