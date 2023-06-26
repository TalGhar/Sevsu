<?php
class CustomFormValidation extends FormValidation
{
    public function __construct()
    {
        $this->setRule('answer2', 'isNotEmpty');
        $this->setRule('answer3', 'isNotEmpty');
    }
}