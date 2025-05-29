# Variables
CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -g
NAME		= push_swap
INCLUDE		= -Iinclude -Ilibft/include
LINK		= -Llibft -lft
LIBFT		= libft/libft.a

# Folders
SRC_DIR		= src
BUILD_DIR	= build

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Files
SRCS		= $(wildcard $(SRC_DIR)/*.c)
OBJS		= $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o, $(SRCS))

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LINK) -o $@
	@echo -e "$(GREEN)$@ compiled! $(DEF_COLOR)"

$(LIBFT):
	@echo -e "$(CYAN)Compiling libft... $< $(DEF_COLOR)"
	@make -C libft all

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	@echo -e "$(YELLOW)Compiling: $< $(DEF_COLOR)" 
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(BUILD_DIR):
	@echo -e "$(MAGENTA)Build dir not found. Creating...$(DEF_COLOR)" 
	@mkdir -p $(BUILD_DIR)
	
clean:
	@rm -rf $(BUILD_DIR)
	@make -C libft clean
	@echo -e "$(GREEN)$(NAME) object files cleaned!$(DEF_COLOR)" 

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@echo -e "$(GREEN)libft.a cleaned!$(DEF_COLOR)" 
	@echo -e "$(GREEN)$(NAME) binaries cleaned!$(DEF_COLOR)" 

re: fclean all
	@echo -e "$(GREEN)Cleaned and rebuilt!$(DEF_COLOR)" 

# Phony
.PHONY: clean fclean bonus re all
