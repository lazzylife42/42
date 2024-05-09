#!/bin/bash

# Define color variables
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'

echo -e "${GREEN}Setting up PHP-FPM...${NC}"
sed -i "s/listen = \/run\/php\/php7.3-fpm.sock/listen = 9000/" "/etc/php/7.3/fpm/pool.d/www.conf"
chown -R www-data:www-data /var/www/*
chmod -R 755 /var/www/*
mkdir -p /run/php/
touch /run/php/php7.3-fpm.pid

if [ ! -f /var/www/html/wp-config.php ]; then
    echo -e "${GREEN}Wordpress: setting up...${NC}"
    mkdir -p /var/www/html
    wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
    chmod +x wp-cli.phar
    mv wp-cli.phar /usr/local/bin/wp
    cd /var/www/html
    wp core download --allow-root
    mv /var/www/wp-config.php /var/www/html/
    echo -e "${GREEN}Wordpress: creating users...${NC}"
    wp core install --allow-root --url=${DOMAIN_NAME} --title=${DB_NAME} --admin_user=${DB_ROOT} --admin_password=${DB_PASS} --admin_email=${DB_USER}
    wp user create --allow-root ${DB_USER} ${DB_PASS} --user_pass=${DB_PASS}
    echo -e "${GREEN}Wordpress: set up!${NC}"
fi

exec "$@"
