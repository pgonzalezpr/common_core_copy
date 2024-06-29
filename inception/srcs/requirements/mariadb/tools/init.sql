CREATE DATABASE IF NOT EXISTS mydatabase;
CREATE USER 'pedrogo'@'%' IDENTIFIED BY 'pedrogopss';
GRANT ALL PRIVILEGES ON mydatabase.* TO 'pedrogo'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;
SET PASSWORD FOR 'root'@'localhost' = PASSWORD('newpss');