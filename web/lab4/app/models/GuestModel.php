<?php

class GuestModel extends Model
{

    public function getMessage()
    {
        $last_name = $_POST['last_name'];
        $first_name = $_POST['first_name'];
        $middle_name = $_POST['middle_name'];
        $email = $_POST['email'];
        $message = $_POST['message'];
        $date = date('d.m.y');

        $data = "$date;$last_name $first_name $middle_name;$email;$message\n";

        return $data;

    }

    public function getMessages($file)
    {
        $lines = explode("\n", $file);
        $result = array();

        foreach (array_reverse($lines) as $line) {
            if (!empty($line)) {
                $fields = explode(";", $line);
                $date = $fields[0];
                $fio = explode(" ", $fields[1]);
                $fio = implode(" ", $fio);
                $email = $fields[2];
                $message = $fields[3];
                $result[] = array(
                    'date' => $date,
                    'fio' => $fio,
                    'email' => $email,
                    'message' => $message
                );
            }
        }
        return $result;
    }



    public function saveMessage($message)
    {
        $file = fopen('messages.inc', 'a');
        fwrite($file, $message);
        fclose($file);
    }

}