<?php

class AdminStatsModel extends Model
{
    public function __construct()
    {
        parent::__construct();
        static::$tablename = 'stats';
        static::$dbfields = array('page', 'ip', 'host', 'browser', 'date');
    }

    public function getStats($get_array)
    {
        $countOfPosts = $this->getCount();
        $rowsPerPage = 6;
        $totalPages = ceil($countOfPosts / $rowsPerPage);

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

        $offset = ($currentPage - 1) * $rowsPerPage;

        $stats = $this->findByPage($offset, $rowsPerPage);

        $result = [
            "stats" => $stats,
            "current_page" => $currentPage,
            "total_pages" => $totalPages
        ];

        return $result;
    }
}