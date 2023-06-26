<body class="bg-gray-200">

    <div class="flex justify-center items-center m-5">
        <table class="table-auto rounded-lg shadow-md bg-white">
            <thead>
                <tr>
                    <th class="px-4 py-2">Страница</th>
                    <th class="px-4 py-2">IP</th>
                    <th class="px-4 py-2">Хост</th>
                    <th class="px-4 py-2">Браузер</th>
                    <th class="px-4 py-2">Дата</th>
                </tr>
            </thead>
            <tbody>

                <?php

                if (isset($model['stats']) && count($model['stats']) > 0) {
                    foreach ($model['stats'] as $stats_item) {
                        echo '
                            <tr>
                                <td class="border px-4 py-2">' . $stats_item['page'] . '</td>
                                <td class="border px-4 py-2">' . $stats_item['ip'] . '</td>
                                <td class="border px-4 py-2">' . $stats_item['host'] . '</td>
                                <td class="border px-4 py-2">' . $stats_item['browser'] . '</td>
                                <td class="border px-4 py-2">' . $stats_item['date'] . '</td>
                            </tr>
                        ';
                    }
                } else {
                    echo "<tr><td class='border px-4 py-2' colspan='5'>Данные о статистике отсутствуют</td></tr>";
                }

                ?>

            </tbody>
        </table>
    </div>  
    <div class="<?= $model['total_pages'] == 0 ? 'hidden' : '' ?>">
        <div class="flex justify-center items-center">
            <a href="/lab3/admin/Stats/index/?page=<?= $model['current_page'] - 1 == 0 ? 1 : $model['current_page'] - 1 ?>"
                class="py-1 px-3 rounded-l-lg border border-gray-200 hover:bg-gray-200 focus:bg-gray-200">
                Предыдущая
            </a>

            <div class="flex items-center justify-center h-10 mx-2">

                <?php
                // Пагинация
                for ($i = 1; $i <= $model['total_pages']; $i++) {
                    if (!($i == $model['current_page'])) {
                        echo '<a href="/lab3/admin/Stats/index/?page=' . $i . '" class="px-3 py-1 rounded-md text-gray-700 border border-gray-300 hover:bg-gray-200 hover:text-gray-800 focus:outline-none focus:ring-2 focus:ring-gray-400 focus:ring-offset-2">' . $i . '</a>';
                    } else {
                        echo '<a href="/lab3/admin/Stats/index/?page=' . $i . '" class="px-3 py-1 rounded-md text-gray-700 border border-gray-300 hover:bg-gray-200 hover:text-gray-800 focus:outline-none focus:ring-2 focus:ring-gray-400 focus:ring-offset-2">' . $i . '</a>';
                    }
                }

                ?>
            </div>

            <a href="/lab3/admin/Stats/index/?page=<?= $model['current_page'] + 1 > $model['total_pages'] ? $model['total_pages'] : $model['current_page'] + 1 ?>"
                class="py-1 px-3 rounded-r-lg border border-gray-200 hover:bg-gray-200 focus:bg-gray-200">
                Следующая
            </a>
        </div>
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