NAME = harlFilter

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

SRCS = ./srcs/main.cpp ./srcs/Harl.cpp
INCLUDE = ./include/Harl.hpp

CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD
OBJS = ${SRCS:.cpp=.o}
DEPS = ${SRCS:.cpp=.d}

%.o: %.cpp
	@echo "${BLUE} ◎ $(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -I./include -c $< -o $@

${NAME}: ${OBJS} ${INCLUDE} Makefile
		@${CC} ${CFLAGS} -I./include ${SRCS} -o ${NAME}
		@echo "\n$(GREEN) Created $(NAME) ✓ $(DEF_COLOR)\n"

all:	${NAME}

-include ${DEPS}

clean:
		@${RM} ${OBJS} ${DEPS} ${NAME}.d
		@echo "\n${BLUE} ◎ $(RED)All objects cleaned successfully ${BLUE}◎$(DEF_COLOR)\n"
fclean:
		@${RM} ${OBJS} ${DEPS} ${NAME} ${NAME}.d
		@echo "\n${BLUE} ◎ $(RED)All objects and executable cleaned successfully${BLUE} ◎$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re