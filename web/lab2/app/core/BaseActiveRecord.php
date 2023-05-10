<?php

class BaseActiveRecord
{
    public static $pdo;
    protected static $tablename;
    protected static $dbfields = array();
    public function __construct()
    {
        if (!static::$tablename) {
            return;
        }

        static::setupConnection();
        static::getFields();
    }

    public static function getFields()
    {
        $stmt = static::$pdo->query("SHOW FIELDS FROM " . static::$tablename);
        while ($row = $stmt->fetch()) {
            static::$dbfields[$row['Field']] = $row['Type'];
        }
    }
    public static function setupConnection()
    {
        if (!isset(static::$pdo)) {
            $eror = false;
            try {
                static::$pdo = new PDO("mysql:dbname=lab2; host=localhost; char-
        set=utf8", "root", "2233");
            } catch (PDOException $ex) {
                die("Ошибка подключения к БД: $ex");
            }
        }
    }

    public static function find($id)
    {
        $sql = "SELECT * FROM " . static::$tablename . " WHERE id=$id";
        $stmt = static::$pdo->query($sql);
        $row = $stmt->fetch(PDO::FETCH_ASSOC);
        if (!$row) {
            return null;
        }
        $ar_obj = new static();
        foreach ($row as $key => $value) {
            $ar_obj->$key = $value;
        }
        return $ar_obj;
    }
    public static function findAll()
    {

    }
    public function save()
    {

    }
    public function delete()
    {
        $sql = "DELETE FROM " . static::$tablename . " WHERE ID=" . $this->id;
        $stmt = static::$pdo->query($sql);

        if ($stmt) {
            return $stmt->fetch(PDO::FETCH_ASSOC);
        } else {
            print_r(static::$pdo->errorInfo());
        }
    }

}