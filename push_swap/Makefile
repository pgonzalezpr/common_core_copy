# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
OBJ_DIR = obj
BONUS_OBJ_DIR = obj_bonus # Define the bonus object directory

# Source files
SRC_DIR = srcs
SRC_FILES = main.c input.c run_sort.c gen_utils.c \
			stack.c stack_utils.c sort_utils.c \
			rotate_utils.c 
SRCS = $(addprefix $(SRC_DIR)/,$(SRC_FILES))

# Object files
OBJS = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

# Dependency files
DEPS = $(OBJS:.o=.d)

# Library
LIBFT = $(LIBFT_DIR)/libft.a

# Executables
NAME = push_swap
BONUS_NAME = checker

# Bonus source files and object files
BONUS_SRC_DIR = bonus
BONUS_SRC_FILES = main_bonus.c print_bonus.c
BONUS_SRCS = $(addprefix $(BONUS_SRC_DIR)/,$(BONUS_SRC_FILES))
BONUS_OBJS = $(addprefix $(BONUS_OBJ_DIR)/,$(BONUS_SRC_FILES:.c=.o))

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFT_DIR) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -c $< -o $@ 

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(BONUS_OBJS) -L$(LIBFT_DIR) -lft

# Rule for bonus source files
$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -c $< -o $@ 

$(BONUS_OBJ_DIR):
	mkdir -p $(BONUS_OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BONUS_OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

# Include dependency files
-include $(DEPS)

.PHONY: all clean fclean re bonus