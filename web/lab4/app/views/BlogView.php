<body class="bg-gray-200">

    <?php

    // Вывод данных на страницу
    $i = 0;
    if (isset($model['posts']) && count($model['posts']) > 0) {
        foreach ($model['posts'] as $post) {

            ?>
            <div class='bg-white rounded-lg shadow-md p-6 mb-8 m-4'>
                <div class='text-gray-500 text-sm mb-2'>
                    <?= $post['date'] ?>
                </div>
                <h2 class='text-2xl font-bold mb-2'>
                    <?= $post['title'] ?>
                </h2>
                <img src="/lab4/public/assets/img/<?= $post['image'] ?>" alt=<?= $post['image'] ?> class='mb-4 w-1/5'>
                <div class='text-lg leading-7'>
                    <?= $post['message'] ?>
                </div>
                <div class="commentContainer">
                <?php
                    if (isset($model['comments'])) {
                        foreach ($model['comments'][$i] as $comment) {
                            ?>
                            
                                <div class=" p-4 bg-gray-200 rounded-lg shadow-md mb-4">
                                    <div class="font-semibold text-lg mb-2">
                                        <?= $comment['fullname'] ?>
                                    </div>

                                    <div class="text-lg mb-2">
                                        <?= $comment['comment'] ?>
                                    </div>

                                    <div class="text-gray-500 text-sm mb-4">
                                        <?= $comment['date'] ?>
                                    </div>
                                </div>

                            <?php
                        }
                    }
                    ?>
                </div>
                <?php
                if ($_SESSION['isUser']) {
                    ?>

                    <div class='mb-4'>
                        <label class='block text-gray-700 font-bold mb-2' for='comment'>Добавить комментарий:</label>
                        <input type='text' data-id=<?= $post['id'] ?> aria-describedby="submitComment"
                            class='form-control shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:shadow-outline'
                            id='comment' name='comment' placeholder='Введите комментарий'></textarea>
                    </div>

                    <div class='flex items-center justify-end'>
                        <button type='button' class='bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded'
                            id='submitComment'
                            onClick="createScript(<?= $post['id'] ?>, '<?= $_SESSION["userFullname"] ?>')">Отправить</button>
                    </div>

                <?php } ?>
            </div>
            <?php
            $i += 1;
        }
    } else {
        echo "<p>Нет сообщений для отображения.</p>";
    }
    ?>

    <div class="<?= $model['total_pages'] == 0 ? 'hidden' : '' ?>">
        <div class="flex justify-center items-center">
            <a href="/lab4/Blog/index/?page=<?= $model['current_page'] - 1 == 0 ? 1 : $model['current_page'] - 1 ?>"
                class="py-1 px-3 rounded-l-lg border border-gray-200 hover:bg-gray-200 focus:bg-gray-200">
                Предыдущая
            </a>

            <div class="flex items-center justify-center h-10 mx-2">

                <?php
                // Пагинация
                for ($i = 1; $i <= $model['total_pages']; $i++) {
                    if (!($i == $model['current_page'])) {
                        echo '<a href="/lab4/Blog/index/?page=' . $i . '" class="px-3 py-1 rounded-md text-gray-700 border border-gray-300 hover:bg-gray-200 hover:text-gray-800 focus:outline-none focus:ring-2 focus:ring-gray-400 focus:ring-offset-2">' . $i . '</a>';
                    } else {
                        echo '<a href="/lab4/Blog/index/?page=' . $i . '" class="px-3 py-1 rounded-md text-gray-700 border border-gray-300 hover:bg-gray-200 hover:text-gray-800 focus:outline-none focus:ring-2 focus:ring-gray-400 focus:ring-offset-2">' . $i . '</a>';
                    }
                }

                ?>
            </div>

            <a href="/lab4/Blog/index/?page=<?= $model['current_page'] + 1 > $model['total_pages'] ? $model['total_pages'] : $model['current_page'] + 1 ?>"
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

<script src="/lab4/public/assets/js/sendMessage.js"></script>