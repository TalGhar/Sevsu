<body class="bg-gray-200">
    <form method="POST" id="myForm" action="Contact/check"
        class="max-w-xl mx-auto p-6 bg-slate-700 rounded-lg shadow-md m-2">
        <div class="mb-4">
            <label for="ФИО" class="font-semibold text-slate-200 block mb-2">ФИО:</label>
            <input type="text" id="ФИО" name="ФИО"
                class="w-full px-4 py-2 border border-gray-400 rounded-lg focus:outline-none focus:border-blue-500">
        </div>
        <div class="mb-4">
            <label for="Телефон" class="font-semibold text-slate-200 block mb-2">Телефон:</label>
            <input type="text" id="Телефон" name="Телефон"
                class="w-full px-4 py-2 border border-gray-400 rounded-lg focus:outline-none focus:border-blue-500">
        </div>
        <div class="mb-4">
            <label class="font-semibold text-slate-200 block mb-2">Пол:</label>
            <label class="inline-flex items-center">
                <input type="radio" class="form-radio" name="gender" value="female" checked>
                <span class="ml-2 text-slate-200">Женщина</span>
            </label>
            <label class="inline-flex items-center ml-6">
                <input type="radio" class="form-radio" name="gender" value="male">
                <span class="ml-2 text-slate-200">Мужчина</span>
            </label>
        </div>
        <div class="mb-4">
            <label for="Дата" class="font-semibold text-slate-200 block mb-2">Дата:</label>
            <input type="date" id="Дата" name="Дата"
                class="w-full px-4 py-2 border border-gray-400 rounded-lg focus:outline-none focus:border-blue-500">
        </div>
        <div class="mb-4">
            <label for="Почта" class="font-semibold text-slate-200 block mb-2">Почта:</label>
            <input type="text" id="Почта" name="Почта"
                class="w-full px-4 py-2 border border-gray-400 rounded-lg focus:outline-none focus:border-blue-500">
        </div>
        <div class="mb-4">
            <label for="Сообщение" class="font-semibold text-slate-200 block mb-2">Сообщение:</label>
            <textarea id="text" name="Сообщение"
                class="w-full px-4 py-2 border border-gray-400 rounded-lg focus:outline-none focus:border-blue-500"></textarea>
        </div>
        <div class="flex justify-end">
            <button type="submit"
                class="bg-blue-500 hover:bg-blue-600 text-white px-4 py-2 rounded-lg mr-2">Отправить</button>
            <button type="reset" class="bg-gray-400 hover:bg-gray-500 text-white px-4 py-2 rounded-lg">Стереть</button>
        </div>
    </form>

    <div class="max-w-xl mx-auto p-6 flex-col text-center">
        <?php
        foreach ($model as $error)
            echo '<div class="flex-col">' . $error . '</div>';
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

    <script src="public/assets/js/history_script.js"></script>