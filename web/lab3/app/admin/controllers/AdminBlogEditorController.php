<?php

require_once "app/admin/controllers/AdminController.php";

class AdminBlogEditorController extends AdminController
{

    function __construct()
    {
        $this->model = new AdminBlogEditorModel();
        $this->view = new View();
    }

    function indexAction()
    {
        $this->checkIsAuth();
        $result = $this->model->getBlogPosts($_GET);
        $this->view->render('AdminBlogEditorView.php', 'Редактор блога', $result, 'admin_layout.php', 'admin/');
    }

    function addAction()
    {
        $this->checkIsAuth();
        if (!empty($_POST)) {
            $this->model->validator->validate($_POST);
            $errors = $this->model->validator->showErrors();

            if (empty($errors)) {
                $this->model->newPost($_POST, $_FILES);
                $_POST = array();
            }

            $result = $this->model->getBlogPosts($_GET);
            $result['errors'] = $errors;
            $this->view->render('AdminBlogEditorView.php', 'Редактор блога', $result, 'admin_layout.php', 'admin/');
        } else {
            $this->view->render('AdminBlogEditorView.php', 'Редактор блога', null, 'admin_layout.php', 'admin/');
        }
    }

}