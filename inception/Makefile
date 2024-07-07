all:
	@sudo hostsed add 127.0.0.1 pedro-go.42.fr && echo "successfully added pedro-go.42.fr to /etc/hosts"
	sudo docker compose -f ./srcs/docker-compose.yml up -d

build:
	sudo docker compose -f ./srcs/docker-compose.yml build

clean:
	sudo docker compose -f ./srcs/docker-compose.yml down --rmi all -v
#	uncomment the following line to remove the images too
#	sudo docker system prune -a

fclean: clean
	@sudo hostsed rm 127.0.0.1 pedro-go.42.fr && echo "successfully removed pedro-go.42.fr to /etc/hosts"
	@if [ -d "/home/pgonzalezpr/data/wordpress" ]; then \
	sudo rm -rf /home/pgonzalezpr/data/wordpress/* && \
	echo "successfully removed all contents from /home/pgonzalezpr/data/wordpress/"; \
	fi;

	@if [ -d "/home/pgonzalezpr/data/mariadb" ]; then \
	sudo rm -rf /home/pgonzalezpr/data/mariadb/* && \
	echo "successfully removed all contents from /home/pgonzalezpr/data/mariadb/"; \
	fi;

re: fclean all

ls:
	sudo docker image ls
	sudo docker ps

.PHONY: all, clean, fclean, re, ls
