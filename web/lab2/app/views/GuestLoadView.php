<body class="bg-gray-200">

    <form class="bg-white shadow-md rounded px-8 pt-6 pb-8 mb-4 m-5" action="/lab2/GuestLoad/create"method="POST" enctype="multipart/form-data">
        <div class="mb-4">
            <label class="block text-gray-700 font-bold mb-2" for="file-upload">
                Выберите файл для загрузки
            </label>
            <div class="flex items-center justify-center w-full">
                <label class="flex flex-col rounded-lg border-4 border-dashed w-full h-32 p-10 group text-center">
                    <div
                        class="h-full w-full text-gray-600  group-hover:text-gray-400 duration-300 flex flex-col justify-center items-center">
                        <svg class="h-12 w-12 text-gray-400 group-hover:text-gray-300 duration-300" fill="none" stroke="currentColor"
                            viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg">
                            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M15 19l-7-7 7-7" />
                        </svg>
                        <span class="text-sm text-gray-600 group-hover:text-gray-400">Нажмите, чтобы выбрать файл</span>
                    </div>
                    <input class="hidden" type="file" name="file" id="file-upload">
                </label>
            </div>
        </div>
        <div class="flex items-center justify-between">
            <button
                class="bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded focus:outline-none focus:shadow-outline"
                type="submit">
                Загрузить
            </button>
        </div>
    </form>

</body>

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


<!-- <?php
if (isset($_FILES['messages_file'])) {
    $file = $_FILES['messages_file'];
    if ($file['error'] == UPLOAD_ERR_OK && $file['type'] == 'text/plain') {
        move_uploaded_file($file['tmp_name'], 'messages.inc');
        echo '<p>Файл успешно загружен на сервер.</p>';
    } else {
        echo '<p>Произошла ошибка загрузки файла.</p>';
    }
}
?> -->