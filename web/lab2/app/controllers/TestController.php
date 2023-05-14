<?php
class TestController extends Controller
{

    function __construct()
    {
        $this->model = new TestModel();
        $this->view = new View();
    }
    function indexAction()
    {
        
        $this->view->render('TestView.php', 'Тест');
    }

    function checkAction()
    {
		if (!empty($_POST)) {
			$this->model->validator->validate($_POST);
            $errors = $this->model->validator->showErrors();
			if (empty($errors)) {
				$this->model->validator->checkAnswers($_POST);
                $this->model->saveTable($_POST);
                $result = $this->model->validator->get_results();
                $to_render = ['result' => $result];
			}
			else {
                $to_render = ['errors' => $errors];
            }
            $this->view->render('TestView.php', 'Тест', $to_render);
		} else {
            $this->view->render('TestView.php', 'Тест');
        }

    }

}