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
          <a href="Main"
            class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Главная</a>
          <a href="About" class="block lg:inline-block lg:mt-0 hover:text-slate-400 mr-5">Обо мне</a>

          <div id="dropdown"
            class="inline-block relative mt-4 lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">
            <a href="Interests" class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300">Мои
              интересы</a>
            <div class="hidden absolute z-50 bg-slate-900 border border-gray-950 text-gray-400" id="dropdownList">
              <a href="Interests#Games"
                class="block px-4 py-2 hover:bg-slate-300 hover:text-slate-950 transition duration-300">Игры</a>
              <a href="Interests#Books"
                class="block px-4 py-2 hover:bg-slate-300 hover:text-slate-950 transition duration-300">Книги</a>
              <a href="Interests#Music"
                class="block px-4 py-2 hover:bg-slate-300 hover:text-slate-950 transition duration-300">Музыка</a>
            </div>
          </div>


          <a href="Education"
            class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Учеба</a>
          <a href="Album"
            class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Альбом</a>
          <a href="Contact"
            class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Контакты</a>
          <a href="Test"
            class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">Тест</a>
          <a href="History"
            class="block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">История</a>

          <div class="group inline-block relative mt-4 lg:mt-0 hover:text-slate-400 transition duration-300">
            <a href="Guest"
              class="group block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">
              Гостевая книга
            </a>
            <ul class="transition duration-300 opacity-0 invisible group-hover:opacity-100 group-hover:visible absolute z-50 bg-slate-900 border border-gray-950 text-gray-400">
              <li><a href="GuestLoad" class="block px-4 py-2 hover:bg-slate-300 hover:text-slate-950 transition duration-300">Загрузить</a></li>
            </ul>
          </div>
          

          <div class="group inline-block relative mt-4 lg:mt-0 hover:text-slate-400 transition duration-300">
            <a href="#" 
              class="group block lg:inline-block lg:mt-0 hover:text-slate-400 transition duration-300 mr-5">
              Мой блог
            </a>
            <ul
              class="transition duration-300 opacity-0 invisible group-hover:opacity-100 group-hover:visible absolute z-50 bg-slate-900 border border-gray-950 text-gray-400">
              <li><a href="#" class="block px-4 py-2 hover:bg-slate-300 hover:text-slate-950 transition duration-300">фыв</a></li>
              <li><a href="#" class="block px-4 py-2 hover:bg-slate-300 hover:text-slate-950 transition duration-300">фыв</a></li>
              <li><a href="#" class="block px-4 py-2 hover:bg-slate-300 hover:text-slate-950 transition duration-300">ыв</a></li>
            </ul>
          </div>


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