NAME = push_swap
NAME_BONUS = checker

SRCS = ./srcs/main.c ./srcs/input.c ./srcs/run_sort.c ./srcs/gen_utils.c \
    	./srcs/stack.c ./srcs/stack_utils.c ./srcs/sort_utils.c \
        ./srcs/rotate_utils.c

BONUS_SRC = ./bns/bonus_main.c ./bns/bonus_input.c ./bns/bonus_stack.c \
			./bns/bonus_utils.c ./bns/run_utils.c ./bns/bonus_stack_utils.c

INCLUDE = ./include/libft.h ./include/utils.h

INCLUDE_BONUS = ./include/libft.h ./include/bonus_utils.h 

LIBFT_DIR = libft

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -MMD

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRC:.c=.o}
DEPS = $(addsuffix .d, $(basename $(SRCS)))
DEPS_BONUS = $(addsuffix .d, $(basename $(BONUS_SRC)))

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT_DIR}/libft.a $(INCLUDE)
	@${CC} ${OBJS} -L${LIBFT_DIR} -lft -o ${NAME}

bonus: ${BONUS_OBJS} ${LIBFT_DIR}/libft.a ${INCLUDE_BONUS}
	@touch $@
	@${CC} ${BONUS_OBJS} -L${LIBFT_DIR} -lft -o ${NAME_BONUS}

$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR)

-include ${DEPS}
-include ${DEPS_BONUS}

clean:
	@${RM} ${OBJS} ${BONUS_OBJS}
	@${RM} ${DEPS} ${DEPS_BONUS}
	@make clean -C $(LIBFT_DIR)

fclean: 
	@${RM} ${OBJS} ${BONUS_OBJS}
	@${RM} ${DEPS} ${DEPS_BONUS}
	@${RM} bonus
	@${RM} ${NAME} ${NAME_BONUS}
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

	