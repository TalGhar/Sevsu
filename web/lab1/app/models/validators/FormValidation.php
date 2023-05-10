<?php
class FormValidation
{
    private array $rules = [
        'ФИО' => [
            'isNotEmpty',
        ],
        'Телефон' => [
            'isNotEmpty',
            'isPhone'
        ],
        'Дата' => [
            'isNotEmpty',
        ],
        'Почта' => [
            'isEmail',
        ],
        'Сообщение' => [
            'isNotEmpty',
        ],
        'Группа' => [
            'isNotEmpty'
        ],
    ];

    private array $errors = [

    ];


    public function isNotEmpty($data, $field)
    {
        if (empty($data)) {
            array_push($this->errors, "Поле $field должно быть заполнено");
        }
        return true;
    }

    public function isInteger($data, $field)
    {
        if (ctype_digit($data)) {
            array_push($this->errors, "Поле $field содержит числа");
        }
        return true;
    }

    public function isLess($data, $field, $value = null)
    {
        if (!is_numeric($data) || $data >= $value) {
            array_push($this->errors, "Поле $field должно быть не короче $value");
        }
        return true;
    }

    public function isGreater($data, $field, $value)
    {
        if (!is_numeric($data) || $data <= $value) {
            array_push($this->errors, "Поле $field должно быть не длиннее $value");
        }
        return true;
    }

    public function isEmail($data, $field)
    {
        if (!filter_var($data, FILTER_VALIDATE_EMAIL)) {
            array_push($this->errors, "Поле $field введено неверно");
        }
        return true;
    }

    public function isPhone($data, $field)
    {
        if (!preg_match('/^(\+7|7|8)?[\s\-]?\(?[489][0-9]{2}\)?[\s\-]?[0-9]{3}[\s\-]?[0-9]{2}[\s\-]?[0-9]{2}$/', $data)) {
            array_push($this->errors, "Поле $field введено неверно");
        }
        return true;
    }

    public function setRule($field_name, $validator_name)
    {
        if (!$this->rules[$field_name]) { $this->rules[$field_name] = []; }
        array_push($this->rules[$field_name], $validator_name);
    }

    public function validate($post_array)
    {
        echo $this->rules[''];
        foreach ($post_array as $field => $item) {
            if ($this->rules[$field]) {
                foreach ($this->rules[$field] as $rule) {
                    $this -> $rule($item, $field);
                }
            }
        }
    }

    public function showErrors()
    {
        return $this->errors;
    }


}