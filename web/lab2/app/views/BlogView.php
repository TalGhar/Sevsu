<body class="bg-gray-200">

    <?php

    // Вывод данных на страницу
    if (isset($model['posts']) && count($model['posts']) > 0) {
        foreach ($model['posts'] as $post) {
            echo "<div class='bg-white rounded-lg shadow-md p-6 mb-8 m-4'>";
            echo "<div class='text-gray-500 text-sm mb-2'>" . $post['date'] . "</div>";
            echo "<h2 class='text-2xl font-bold mb-2'>" . $post['title'] . "</h2>";
            echo "<img src='/lab2/public/assets/img/" . $post['image'] . "' alt='" . $post['title'] . "' class='mb-4 w-1/5'>";
            echo "<div class='text-lg leading-7'>" . $post['message'] . "</div>";
            echo "</div>";
        }
    } else {
        echo "<p>Нет сообщений для отображения.</p>";
    }

    ?>

    <div class="<?= $model['total_pages'] == 0 ? 'hidden' : '' ?>">
        <div class="flex justify-center items-center">
            <a href="/lab2/Blog/index/?page=<?= $model['current_page'] - 1 == 0 ? 1 : $model['current_page'] - 1 ?>"
                class="py-1 px-3 rounded-l-lg border border-gray-200 hover:bg-gray-200 focus:bg-gray-200">
                Предыдущая
            </a>

            <div class="flex items-center justify-center h-10 mx-2">

                <?php
                // Пагинация
                for ($i = 1; $i <= $model['total_pages']; $i++) {
                    if (!($i == $model['current_page'])) {
                        echo '<a href="/lab2/Blog/index/?page=' . $i . '" class="px-3 py-1 rounded-md text-gray-700 border border-gray-300 hover:bg-gray-200 hover:text-gray-800 focus:outline-none focus:ring-2 focus:ring-gray-400 focus:ring-offset-2">' . $i . '</a>';
                    } else {
                        echo '<a href="/lab2/Blog/index/?page=' . $i . '" class="px-3 py-1 rounded-md text-gray-700 border border-gray-300 hover:bg-gray-200 hover:text-gray-800 focus:outline-none focus:ring-2 focus:ring-gray-400 focus:ring-offset-2">' . $i . '</a>';
                    }
                }

                ?>
            </div>

            <a href="/lab2/Blog/index/?page=<?= $model['current_page'] + 1 > $model['total_pages'] ? $model['total_pages'] : $model['current_page'] + 1 ?>"
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