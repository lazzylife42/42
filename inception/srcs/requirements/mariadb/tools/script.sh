#!/bin/bash

# Charger les variables d'environnement
# export $(cat .env | xargs)

service mysql start
# Démarrer le service MySQL

# # Attendre que MySQL soit prêt
# until mysqladmin ping &>/dev/null; do
#     echo "Waiting for MySQL to start..."
#     sleep 1
# done
echo $DB_NAME $DB_USER $DB_PASSWORD
# Exécuter les commandes SQL
echo "CREATE DATABASE IF NOT EXISTS $DB_NAME ;" > db1.sql
echo "CREATE USER IF NOT EXISTS '$DB_USER'@'%' IDENTIFIED BY '$DB_PASSWORD' ;" >> db1.sql
echo "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER'@'%' ;" >> db1.sql
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '12345' ;" >> db1.sql
echo "FLUSH PRIVILEGES;" >> db1.sql
service --status-all

cat db1.sql | mysql -u root -p 

echo ici3
service mysql stop
echo ici4
mysqld 
echo ici5
# tail -f /dev/null

# Arrêter MySQL proprement
# mysqladmin shutdown

# # Attendre que MySQL s'arrête
# while pgrep mysqld >/dev/null; do
#     echo "Waiting for MySQL to stop..."
#     sleep 1
# done
