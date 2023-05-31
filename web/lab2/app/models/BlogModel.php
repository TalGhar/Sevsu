<?php
class BlogModel extends Model
{

    public function __construct()
    {
        parent::__construct();
        static::$tablename = 'my_blog';
        static::$dbfields = array('title', 'date', 'image', 'message');
    }

    public function getBlogPosts($get_array)
    {
        $countPosts = $this->getCount();
        $rowsOnPage = 5;
        $totalPages = ceil($countPosts / $rowsOnPage);

        if (isset($get_array['page']) && is_numeric($get_array['page'])) {
            $currentPage = (int) $get_array['page'];
        } else {
            $currentPage = 1;
        }

        if ((int) $currentPage > (int) $totalPages) {
            $currentPage = $totalPages;
        }

        if ((int) $currentPage < 1) {
            $currentPage = 1;
        }

        $offset = ($currentPage - 1) * $rowsOnPage;

        $posts = $this->findByPage($offset, $rowsOnPage);

        $result = [
            "posts" => $posts,
            "current_page" => $currentPage,
            "total_pages" => $totalPages
        ];

        return $result;

    }

}