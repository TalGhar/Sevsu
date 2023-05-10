<body class="bg-gray-200">
    <div class="flex flex-col space-y-5">
        <?php

        foreach ($model as $item) {
            ?>
            <div class="bg-white rounded-lg shadow p-4" id=<?php echo $item['id']; ?>>
                <div class="flex flex-col md:flex-row items-center md:items-start">
                    <img src="<?php echo $item['img']; ?>" class="w-auto h-64 mb-4 md:mb-0 md:mr-4">
                    <p class="text-gray-800">
                        <?php echo $item['description']; ?>
                    </p>
                </div>
            </div>
        <?php } ?>

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