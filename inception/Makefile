all:
	@sudo hostsed add 127.0.0.1 pedro-go.42.fr && echo "successfully added pedro-go.42.fr to /etc/hosts"
	sudo docker compose -f ./srcs/docker-compose.yml up -d --build

clean:
	sudo docker compose -f ./srcs/docker-compose.yml down --rmi all -v

fclean: clean
	@sudo hostsed rm 127.0.0.1 pedro-go.42.fr && echo "successfully removed pedro-go.42.fr to /etc/hosts"
	@if [ -d "/home/pedro-go/data/wordpress" ]; then \
	sudo rm -rf /home/pedro-go/data/wordpress/* && \
	echo "successfully removed all contents from /home/pgonzalezpr/data/wordpress/"; \
	fi;

	@if [ -d "/home/pedro-go/data/mariadb" ]; then \
	sudo rm -rf /home/pedro-go/data/mariadb/* && \
	echo "successfully removed all contents from /home/pgonzalezpr/data/mariadb/"; \
	fi;

re: fclean all

ls:
	sudo docker image ls
	sudo docker ps

.PHONY: all, clean, fclean, re, ls