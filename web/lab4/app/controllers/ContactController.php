<?php
class ContactController extends Controller
{
    function indexAction()
    {
        $this->model->saveUserInfo("Контакты");
        $this->view->render('ContactView.php', 'Контакты');
    }

    function checkAction()
    {
        if (!empty($_POST)) {
            $this->model->validator->validate($_POST);
            $errors = $this->model->validator->showErrors();
            $this->view->render('ContactView.php', 'Контакты', $errors);
        } else {
            $this->view->render('ContactView.php', 'Контакты');
        }
        
    }
}