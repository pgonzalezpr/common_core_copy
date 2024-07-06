#!/bin/bash
if [ ! -f /etc/ssl/pedro-go.42.fr.crt ]; then
openssl req -newkey rsa:4096 -x509 -days 365 -nodes -out /etc/ssl/pedro-go.42.fr.crt -keyout /etc/ssl/pedro-go.42.fr.key -subj "/CN=pedro-go.42.fr";
fi
exec "$@"