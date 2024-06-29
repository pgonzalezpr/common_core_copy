FROM debian:11

RUN apt-get update && \
    apt-get install -y mariadb-server mariadb-client && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

RUN mkdir -p /var/run/mysqld && \
	chown -R mysql:mysql /var/run/mysqld && \
	chmod 777 /var/run/mysqld

EXPOSE 3306

COPY --chmod=755 tools/init_script.sh /usr/local/bin/init_script.sh
COPY --chmod=755 tools/init.sql /usr/local/bin/init.sql

RUN mysql_install_db

ENTRYPOINT [ "/usr/local/bin/init_script.sh" ]