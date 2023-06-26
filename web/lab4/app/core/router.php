<?php
class Router
{

    static function route()
    {
        $server_url = explode('/', $_SERVER['REQUEST_URI']);

        $controller_name = 'Main';
        $action_name = 'index';

        if ($server_url[2] == 'admin') {


            if (!empty($server_url[3])) {
                $controller_name = $server_url[3];
            }

            if (!empty($server_url[4])) {
                $action_name = $server_url[4];
            }

            $admin_prefix = 'Admin';
            $admin_path = 'admin/';

        } else {

            if (!empty($server_url[2])) {

                $controller_name = $server_url[2];
            }

            if (!empty($server_url[3])) {
                $action_name = $server_url[3];
            }


        }

        $action_name .= 'Action';

        $controller_file = 'app/' . $admin_path . 'controllers/' . $admin_prefix . $controller_name . 'Controller.php';

        $model_name = $controller_name;
        $model_file = 'app/' . $admin_path . 'models/' . $admin_prefix . $model_name . "Model.php";

        if (file_exists($model_file)) {
            include $model_file;
        }

        if (file_exists($controller_file)) {
            include $controller_file;
        }

        $controller_class_name = $admin_prefix . ucfirst($controller_name) . 'Controller';

        $controller = new $controller_class_name;

        if (method_exists($controller, $action_name)) {
            $controller->$action_name();
        }

    }

}