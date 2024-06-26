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
BONUS_SRCS = ./bns/ft_printf_bonus.c ./bns/conversion_bonus.c ./bns/parse_utils_bonus.c \
				./bns/build_utils_bonus.c ./bns/build_str_bonus.c ./bns/buff_utils_bonus.c
LIBFT_SRCS = ./libft/ft_atoi.c ./libft/ft_putendl_fd.c ./libft/ft_strncmp.c \
			./libft/ft_bzero.c ./libft/ft_putnbr_fd.c ./libft/ft_strnstr.c \
			./libft/ft_calloc.c ./libft/ft_putstr_fd.c ./libft/ft_strrchr.c \
			./libft/ft_isalnum.c ./libft/ft_split.c ./libft/ft_strtrim.c \
			./libft/ft_isalpha.c ./libft/ft_strchr.c ./libft/ft_substr.c \
			./libft/ft_isascii.c ./libft/ft_strdup.c ./libft/ft_tolower.c \
			./libft/ft_isdigit.c ./libft/ft_memchr.c ./libft/ft_striteri.c ./libft/ft_toupper.c \
			./libft/ft_isprint.c ./libft/ft_memcmp.c ./libft/ft_strjoin.c \
			./libft/ft_itoa.c ./libft/ft_memcpy.c ./libft/ft_strlcat.c \
			./libft/ft_memmove.c ./libft/ft_strlcpy.c ./libft/ft_memset.c \
			./libft/ft_strlen.c ./libft/ft_putchar_fd.c ./libft/ft_strmapi.c

INCLUDE = ./include/ft_printf.h ./include/libft.h ./include/utils.h ./libft/libft.h
INCLUDE_BONUS = ./include/ft_printf_bonus.h ./include/libft.h ./libft/libft.h ./include/utils_bonus.h

%.o: %.c ${INCLUDE}
			@${CC} ${CFLAGS} -c $< -o $@
			@echo "$(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
DEPS = $(addsuffix .d, $(basename $(SRCS)))
DEPS_BONUS = $(addsuffix .d, $(basename $(BONUS_SRCS)))

all:		$(NAME)	

$(NAME):	$(OBJS) $(INCLUDE) $(LIBFT_SRCS) Makefile
				@make -C $(LIBFT)
				@cp libft/libft.a .
				@mv libft.a $(NAME)
				@$(AR) $(NAME) $(OBJS)
				@echo "\n$(RED) Created $(NAME) ✓ $(DEF_COLOR)\n"

bonus:		$(BONUS_OBJS) $(INCLUDE_BONUS) $(LIBFT_SRCS) Makefile
				@make -C $(LIBFT)
				@cp libft/libft.a .
				@mv libft.a $(NAME)
				@$(AR) $(NAME) $(BONUS_OBJS)
				@echo "\n$(RED) Created $(NAME) ✓ $(DEF_COLOR)\n"


clean:
				@$(RM) $(OBJS) ${BONUS_OBJS}
				@${RM} ${DEPS} ${DEPS_BONUS}
				@make clean -C $(LIBFT)
				@echo "\n$(DARK_YELLOW) Removed all objects$(DEF_COLOR)\n"

-include ${DEPS}
-include ${DEPS_BONUS}

fclean: 	clean
				@${RM} ${OBJS} ${BONUS_OBJS}
				@${RM} ${DEPS} ${DEPS_BONUS}
				@${RM} bonus
				@${RM} ${NAME} ${NAME_BONUS}
				@make fclean -C $(LIBFT)
				@echo "\n$(DARK_YELLOW)Removed all objects and library$(DEF_COLOR)\n"

re:			fclean all

.PHONY:		all clean fclean re
