<?php
class GuestController extends Controller
{
    function indexAction()
    {
        $this->view->render('GuestView.php', 'Гостевая книга');
    }
}