NAME = push_swap
NAME_BONUS = checker

SRCS = ./srcs/main.c ./srcs/input.c ./srcs/run_sort.c ./srcs/gen_utils.c \
    	./srcs/stack.c ./srcs/stack_utils.c ./srcs/sort_utils.c \
        ./srcs/rotate_utils.c

BONUS_SRC = ./bns/main_bonus.c ./bns/input_bonus.c ./bns/stack_bonus.c \
			./bns/utils_bonus.c ./bns/run_utils_bonus.c ./bns/stack_utils_bonus.c

INCLUDE = ./include/libft.h ./include/utils.h

INCLUDE_BONUS = ./include/libft.h ./include/utils_bonus.h 

LIBFT_DIR = libft

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -MMD

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
BONUS_OBJS = ${BONUS_SRC:.c=.o}
DEPS = $(addsuffix .d, $(basename $(SRCS)))
DEPS_BONUS = $(addsuffix .d, $(basename $(BONUS_SRC)))

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT_DIR}/libft.a $(INCLUDE) Makefile
	@${CC} ${OBJS} -L${LIBFT_DIR} -lft -o ${NAME}
	@echo "\n$(RED) Created $(NAME) ✓ $(DEF_COLOR)\n"

bonus: ${BONUS_OBJS} ${LIBFT_DIR}/libft.a ${INCLUDE_BONUS} Makefile
	@touch $@
	@${CC} ${BONUS_OBJS} -L${LIBFT_DIR} -lft -o ${NAME_BONUS}
	@echo "\n$(RED) Created $(NAME_BONUS) ✓ $(DEF_COLOR)\n"

$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR)

-include ${DEPS}
-include ${DEPS_BONUS}

clean:
	@${RM} ${OBJS} ${BONUS_OBJS}
	@${RM} ${DEPS} ${DEPS_BONUS}
	@make clean -C $(LIBFT_DIR)
	@echo "\n$(DARK_YELLOW) Removed all objects$(DEF_COLOR)\n"

fclean: 
	@${RM} ${OBJS} ${BONUS_OBJS}
	@${RM} ${DEPS} ${DEPS_BONUS}
	@${RM} bonus
	@${RM} ${NAME} ${NAME_BONUS}
	@make fclean -C $(LIBFT_DIR)
	@echo "\n$(DARK_YELLOW)Removed all objects and executable$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re

	