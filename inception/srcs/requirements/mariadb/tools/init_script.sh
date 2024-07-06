#!/bin/bash

mysqld_safe &

while ! mysqladmin ping --silent; do
    sleep 1
done

mysql < /usr/local/bin/init.sql

tail -f /dev/null

