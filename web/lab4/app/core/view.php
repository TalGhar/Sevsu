<?php
class View
{
    function render($content_view, $title, $model = null, $layout = 'layout.php', $admin_prefix = '')
    {
        include 'app/' . $admin_prefix . 'views/' . $layout;
    }
}