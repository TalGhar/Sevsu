<?php
require 'app/models/validators/CustomFormValidation.php';

class ResultVerification extends CustomFormValidation
{
    private $answers = [
    ];
    private $result = 0;

    public function __construct()
    {
        parent::__construct();
        $this->setAnswer('answer1', '1');
        $this->setAnswer('answer2', 'mda');
        $this->setAnswer('answer3', 'da');
    }

    public function checkAnswers($post_array)
    {
        foreach ($this->answers as $field => $value) {
            if ($post_array[$field] == $value) {
                $this->result++;
            }
        }
            
    }

    public function get_results()
    {
        return $this->result;
    }

    public function setAnswer($field_name, $answer)
    {
        $this->answers[$field_name] = $answer;
    }

}


?>