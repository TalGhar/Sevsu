<body class="bg-gray-200">

    <div class="max-w-6xl mx-auto px-4 sm:px-6 lg:px-8 py-8">
        <h1 class="text-3xl font-bold mb-8">Гостевая книга</h1>

        <form class="mb-8" action="#" method="POST">
            <div class="grid grid-cols-2 gap-4">
                <div>
                    <label class="block mb-2 font-bold" for="last_name">Фамилия</label>
                    <input class="w-full border border-gray-300 p-2 rounded-md" type="text" id="last_name"
                        name="last_name" required>
                </div>
                <div>
                    <label class="block mb-2 font-bold" for="first_name">Имя</label>
                    <input class="w-full border border-gray-300 p-2 rounded-md" type="text" id="first_name"
                        name="first_name" required>
                </div>
                <div>
                    <label class="block mb-2 font-bold" for="middle_name">Отчество</label>
                    <input class="w-full border border-gray-300 p-2 rounded-md" type="text" id="middle_name"
                        name="middle_name">
                </div>
                <div>
                    <label class="block mb-2 font-bold" for="email">E-mail</label>
                    <input class="w-full border border-gray-300 p-2 rounded-md" type="email" id="email" name="email"
                        required>
                </div>
            </div>
            <div class="mt-4">
                <label class="block mb-2 font-bold" for="message">Текст отзыва</label>
                <textarea class="w-full border border-gray-300 p-2 rounded-md" id="message" name="message"
                    required></textarea>
            </div>
            <div class="mt-8">
                <button class="bg-blue-500 text-white py-2 px-4 rounded hover:bg-blue-400 transition duration-300"
                    type="submit">Отправить</button>
            </div>
        </form>

        <!-- Таблица сообщений -->
        <table class="w-full border border-gray-300 rounded-lg">
            <thead class="bg-slate-100">
                <tr>
                    <th class="px-4 py-2 font-bold text-left">ФИО</th>
                    <th class="px-4 py-2 font-bold text-left">E-mail</th>
                    <th class="px-4 py-2 font-bold text-left">Сообщение</th>
                    <th class="px-4 py-2 font-bold text-left">Дата</th>
                </tr>
            </thead>
            <tbody>
                <?php foreach ($model as $message) {
                    ?>
                    <tr>
                        <td class="px-4 py-2">
                            <?php echo $message['fio'] ?>
                        </td>
                        <td class="px-4 py-2">
                            <?php echo $message['email'] ?>
                        </td>
                        <td class="px-4 py-2">
                            <?php echo $message['message'] ?>
                        </td>
                        <td class="px-4 py-2">
                            <?php echo $message['date'] ?>
                        </td>
                    </tr>
                <?php } ?>

            </tbody>
        </table>

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