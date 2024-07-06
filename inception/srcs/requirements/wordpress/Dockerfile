FROM debian:11

RUN apt-get update && apt-get install -y \
	php7.4-fpm \
	php7.4-mysqli \
	mariadb-client \
	curl && \
	rm -rf /var/lib/apt/lists/*

COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
	&& chmod +x wp-cli.phar \
	&& mv wp-cli.phar /usr/local/bin/wp

RUN mkdir -p /run/php
RUN chmod 755 /run/php

COPY ./tools/config.sh /usr/local/bin/config.sh
RUN chmod +x /usr/local/bin/config.sh

EXPOSE 9000

WORKDIR /var/www/html/

ENTRYPOINT [ "/usr/local/bin/config.sh" ]