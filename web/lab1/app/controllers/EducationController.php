<?php
class EducationController extends Controller
{
    function indexAction()
    {
        $this->view->render('EducationView.php', 'Учёба');
    }
}