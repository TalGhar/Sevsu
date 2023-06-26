<?php

class AdminAuthController extends Controller
{
    function indexAction()
    {
        $this->view->render('AdminAuthView.php', 'Вход', null, 'admin_layout.php', 'admin/');
    }

    function loginAction()
    {

        if (!empty($_POST)) {

            $this->model->validator->validate($_POST);
            $errors = $this->model->validator->showErrors();
            if (empty($errors)) {

                if ($this->compareLoginData($_POST)) {
                    header('Location:/lab3/admin/Stats');
                    exit;
                } else {
                    $login = false;
                    $_POST['password'] = null;
                }
            }

            $vars = ['errors' => $errors, 'login' => $login];
            $this->view->render('AdminAuthView.php', 'Вход', $vars, 'admin_layout.php');
        } else {
            $this->view->render('AdminAuthView.php', 'Вход', null, 'admin_layout.php');
        }
    }

    function logoutAction()
    {
        unset($_SESSION['isAdmin']);
        header('Location:/lab3/admin/Auth');
        exit;
    }

    function compareLoginData($post_array)
    {
        if (($post_array['username'] === 'admin') && (md5($post_array['password']) === '21232f297a57a5a743894a0e4a801fc3')) {
            echo ("<script>console.log('PHP: da');</script>");
            $_SESSION['isAdmin'] = 1;
            return true;
        }
        return false;
    }
}