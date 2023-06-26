<?php

require_once "app/admin/controllers/AdminController.php";
class AdminGuestLoadController extends AdminController
{

    function __construct() {
        parent::__construct();
        $this->model = new AdminGuestLoadModel();
        $this->view = new View();
    }

    function indexAction()
    {
        $this->checkIsAuth();
        $this->view->render('AdminGuestLoadView.php', 'Загрузка гостевой книги', null, 'admin_layout.php', 'admin/');

    }

    function createAction()
    {
        $this->checkIsAuth();
        if (!empty($_FILES['file']['name'])) {
            if ($_FILES['file']['name'] === 'messages.inc') {
                $messages = $this->model->getMessages($_FILES['file']['name']);
                $this->view->render('GuestView.php', 'Гостевая книга', $messages);
            }
        }
    }

}