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
          <a href="/lab4/Main"
            class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Главная</a>
          <a href="/lab4/About" class="block lg:inline-block lg:mt-0 hover:text-slate-400 mr-5">Обо мне</a>

          <div id="dropdown"
            class="inline-block relative mt-4 lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">
            <a href="/lab4/Interests"
              class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300">Мои
              интересы</a>
            <div class="hidden absolute z-50 bg-slate-900 border border-gray-950 text-gray-400" id="dropdownList">
              <a href="/lab4/Interests#Games"
                class="block px-4 py-2 hover:bg-slate-300 hover:text-slate-950 transition duration-300">Игры</a>
              <a href="/lab4/Interests#Books"
                class="block px-4 py-2 hover:bg-slate-300 hover:text-slate-950 transition duration-300">Книги</a>
              <a href="/lab4/Interests#Music"
                class="block px-4 py-2 hover:bg-slate-300 hover:text-slate-950 transition duration-300">Музыка</a>
            </div>
          </div>


          <a href="/lab4/Education"
            class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Учеба</a>
          <a href="/lab4/Album"
            class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Альбом</a>
          <a href="/lab4/Contact"
            class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Контакты</a>
          <a href="/lab4/Test"
            class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Тест</a>
          <a href="/lab4/History"
            class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">История</a>
          <a href="/lab4/Guest"
            class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Гостевая книга</a>
          <a href="/lab4/Blog"
            class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Мой блог</a>

          <?php
          if ($_SESSION['isUser']) {
            ?>
            <p class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Пользователь:
              <?= $_SESSION['userFullname'] ?>
            </p>
            <?php
          } else {
            ?>
            <a href="/lab4/Auth/signin"
              class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Вход</a>
          <?php } ?>

          <?php
          if ($_SESSION['isUser']) {
            ?>
            <a href="/lab4/Auth/logout"
              class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Выход</a>
            <?php
          } else {
            ?>
            <a href="/lab4/Auth/signup"
              class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Регистрация</a>
          <?php } ?>

        </div>
      </div>



    </div>
  </nav>

  <?php include 'app/views/' . $content_view;

  ?>

  <script src="public/assets/js/dropdown_script.js"></script>
  <script src="public/assets/js/time_script.js"></script>

</body>

</html>