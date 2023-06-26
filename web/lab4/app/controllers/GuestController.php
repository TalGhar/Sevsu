<?php
class GuestController extends Controller
{

    function __construct()
    {
        $this->model = new GuestModel();
        $this->view = new View();
    }

    function indexAction()
    {
        $this->model->saveUserInfo("Гостевая книга");
        if (!empty($_POST)) {
            $message = $this->model->getMessage();
            $this->model->saveMessage($message);
            $this->view->render('GuestView.php', 'Гостевая книга');
        }
        else {
            $this->view->render('GuestView.php', 'Гостевая книга');
        }
        
    }

}