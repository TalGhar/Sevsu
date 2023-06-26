<?php
class EducationController extends Controller
{
    function indexAction()
    {
        $this->model->saveUserInfo("Учёба");
        $this->view->render('EducationView.php', 'Учёба');
    }
}