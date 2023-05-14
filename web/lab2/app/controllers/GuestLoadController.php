<?php
class GuestLoadController extends Controller
{

    function __construct() {
        $this->model = new GuestLoadModel();
        $this->view = new View();
    }

    function indexAction()
    {
        $this->view->render('GuestLoadView.php', 'Загрузка гостевой книги');

    }

    function createAction()
    {
        if (!empty($_FILES['file']['name'])) {
            if ($_FILES['file']['name'] === 'messages.inc') {
                $messages = $this->model->getMessages($_FILES['file']['name']);
                $this->view->render('GuestView.php', 'Гостевая книга', $messages);
            }
        }
    }

}