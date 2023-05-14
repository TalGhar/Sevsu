<?php

class GuestLoadModel extends Model
{
    public function getMessages($file)
    {
        $contents = file_get_contents($file);
        $lines = explode("\n", $contents);
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
}