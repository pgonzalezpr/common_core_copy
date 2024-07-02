#! /bin/bash

if [ ! -d /var/lib/mysql/${MYSQL_DATABASE} ];
then
mysql -u ${MYSQL_ROOT_USER} -p${MYSQL_ROOT_PASSWORD} < /usr/local/bin/init.sql
fi

mysqladmin -u ${MYSQL_ROOT_USER} -p${MYSQL_ROOT_PASSWORD} shutdown

mysqld
