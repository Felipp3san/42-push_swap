# Variables
CC		:= cc
RM		:= rm -f
CFLAGS	:= -Wall -Wextra -Werror

# Folders
INCLUDE_DIR		:= include
BUILD_DIR		:= build
LIBFT_DIR		:= libft
SRC_DIR			:= src
PUSH_SWAP_DIR	= $(SRC_DIR)/push_swap
CHECKER_DIR		= $(SRC_DIR)/checker
SHARED_DIR		= $(SRC_DIR)/shared
STACK_DIR		= $(SRC_DIR)/stack

# Names
NAME	:= push_swap
CHECKER	:= checker
LIBFT	:= libft.a
LIBFT   := $(LIBFT_DIR)/libft.a

# Includes & Links
INCLUDE	:= -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/include
LINK	:= -Llibft -lft

# Colors
DEF_COLOR	:= \033[0;39m
GRAY		:= \033[0;90m
RED			:= \033[0;91m
GREEN		:= \033[0;92m
YELLOW		:= \033[0;93m
BLUE		:= \033[0;94m
MAGENTA		:= \033[0;95m
CYAN		:= \033[0;96m
WHITE		:= \033[0;97m

# Source lists
PUSH_SWAP_SRCS	:= $(shell find $(PUSH_SWAP_DIR) -name "*.c" -type f)
CHECKER_SRCS	:= $(wildcard $(CHECKER_DIR)/*.c)
SHARED_SRCS		:= $(wildcard $(SHARED_DIR)/*.c)
STACK_SRCS		:= $(wildcard $(STACK_DIR)/*.c)

# Object lists
PUSH_SWAP_OBJS	:= $(PUSH_SWAP_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
CHECKER_OBJS	:= $(CHECKER_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
SHARED_OBJS		:= $(SHARED_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
STACK_OBJS		:= $(STACK_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Rules
all: $(NAME)

$(NAME): $(PUSH_SWAP_OBJS) $(SHARED_OBJS) $(STACK_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $^ $(LINK) -o $(NAME)
	@printf "$(GREEN)$@ compiled! $(DEF_COLOR)\n"

bonus: $(CHECKER_OBJS) $(SHARED_OBJS) $(STACK_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $^ $(LINK) -o $(CHECKER)
	@printf "$(GREEN)$@ compiled! $(DEF_COLOR)\n"

$(LIBFT):
	@printf "$(CYAN)Compiling libft... $< $(DEF_COLOR)\n"
	@make -C $(LIBFT_DIR) all

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)Compiling: $< $(DEF_COLOR)\n"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	
clean:
	@rm -rf $(BUILD_DIR)
	@make -C $(LIBFT_DIR) clean
	@printf "$(GREEN)$(NAME) object files cleaned!$(DEF_COLOR)\n"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(CHECKER)
	@make -C $(LIBFT_DIR) fclean
	@printf "$(GREEN)libft.a cleaned!$(DEF_COLOR)\n"
	@printf "$(GREEN)$(NAME) binaries cleaned!$(DEF_COLOR)\n"

re: fclean all
	@printf "$(GREEN)Cleaned and rebuilt!$(DEF_COLOR)\n"

# Phony
.PHONY: clean fclean bonus re all
