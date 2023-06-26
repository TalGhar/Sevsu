<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <script src="https://cdn.tailwindcss.com"></script>
  <title>
    <?php echo $title ?>
  </title>
</head>

<body>

  <nav class="flex items-center justify-between flex-wrap bg-slate-900 p-4">
    <div class="flex items-center flex-shrink-0 text-gray-400">
      <div id="clock" class="w-32 font-semibold text-3xl tracking-tight mr-10 flex"></div>

      <div class="w-full block flex-grow lg:flex lg:items-center lg:w-auto">
        <div class="text-xl lg:flex-grow">
          <a href="/lab4/admin/Stats"
            class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Статистика
            посещений</a>
          <a href="/lab4/admin/GuestLoad"
            class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Загрузка сообщений
            гостевой книги</a>
          <a href="/lab4/admin/BlogEditor"
            class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Редактор блога</a>
          <a href="/lab4/admin/LoadBlog"
            class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Загрузка постов
            блога</a>

          <?php
          if (!$_SESSION['isAdmin'])
            echo '<a href="/lab4/admin/Auth"
            class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Вход</a>';
          else {
            echo '<a href="/lab4/admin/Auth/logout"
            class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Выйти</a>';
          }
          ?>
          
        </div>
      </div>

    </div>
  </nav>

  <?php include 'app/admin/views/' . $content_view;

  ?>

  <script src="public/assets/js/dropdown_script.js"></script>
  <script src="public/assets/js/time_script.js"></script>

</body>

</html>