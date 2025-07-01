# Variables
CC		:= cc
RM		:= rm -f
CFLAGS	:= -Wall -Wextra -Werror -g

# Names
NAME	:= push_swap
LIBFT	:= libft.a

# Folders
INCLUDE_DIR := include
BUILD_DIR	:= build
LIBFT_DIR	:= libft
SRC_DIR		:= src

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

# Files
SRCS	:= $(shell find $(SRC_DIR) -name "*.c" -type f)
OBJS	:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Rules
all: $(NAME)

print:
	$(SRCS)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LINK) -o $(NAME)
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
	@make -C $(LIBFT_DIR) fclean
	@printf "$(GREEN)libft.a cleaned!$(DEF_COLOR)\n"
	@printf "$(GREEN)$(NAME) binaries cleaned!$(DEF_COLOR)\n"

re: fclean all
	@printf "$(GREEN)Cleaned and rebuilt!$(DEF_COLOR)\n"

# Phony
.PHONY: clean fclean bonus re all
