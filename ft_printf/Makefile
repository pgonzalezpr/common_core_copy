NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
LIBFT= libft
AR = ar rcs
RM = rm -f

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

SRCS = ./srcs/ft_printf.c ./srcs/utils.c
INCLUDE = ./include/ft_printf.h ./include/libft.h ./include/utils.h

%.o: %.c ${INCLUDE}
			@${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.c=.o}

all:		$(NAME)	

$(NAME):	$(OBJS)
				@make -C $(LIBFT)
				@cp libft/libft.a .
				@mv libft.a $(NAME)
				@$(AR) $(NAME) $(OBJS)
				@echo "\n$(RED) Created $(NAME) ✓ $(DEF_COLOR)\n"

clean:
				@$(RM) $(OBJS)
				@make clean -C $(LIBFT)
				@echo "\n$(DARK_YELLOW) Removed all objects$(DEF_COLOR)\n"

fclean: 	clean
				@$(RM) $(NAME)
				@make fclean -C $(LIBFT)
				@echo "\n$(DARK_YELLOW)Removed all objects and executable$(DEF_COLOR)\n"

re:			fclean all

.PHONY:		all clean fclean re
