NAME = so_long

SRCS = ./srcs/main.c ./srcs/read_map.c ./srcs/check_map.c ./srcs/utils.c \
	   ./srcs/movements.c ./srcs/render.c

LIBFT_SRCS = ./libft/ft_atoi.c ./libft/ft_putendl_fd.c ./libft/ft_strncmp.c \
			./libft/ft_bzero.c ./libft/ft_putnbr_fd.c ./libft/ft_strnstr.c \
			./libft/ft_calloc.c ./libft/ft_putstr_fd.c ./libft/ft_strrchr.c \
			./libft/ft_isalnum.c  ./libft/ft_split.c ./libft/ft_strtrim.c \
			./libft/ft_isalpha.c ./libft/ft_strchr.c ./libft/ft_substr.c \
			./libft/ft_isascii.c ./libft/ft_strdup.c ./libft/ft_tolower.c \
			./libft/ft_isdigit.c ./libft/ft_memchr.c ./libft/ft_striteri.c ./libft/ft_toupper.c \
			./libft/ft_isprint.c ./libft/ft_memcmp.c ./libft/ft_strjoin.c \
			./libft/ft_itoa.c ./libft/ft_memcpy.c ./libft/ft_strlcat.c \
			./libft/ft_memmove.c ./libft/ft_strlcpy.c  ./libft/ft_memset.c \
			./libft/ft_strlen.c ./libft/ft_putchar_fd.c ./libft/ft_strmapi.c ./libft/ft_printf_bonus.c \
			./libft/buff_utils_bonus.c ./libft/build_str_bonus.c ./libft/build_utils_bonus.c \
			./libft/conversion_bonus.c ./libft/parse_utils_bonus.c ./libft/get_next_line_bonus.c \
			./libft/ft_lstadd_back.c ./libft/ft_lstadd_front.c ./libft/ft_lstclear.c ./libft/ft_lstdelone.c \
			./libft/ft_lstiter.c ./libft/ft_lstlast.c ./libft/ft_lstmap.c ./libft/ft_lstnew.c ./libft/ft_lstsize.c

				
INCLUDE = ./include/so_long.h ${LIBFT_DIR}/libft.h ${MINILIBX_DIR}/mlx.h

LIBFT_DIR = libft

MINILIBX_DIR = minilibx_macos

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
DEPS = $(addsuffix .d, $(basename $(SRCS)))

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT_DIR}/libft.a ${MINILIBX_DIR}/libmlx.a $(INCLUDE) ${LIBFT_SRCS} Makefile
	@${CC} ${OBJS} -L${LIBFT_DIR} -L${MINILIBX_DIR} -lft -lmlx -lm -framework OpenGL -framework AppKit -o ${NAME}
	@echo "\n$(RED) Created $(NAME) ✓ $(DEF_COLOR)\n"

$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR)

${MINILIBX_DIR}/libmlx.a:
	@make -C $(MINILIBX_DIR)

-include ${DEPS}

clean:
	@${RM} ${OBJS}
	@${RM} ${DEPS}
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MINILIBX_DIR)
	@echo "\n$(DARK_YELLOW) Removed all objects$(DEF_COLOR)\n"

fclean: 
	@${RM} ${OBJS}
	@${RM} ${DEPS}
	@${RM} ${NAME}
	@make fclean -C $(LIBFT_DIR)
	@echo "\n$(DARK_YELLOW)Removed all objects and executable$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re

	
