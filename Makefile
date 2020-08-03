# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedavis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 16:40:31 by bedavis           #+#    #+#              #
#    Updated: 2020/08/03 17:11:01 by bedavis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bedavis.filler

SRC_PATH = ./src/
LIB_PATH = ./libft/
OBJ_PATH = ./obj/
LIB_HEADER = $(LIB_PATH)includes/
INC_PATH = ./includes/

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

SRC_FILES = filler.c \
			parser.c \
			place.c \
			hmap.c \
			hmap2.c \
			initialization.c

OBJ_FILES = $(SRC_FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILES))
INC = -I $(INC_PATH) -I $(LIB_HEADER)

all: $(NAME)

$(NAME): $(OBJ)
		@make -C $(LIB_PATH)
		@echo "$(NAME): $(GREEN)Creating LIBFT...$(RESET)"
		@gcc $(FLAGS) $(OBJ)  $(INC) -L $(LIB_PATH) -lft -o $(NAME)
		@echo "$(NAME): $(GREEN)Creating Fillerbot...$(RESET)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir -p $(OBJ_PATH)
		@gcc $(FLAGS)  $(INC) -c $< -o $@
		@echo "\n$(NAME): $(GREEN)object file was created$(RESET)"

clean:
		@make -C $(LIB_PATH)/ clean
		@echo "$(NAME): $(RED) $(LIB_PATH) objects were deleted$(RESET)"
		@/bin/rm -rf $(OBJ_PATH)
		@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
		@make -C $(LIB_PATH)/ fclean
		@/bin/rm -f $(NAME)
		@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re $(NAME)
