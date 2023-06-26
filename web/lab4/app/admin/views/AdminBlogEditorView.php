<style>
    .modal {
        background-color: rgba(0, 0, 0, 0.4);
        position: fixed;
        top: 0;
        left: 0;
        width: 100%;
        height: 100%;
        overflow: auto;
    }

    .modal.hidden {
        display: none
    }

    .modal .container {
        background-color: #fefefe;
        margin: 15% auto;
        padding: 20px;
        border: 1px solid #888;
        width: 80%;
    }
</style>

<body class="bg-gray-200">
    <div class="max-w-7xl mx-auto py-6 sm:px-6 lg:px-8">
        <div class="mt-5 md:mt-0 md:col-span-2">
            <form action="/lab4/admin/BlogEditor/add" method="POST" enctype="multipart/form-data">
                <div class="shadow overflow-hidden sm:rounded-md">
                    <div class="px-4 py-5 bg-white sm:p-6">
                        <div class="grid grid-cols-6 gap-6">
                            <div class="col-span-6 sm:col-span-4">
                                <label for="title" class="block text-sm font-medium text-gray-700">Тема
                                    сообщения</label>
                                <input type="text" name="title" id="title" autocomplete="off"
                                    class="mt-1 focus:ring-blue-500 focus:border-blue-500 block w-full shadow-sm sm:text-sm border-gray-300 rounded-md">
                            </div>
                            <div class="col-span-6 sm:col-span-4">
                                <label for="image" class="block text-sm font-medium text-gray-700">Изображение</label>
                                <input type="file" name="image" id="image"
                                    class="mt-1 focus:ring-blue-500 focus:border-blue-500 block w-full shadow-sm sm:text-sm border-gray-300 rounded-md">
                            </div>
                            <div class="col-span-6">
                                <label for="message" class="block text-sm font-medium text-gray-700">Текст
                                    сообщения</label>
                                <textarea name="message" id="message" rows="5"
                                    class="mt-1 focus:ring-blue-500 focus:border-blue-500 block w-full shadow-sm sm:text-sm border-gray-300 rounded-md"></textarea>
                            </div>
                        </div>
                    </div>
                    <div class="px-4 py-3 bg-gray-50 text-right sm:px-6">
                        <button type="submit"
                            class="inline-flex items-center px-4 py-2 border border-transparent rounded-md font-semibold text-white bg-blue-500 hover:bg-blue-600 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-blue-500">
                            Добавить запись
                        </button>
                    </div>
                </div>
            </form>

            <div class="max-w-xl mx-auto p-6 flex-col text-center">
                <?php
                if (isset($model['errors'])) {
                    foreach ($model['errors'] as $errors => $error)
                        echo '<div class="flex-col">' . $error . '</div>';
                }
                ?>
            </div>

        </div>
        <div class="flex flex-col mt-5">
            <h2 class="text-lg font-medium text-gray-900">Список записей</h2>
            <div class="mt-2 overflow-x-auto">

                <?php
                // Вывод данных на страницу
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
                            <img src="/lab4/public/assets/img/<?= $post['image'] ?>" alt=<?= $post['image'] ?>
                                class='mb-4 w-1/5'>
                            <p class='text-lg leading-7 mb-5'>

                                <?= $post['message'] ?>

                            </p>
                            <button class="btn edit-btn bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded"
                                type="button" data-id='<?= $post['id'] ?>' data-title='<?= $post['title'] ?>'
                                data-message='<?= $post['message'] ?>'>Редактировать</button>
                        </div>



                        <?php
                    }
                } else {
                    echo "<p>Нет сообщений для отображения.</p>";
                }


                ?>
            </div>
        </div>


    </div>

    <div class="modal hidden">
        <div class="container rounded-lg shadow-lg">
            <h4 class="text-center mb-4">Редактирование</h4>
            <form>
                <div class="form-group">
                    <input id="editTitle" type="text"
                        class="mb-3 shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:shadow-outline"
                        placeholder="Тема сообщения" autocomplete="off">
                </div>
                <div class="form-group">
                    <textarea id="editMessage"
                        class="shadow appearance-none border rounded w-full py-2 px-3 text-gray-700 leading-tight focus:outline-none focus:shadow-outline"
                        rows="4" placeholder="Введите сообщение"></textarea>
                </div>
                <button id="saveBtn" class="btn btn-primary w-100" type="button">Сохранить</button>
            </form>
            <div id="modalErrorBlock" class="mt-3"></div>
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

<script src="/lab4/public/assets/js/blogEditor.js"></script>