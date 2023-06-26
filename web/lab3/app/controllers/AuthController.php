<?php

class AuthController extends Controller {
    function __construct() {
		$this->model = new AuthModel();
		$this->view = new View();
    }

	function signinAction() {
		$this->view->render('SignInView.php', 'Вход', null, 'layout.php');
    }

	function signupAction() {
		$this->view->render('SignUpView.php', 'Регистрация', null, 'layout.php');
    }
    
    function loginAction() {
		if (!empty($_POST)) {
			$this->model->validator->validate($_POST);
            $errors = $this->model->validator->showErrors();

            if (empty($errors)) {
                $findUser = $this->model->findUser($_POST);
                if ($findUser) {
                    $_SESSION['isUser'] = 1;
                    $_SESSION['userFullname'] = $findUser->fullname;
                    header('Location:/lab3/');
                    exit;
                } else {
                    $login = false;
                    $_POST['password'] = null;
                }
            }

            $vars = [ 'errors' => $errors, 'login' => $login ];

			$this->view->render('SignInView.php', 'Вход', $vars, 'layout.php');
		} else {
            $this->view->render('SignInView.php', 'Вход', null, 'layout.php');
        }
    }

    function createAction() {
		if (!empty($_POST)) {
			$this->model->validator->validate($_POST);
            $errors = $this->model->validator->showErrors();
            if (empty($errors)) {
                if ($this->model->createUser($_POST)) {
                    $_POST = array();
                    header('Location:/lab3/Auth/signin');
                    exit;
                } else {
                    $result = false;
                }
            }

            $vars = [ 'errors' => $errors, 'result' => $result ];

			$this->view->render('SignUpView.php', 'Регистрация', $vars, 'layout.php');
		} else {
            $this->view->render('SignUpView.php', 'Регистрация', null, 'layout.php');
        }
    }

    function logoutAction() {
        unset($_SESSION['isUser']);
        header('Location:/lab3/Auth/signin');
        exit;
    }
}