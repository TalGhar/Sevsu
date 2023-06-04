<?php
class LoadBlogController extends Controller
{


    function __construct()
    {
        $this->model = new LoadBlogModel();
        $this->view = new View();
    }

    function indexAction()
    {
        $this->view->render('LoadBlogView.php', 'Загрузка сообщений блога');
    }

    function loadAction()
    {
        if($_FILES["file"]["name"] != "uploads.csv") {
            $error = "Необходимо выбрать файл uploads.csv";
            $this->view->render('LoadBlogView.php', 'Загрузка сообщений блога', $error);
        } else {
            $this->model->uploadPosts($_FILES);
            $this->view->render('LoadBlogView.php', 'Загрузка сообщений блога');
        }


    }

}