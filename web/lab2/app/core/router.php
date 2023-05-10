<?php
class Router
{

    static function route()
    {
        $server_url = explode('/', $_SERVER['REQUEST_URI']);

        $action_name = 'index';

        if (!empty($server_url[2])) {
            
            $controller_name = $server_url[2];
        }

        if (!empty($server_url[3])) {

            $action_name = $server_url[3];
        }

        $action_name .= 'Action';

        if ($controller_name == '/' || $controller_name == '')
            $controller_name = 'Main';

        $controller_file = 'app/controllers/' . $controller_name . 'Controller.php';

        $model_name = $controller_name;
        $model_file = 'app/models/' . $model_name . "Model.php";

        if (file_exists($model_file)) {
            include $model_file;
        }

        if (file_exists($controller_file)) {
            include $controller_file;
        }

        $controller_class_name = ucfirst($controller_name) . 'Controller';

        $controller = new $controller_class_name;

        if (method_exists($controller, $action_name)) {
            $controller->$action_name();
        }

    }

}