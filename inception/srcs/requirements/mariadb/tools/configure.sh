#!/bin/bash

# Charger les variables d'environnement depuis le fichier .env
set -a
source .env
set +a

sed "s/{{DB_ROOT}}/${DB_ROOT}/g; s/{{DB_NAME}}/${DB_NAME}/g; s/{{DB_USER}}/${DB_USER}/g; s/{{DB_PASS}}/${DB_PASS}/g" /var/www/initial_db.sql > /var/www/initial_db_tmp.sql

service mysql start && mysql < /var/www/initial_db_tmp.sql && rm -f /var/www/initial_db_tmp.sql

service mysql start

exec "$@"
