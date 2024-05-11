#!/bin/bash

# Démarrer le service MySQL
service mysql start
# Exécuter les commandes SQL en tant qu'utilisateur root
echo "CREATE DATABASE IF NOT EXISTS $DB_NAME ;" > db1.sql
echo "CREATE USER IF NOT EXISTS '$DB_USER'@'%' IDENTIFIED BY '$DB_PASSWORD' ;" >> db1.sql
echo "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER'@'%' ;" >> db1.sql
echo "FLUSH PRIVILEGES;" >> db1.sql
service --status-all
# Passer le fichier dans la db en spécifiant le mot de passe
cat db1.sql | mysql -u root
# Arrêter le service MySQL
service mysql stop
# Redémarrer MySQL
mysqld
