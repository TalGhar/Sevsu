<?php
require 'app/models/validators/ResultsVerification.php';

class TestModel extends Model
{
    public function __construct()
    {
        parent::__construct();
        $this->validator = new ResultVerification();
        static::$tablename = 'test_results';
        static::$dbfields = array('fio', 'date', 'answer1', 'answer2', 'answer3', 'correct_answers');
    }

    public function saveTable($post_array)
    {

        $correct_answers = $this->validator->get_results();

        $data = [
            'fio' => $post_array['ФИО'],
            'date' => date('Y-m-d H:i:s'),
            'answer1' => $post_array['answer1'],
            'answer2' => $post_array['answer2'],
            'answer3' => $post_array['answer3'],
            'correct_answers' => $correct_answers
        ];

        $this->save($data);

    }


}

?>