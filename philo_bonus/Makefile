# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romoreno <romoreno@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 19:14:15 by romoreno          #+#    #+#              #
#    Updated: 2024/03/05 20:32:21 by romoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= philo_bonus

# Global directories
SRC	:= src

# Commands ( -fsanitize=thread -g)
COMPILER := gcc -Wall -Wextra -Werror
REMOVER := rm -rf

# Files
SRC_FILES 		:= src/actions_bonus.c src/check_bonus.c src/clean_bonus.c src/exit_bonus.c \
					src/init_bonus.c src/main_bonus.c src/monitor_bonus.c \
					src/protected_functions_bonus.c src/starter_bonus.c src/utils_bonus.c \
					src/writer_bonus.c src/ft_itoa_bonus.c src/str_bonus.c
OBJ_FILES 		:= $(SRC_FILES:.c=.o)

# Styles
GREEN		:= \033[0;32m
BOLD 		:= \033[1m
BLUE		:= \033[0;94m
RESET_STYLE	:= \033[0m

# Rules
.c.o:
		@$(COMPILER) -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJ_FILES)
		@echo "Creating $(NAME)..."
		@$(COMPILER) $(OBJ_FILES) -pthread -o $(NAME)
		@echo "$(GREEN)$(BOLD)$(NAME) created!$(RESET_STYLE)"

clean:
		@echo "Cleaning..."
		@$(REMOVER) $(OBJ_FILES)
		@echo "$(BLUE)All objects files were cleaned!$(RESET_STYLE)"

fclean: clean
		@$(REMOVER) $(NAME) $(NAME_BONUS)
		@echo "$(BLUE)All compiled files were cleaned!$(RESET_STYLE)"

re: 	fclean all

.PHONY: all clean fclean re
