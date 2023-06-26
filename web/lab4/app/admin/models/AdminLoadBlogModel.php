<?php

class AdminLoadBlogModel extends Model
{
    public function __construct()
    {
        static::$tablename = 'my_blog';
        static::$dbfields = array('title', 'date', 'image', 'message');
    }

    public function uploadPosts($files_array) {
        $lines = file($files_array["file"]["tmp_name"]);
        $posts = [];
        foreach ($lines as $str) {
            array_push($posts, preg_split('/;/', $str));
        }

        try {
            foreach ($posts as $post) {
                $this->save($post);
            }
        } catch (\Throwable $th) {
            return false;
        }

        return true;
    }

}