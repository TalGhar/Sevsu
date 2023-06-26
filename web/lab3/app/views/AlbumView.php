<body class="bg-gray-200">
    <div class="grid grid-cols-1 sm:grid-cols-2 md:grid-cols-3 lg:grid-cols-5 gap-4 mt-2">
        <?php
        foreach ($model as $photo) {
            echo
                '<div class="group relative w-96 h-96">
            <img src="public/assets/img/' . $photo['name'] . '" class="object-fill w-full h-full">
            <div
                class="opacity-0 group-hover:opacity-80 absolute inset-0 flex items-center justify-center bg-slate-800 transition duration-300">
                <p class="text-white text-center text-2xl">' . $photo['description'] . '</p>
            </div>
        </div>';
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
</body>