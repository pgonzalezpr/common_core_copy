NAME = philo_bonus

SRCS = ./srcs/main_bonus.c ./srcs/utils_bonus.c ./srcs/init_bonus.c ./srcs/exit_bonus.c \
		./srcs/string_utils_bonus.c ./srcs/run_bonus.c ./srcs/run_utils_bonus.c
			
INCLUDE = ./include/philo_bonus.h

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -MMD -fsanitize=thread

DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@
	@echo "$(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"

OBJS = ${SRCS:.c=.o}
DEPS = $(addsuffix .d, $(basename $(SRCS)))

all: ${NAME}

${NAME}: ${OBJS} $(INCLUDE) Makefile
	@${CC} ${OBJS} -ltsan -o ${NAME}
	@echo "\n$(RED) Created $(NAME) ✓ $(DEF_COLOR)\n"

${OBJS}:
-include ${DEPS}

clean:
	@${RM} ${OBJS}
	@${RM} ${DEPS}
	@echo "\n$(DARK_YELLOW) Removed all objects$(DEF_COLOR)\n"

fclean: 
	@${RM} ${OBJS}
	@${RM} ${DEPS}
	@${RM} ${NAME}
	@echo "\n$(DARK_YELLOW)Removed all objects and executable$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
