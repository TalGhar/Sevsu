<?php

require_once "app/admin/controllers/AdminController.php";

class AdminStatsController extends AdminController
{
    function __construct()
    {
        $this->model = new AdminStatsModel();
        $this->view = new View();
    }

    function indexAction()
    {
        $this->checkIsAuth();
        $result = $this->model->getStats($_GET);
        $this->view->render('AdminStatsView.php', 'Статистика посещений', $result, 'admin_layout.php', 'admin/');
    }
}