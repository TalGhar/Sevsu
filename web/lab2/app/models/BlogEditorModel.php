<?php
class BlogEditorModel extends Model
{

    public function __construct()
    {
        parent::__construct();
        static::$tablename = 'my_blog';
        static::$dbfields = array('title', 'date', 'image', 'message');
    }

    public function getBlogPosts($get_array)
    {

        $posts = $this->findAll();

        $result = [
            "posts" => $posts
        ];

        return $result;

    }

    public function newPost($post_array, $file_array) {
        if ($file_array["image"]["size"] > 0) {
            $this->saveImageInFolder($file_array);
            $data = [
                "title" => $post_array["title"],
                "date" => date('Y-m-d H:i:s'),
                "image" => $file_array["image"]["name"],
                "message" => $post_array["message"]
            ];
        } else {
            $data = [
                "title" => $post_array["title"],
                "date" => date('Y-m-d H:i:s'),
                "image" => NULL,
                "message" => $post_array["message"]
            ];
        }
        $this->save($data);
    }

    private function saveImageInFolder($files_array) {

        $upload_dir = '/lab2/public/assets/img/';
        $file = $files_array['image'];
        $file_name = basename($file['name']);
        $upload = $upload_dir . $file_name;
        $file_tmp = $file['tmp_name']; 

        move_uploaded_file($file_tmp, $upload);

    }

}