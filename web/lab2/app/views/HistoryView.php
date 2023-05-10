<body class="bg-gray-200">
    <div class="relative overflow-x-auto">
        <h1 class="text-2xl">История текущего сеанса</h1>
        <table id="localStorage" class="w-full text-gray-700 mt-2 text-center">
            <thead class="bg-gray-700">
                <tr>
                    <th scope="col" class="px-6 py-3 border-r border-b border-gray-600">№</th>
                    <th scope="col" class="px-6 py-3 border-r border-b border-gray-600">Страница</th>
                    <th scope="col" class="px-6 py-3 border-r border-b border-gray-600">Посещений</th>
                </tr>
            </thead>
            <tbody class="bg-gray-800">
            </tbody>
        </table>

        <h1 class="text-2xl">История за всё время</h1>
        <table id="cookie" class="w-full text-gray-700 mt-2 text-center">
            <thead class="bg-gray-700">
                <tr>
                    <th scope="col" class="px-6 py-3 border-r border-b border-gray-600">№</th>
                    <th scope="col" class="px-6 py-3 border-r border-b border-gray-600">Страница</th>
                    <th scope="col" class="px-6 py-3 border-r border-b border-gray-600">Посещений</th>
                </tr>
            </thead>
            <tbody class="bg-gray-800">
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

    <script src="public/assets/js/history_script.js"></script>
</body>