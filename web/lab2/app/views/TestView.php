<body class="bg-gray-200">
    <form method="POST" action="/lab2/Test/check" class="max-w-xl mx-auto p-6 bg-slate-700 rounded-lg shadow-md m-2">
        <div class="mb-4">
            <label class="font-semibold text-slate-200 block mb-2" for="ФИО">ФИО</label>
            <input class="w-full px-4 py-2 border border-gray-400 rounded-lg focus:outline-none focus:border-blue-500"
                type="text" id="ФИО" name="ФИО">
        </div>

        <div class="mb-4">
            <label class="font-semibold text-slate-200 block mb-2" for="course">Курс</label>
            <select class="w-full px-4 py-2 rounded-lg border border-gray-400" id="course" name="course">
                <optgroup label="1 курс">
                    <option value="1">Группа 1</option>
                    <option value="2">Группа 2</option>
                    <option value="3">Группа 3</option>
                </optgroup>
                <optgroup label="2 курс">
                    <option value="4">Группа 1</option>
                    <option value="5">Группа 2</option>
                    <option value="6">Группа 3</option>
                </optgroup>
                <optgroup label="3 курс">
                    <option value="7">Группа 1</option>
                    <option value="8">Группа 2</option>
                    <option value="9">Группа 3</option>
                </optgroup>
                <optgroup label="4 курс">
                    <option value="10">Группа 1</option>
                    <option value="11">Группа 2</option>
                    <option value="12">Группа 3</option>
                </optgroup>
            </select>
        </div>

        <div class="mb-4">
            <label class="font-semibold text-slate-200 block mb-2">Вопрос 1</label>
            <div class="flex items-center">
                <input class="mr-2" type="radio" id="answer1_1" name="answer1" value="1" checked>
                <label for="answer1_1" class="font-semibold text-slate-200 mr-4">Ответ 1</label>
                <input class="mr-2" type="radio" id="answer1_2" name="answer1" value="2">
                <label for="answer1_2" class="font-semibold text-slate-200">Ответ 2</label>
            </div>
        </div>

        <div class="mb-4">
            <label class="font-semibold text-slate-200 block mb-2" for="answer2">Вопрос 2</label>
            <input class="w-full px-4 py-2 border border-gray-400 rounded-lg focus:outline-none focus:border-blue-500"
                type="text" id="answer2" name="answer2">
        </div>

        <div class="mb-4">
            <label class="font-semibold text-slate-200 block mb-2" for="answer3">Вопрос 3</label>
            <textarea
                class="w-full px-4 py-2 border border-gray-400 rounded-lg focus:outline-none focus:border-blue-500"
                id="answer3" name="answer3"></textarea>
        </div>

        <div class="flex justify-between">
            <button type="submit" class="bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded">
                Отправить
            </button>
            <button type="reset" class="bg-gray-500 hover:bg-gray-700 text-white font-bold py-2 px-4 rounded">
                Стереть
            </button>
        </div>
    </form>

    <div class="max-w-xl mx-auto p-6 flex-col text-center">
        <?php
        if (isset($model['errors'])) {
            foreach ($model['errors'] as $errors => $error)
                echo '<div class="flex-col">' . $error . '</div>';
        } elseif (isset($model['result'])) {
            $result = $model['result'];
            echo "<div>У вас $result верных ответов</div>";
        }
        ?>
    </div>

    <table class="min-w-full divide-y divide-gray-200">
        <thead class="bg-gray-50">
            <tr>
                <th scope="col" class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">
                    ФИО</th>
                <th scope="col" class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">
                    Дата</th>
                <th scope="col" class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">
                    Вопрос 1</th>
                <th scope="col" class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">
                    Вопрос 2</th>
                <th scope="col" class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">
                    Вопрос 3</th>
                <th scope="col"
                    class="px-6 py-3 text-center text-xs font-medium text-gray-500 uppercase tracking-wider">Правильные
                    ответы</th>
            </tr>
        </thead>
        <tbody class="bg-white divide-y divide-gray-200">
            <?php if (isset($model['data']))
                foreach ($model['data'] as $row) { ?>
                    <tr>
                        <td class="px-6 py-4 whitespace-nowrap">
                            <?php echo $row['fio']; ?>
                        </td>
                        <td class="px-6 py-4 whitespace-nowrap">
                            <?php echo $row['date']; ?>
                        </td>
                        <td class="px-6 py-4 whitespace-nowrap">
                            <?php echo $row['answer1']; ?>
                        </td>
                        <td class="px-6 py-4 whitespace-nowrap">
                            <?php echo $row['answer2']; ?>
                        </td>
                        <td class="px-6 py-4 whitespace-nowrap">
                            <?php echo $row['answer3']; ?>
                        </td>
                        <td class="px-6 py-4 whitespace-nowrap text-center">
                            <?php echo $row['correct_answers']; ?>
                        </td>
                    </tr>
                <?php } ?>
        </tbody>
    </table>

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