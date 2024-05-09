# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 03:17:50 by sab               #+#    #+#              #
#    Updated: 2024/05/09 16:24:28 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y mariadb-server \
    && rm -rf /var/lib/apt/lists/*

EXPOSE 3306

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/

COPY ./tools /var/www/

COPY configure_mysql.sh /var/www/

CMD ["/var/www/configure_mysql.sh"]
