<?php
class AlbumController extends Controller
{

    function __construct()
    {
        $this->model = new AlbumModel();
        $this->view = new View();
    }

    function indexAction()
    {
        $this->view->render('AlbumView.php', 'Альбом', $this->model->get_data());
    }
}