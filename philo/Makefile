# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romoreno <romoreno@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 19:14:15 by romoreno          #+#    #+#              #
#    Updated: 2024/03/10 21:36:11 by romoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= philo

# Global directories
SRC			:= src
UTILS		:= utils
INIT		:= init
# Commands ( -fsanitize=thread -g)
COMPILER := gcc -Wall -Wextra -Werror
REMOVER := rm -rf

# Files
SRC_FILES 		:= src/actions.c src/check.c src/clean.c src/exit.c src/init.c src/main.c \
					src/monitor.c src/protected_functions.c src/starter.c src/utils.c \
					src/writer.c

OBJ_FILES 		:= $(SRC_FILES:.c=.o)

# Styles
PRINT		:= \033[0m
BOLD 		:= \033[1m
GREEN		:= \033[0;32m
BLUE		:= \033[0;94m

# Rules
.c.o:
		@$(COMPILER) -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJ_FILES)
		@echo "Creating $(NAME)..."
		@$(COMPILER) $(OBJ_FILES) -pthread -o $(NAME)
		@echo "$(GREEN)$(BOLD)$(NAME) created!$(PRINT)"

clean:
		@echo "Cleaning..."
		@$(REMOVER) $(OBJ_FILES)
		@echo "$(BLUE)All objects files were cleaned!$(PRINT)"

fclean: clean
		@$(REMOVER) $(NAME)
		@echo "$(BLUE)All compiled files were cleaned!$(PRINT)"

re: 	fclean all

.PHONY: all clean fclean re
