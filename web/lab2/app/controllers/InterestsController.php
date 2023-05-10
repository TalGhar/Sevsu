<?php
class InterestsController extends Controller
{
    function __construct(){
        $this->model = new InterestsModel();
        $this->view = new View();
    }
    
    function indexAction()
    {
        $this->view->render('InterestsView.php', 'Мои интересы', $this->model->get_data());
    }
}