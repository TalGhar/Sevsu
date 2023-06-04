<?php
class BlogEditorController extends Controller
{

    function __construct()
    {
        $this->model = new BlogEditorModel();
        $this->view = new View();
    }

    function indexAction()
    {
        $result = $this->model->getBlogPosts($_GET);
        $this->view->render('BlogEditorView.php', 'Редактор блога', $result);
    }

    function addAction() {
		if (!empty($_POST)) {
            $this->model->validator->validate($_POST);
            $errors = $this->model->validator->showErrors();

            if (empty($errors)) {
                $this->model->newPost($_POST, $_FILES);
                $_POST = array();
            }

            $result = $this->model->getBlogPosts($_GET);
            $result['errors'] = $errors;
			$this->view->render('BlogEditorView.php', 'Редактор блога', $result);
		} else {
            $this->view->render('BlogEditorView.php', 'Редактор блога');
        }
	}

}