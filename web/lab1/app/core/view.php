<?php
class View
{
    function render($content_view, $title, $model = null, $layout = 'layout.php')
    {
        include 'app/views/' . $layout;
    }
}