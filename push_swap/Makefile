CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
BONUS_DIR = bonus
INCLUDE_DIR = includes
BUILD_DIR = build
LIBFTPRINTF_DIR = ./libftprintf

# List of source files for the main program
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# List of source files for the bonus program
BONUS_SRCS = $(wildcard $(BONUS_DIR)/*.c)
BONUS_OBJS = $(patsubst $(BONUS_DIR)/%.c,$(BUILD_DIR)/%.o,$(BONUS_SRCS))

MAIN_TARGET = push_swap
BONUS_TARGET = checker

# Default target, builds only the main executable
all: $(MAIN_TARGET)

$(MAIN_TARGET): $(OBJS) makelibft
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTPRINTF_DIR) -lftprintf -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/%.o: $(BONUS_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

makelibft:
	@make -C $(LIBFTPRINTF_DIR)

clean:
	@rm -rf $(BUILD_DIR)
	@cd $(LIBFTPRINTF_DIR) && make clean

fclean: clean
	rm -f $(MAIN_TARGET) $(BONUS_TARGET)
	@cd $(LIBFTPRINTF_DIR) && make fclean

re: fclean all 

# Target to build the bonus program
bonus: $(BONUS_TARGET)

$(BONUS_TARGET): $(BONUS_OBJS) makelibft
	$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(LIBFTPRINTF_DIR) -lftprintf -o $@

.PHONY: all clean fclean re bonus

