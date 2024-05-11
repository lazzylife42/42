#!/bin/bash


sed -i "s|listen = /run/php/php7.3-fpm.sock|listen = 9000|" "/etc/php/7.3/fpm/pool.d/www.conf"
chown -R www-data:www-data /var/www/*
chmod -R 755 /var/www/*
mkdir -p /run/php/
touch /run/php/php7.3-fpm.pid

echo "Wordpress: setting up..."
mkdir -p /var/www/html
wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp
cd /var/www/html
wp core download --allow-root
wp config create --allow-root --dbname=$DB_NAME --dbuser=$DB_USER --dbhost=$DB_HOST --dbpass=$DB_PASSWORD --force
wp core install --allow-root --url="${WP_URL}" --title="${WP_TITLE}" --admin_user="${WP_ADMIN_LOGIN}" --admin_password="${WP_ADMIN_PASSWORD}" --admin_email="${WP_ADMIN_EMAIL}"
wp user create --allow-root "${WP_USER_LOGIN}" "${WP_USER_EMAIL}" --user_pass="${WP_USER_PASSWORD}"
echo "Wordpress: set up!"

chmod +x /var/www/wordpress_start.sh
exec "$@"
