# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 03:17:50 by sab               #+#    #+#              #
#    Updated: 2024/05/10 15:58:26 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FROM debian:buster

# RUN apt-get update
# RUN apt-get install -y mariadb-server

# EXPOSE 3306

# COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
# COPY ./tools /var/www/

# RUN service mysql start && mysql < /var/www/initial_db.sql && rm -f /var/www/initial_db.sql;

# CMD ["mysqld"]

FROM debian:buster

RUN apt-get update -y && apt-get install -y apt-utils
RUN apt-get install -y mariadb-server

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./tools/script.sh /

RUN chown -R mysql:mysql /var/lib/mysql
RUN chmod +x /script.sh

WORKDIR /

CMD ["./script.sh"]
