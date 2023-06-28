#!/bin/bash

npm install
composer install
yes | php artisan migrate
php-fpm --daemonize
npm run dev
