FROM php:8.2-rc-fpm

# Install system dependencies
RUN apt update && apt install -y mc vim htop git mysql-common \
    libssl-dev libzip-dev libcurl4-openssl-dev libonig-dev libxml2-dev libldap2-dev libpng-dev openssl
RUN export CFLAGS="-I/usr/src/php"

# Install PHP extensions
RUN docker-php-ext-install pdo_mysql zip curl opcache sockets gd

# Install PHP extensions
RUN docker-php-ext-install pdo_mysql

RUN apt-get install -y libssh2-1-dev libssh2-1 \
    && pecl install ssh2-1.3.1 \
    && docker-php-ext-enable ssh2

RUN apt-get purge -y nodejs
RUN apt-get purge -y npm

RUN curl -fsSL https://deb.nodesource.com/setup_18.x | bash -
RUN apt install -y nodejs

# Get latest Composer
COPY --from=composer:latest /usr/bin/composer /usr/bin/composer

COPY ./entrypoint.sh /entrypoint.sh

# Set working directory
WORKDIR /var/www

COPY ./ ./

EXPOSE 9000
EXPOSE 5173
RUN chmod +x /entrypoint.sh
#ENTRYPOINT ["debian.exe", "./entrypoint.sh"]
ENTRYPOINT ["/entrypoint.sh"]
