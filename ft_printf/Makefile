NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I
LIBFT= libft
AR = ar rcs
RM = rm -f
SRC_DIR = srcs/
OBJ_DIR = obj/
INCLUDE = include

SRC_FILES = ft_printf utils \

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		=	.cache_exists

all:		$(NAME)	

$(NAME):	$(OBJ)
				@make -C $(LIBFT)
				@cp libft/libft.a .
				@mv libft.a $(NAME)
				@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
				@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
				@mkdir -p $(OBJ_DIR)

clean:
				@$(RM) -rf $(OBJ_DIR)
				@make clean -C $(LIBFT)

fclean: 	clean
				@$(RM) -f $(NAME)
				@$(RM) -f $(LIBFT)/libft.a

re:			fclean all

.PHONY:		all clean fclean re
