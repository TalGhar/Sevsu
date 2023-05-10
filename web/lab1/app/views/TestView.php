<form method="POST" action="Test/check" class="max-w-xs mx-auto">
    <div class="mb-4">
        <label class="block font-bold mb-2" for="ФИО">ФИО</label>
        <input class="w-full px-4 py-2 rounded-lg border border-gray-400" type="text" id="ФИО" name="ФИО"
            placeholder="Введите ФИО">
    </div>

    <div class="mb-4">
        <label class="block font-bold mb-2" for="course">Курс</label>
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
        <label class="block font-bold mb-2">Вопрос 1</label>
        <div class="flex items-center">
            <input class="mr-2" type="radio" id="answer1_1" name="answer1" value="1" checked>
            <label class="mr-4" for="answer1_1">Ответ 1</label>
            <input class="mr-2" type="radio" id="answer1_2" name="answer1" value="2">
            <label for="answer1_2">Ответ 2</label>
        </div>
    </div>

    <div class="mb-4">
        <label class="block font-bold mb-2" for="answer2">Вопрос 2</label>
        <input class="w-full px-4 py-2 rounded-lg border border-gray-400" type="text" id="answer2" name="answer2"
            placeholder="Введите ответ на вопрос 2">
    </div>

    <div class="mb-4">
        <label class="block font-bold mb-2" for="answer3">Вопрос 3</label>
        <textarea class="w-full px-4 py-2 rounded-lg border border-gray-400" id="answer3" name="answer3"
            placeholder="Введите ответ на вопрос 3"></textarea>
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
        if(isset($model['errors'])) {
            foreach($model['errors'] as $errors => $error) 
            echo '<div class="flex-col">'.$error.'</div>';
        } elseif (isset($model['result'])) {
            $result = $model['result'];
            echo "<div>У вас $result верных ответов</div>";
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

<script src="public/assets/js/history_script.js"></script>