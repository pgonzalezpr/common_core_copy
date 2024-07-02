FROM debian:11

RUN apt-get update \
    && apt-get install -y nginx openssl \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

RUN rm -v /etc/nginx/nginx.conf

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/cert.key -out /etc/nginx/cert.crt -subj "/CN=pedro-go.42.fr"

COPY conf/nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
