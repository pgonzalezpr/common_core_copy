FROM debian:11

RUN apt-get update \
    && apt-get install -y nginx openssl \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

COPY ./conf/default /etc/nginx/sites-enabled/default
COPY ./tools/nginx_script.sh /var/www

RUN chmod +x /var/www/nginx_script.sh

ENTRYPOINT [ "var/www/nginx_script.sh" ]

CMD ["nginx", "-g", "daemon off;"]
