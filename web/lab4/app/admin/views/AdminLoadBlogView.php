<body class="bg-gray-200">

    <div class="max-w-md mx-auto m-10">
        <form class="bg-white shadow-md rounded px-8 pt-6 pb-8 mb-4" method="POST" action="/lab4/admin/LoadBlog/load"
            enctype="multipart/form-data">
            <div class="mb-4">
                <label class="block text-gray-700 font-bold mb-2" for="csv-file">
                    Выберите файл CSV для загрузки
                </label>
                <input
                    class="appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:shadow-outline"
                    id="csv-file" type="file" name="file">
            </div>
            <div class="flex items-center justify-between">
                <button
                    class="bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded focus:outline-none focus:shadow-outline"
                    type="submit">
                    Загрузить
                </button>
            </div>
        </form>
    </div>


    <div class="max-w-xl mx-auto p-6 flex-col text-center">
        <?php
        if (!empty($model)) {
            echo '<div class="flex-col">' . $model . '</div>';
        }
        ?>
    </div>

    <footer class="bg-slate-900 rounded-lg shadow m-4">
        <div class="w-full mx-auto max-w-screen-xl p-4 md:flex md:items-center md:justify-between">
            <span class="text-sm text-gray-400 sm:text-center">© 2023 <a href="https://vk.com/tallghar"
                    class="hover:underline">TalGhar™</a>. All Rights Reserved.
            </span>
            <ul class="flex flex-wrap items-center mt-3 text-sm font-medium text-gray-400 sm:mt-0">
                <li>
                    <a href="#" class="mr-4 md:mr-6 ">Нет</a>
                </li>
                <li>
                    <a href="#" class="mr-4 md:mr-6">Здесь</a>
                </li>
                <li>
                    <a href="#" class="mr-4 md:mr-6">Ничего</a>
                </li>
                <li>
                    <a href="#">Абсолютно</a>
                </li>
            </ul>
        </div>
    </footer>
</body>