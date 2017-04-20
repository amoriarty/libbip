# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alegent <alegent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/15 10:43:26 by alegent           #+#    #+#              #
#    Updated: 2017/04/20 15:14:20 by alegent          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILER CONFIGURATION
CC= clang -Wall -Wextra -Werror -g
INC= -I libft -I .
LIB= ./libft/libft.a

# BINARIE CONFIGURATION
NAME= libbip.a
SRC_PATH= srcs/
SRC_NAME= bip.c \
			bip_free.c \
			bip_reserve.c \
			bip_commit.c \
			bip_clear.c \
			bip_uncommit.c
SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ_PATH= obj/
OBJ_NAME= $(SRC_NAME:.c=.o)
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# RULES
all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) has been created."

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(INC) -o $@ -c $<

clean:
	@make -C libft clean
	@rm -rf $(OBJ)
	@rm -rf $(PATH)
	@echo "Objects files are deleted."

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "$(NAME) are deleted."
	@rm -rf $(NAME)
	@echo "$(NAME) are deleted."

re: fclean all

.PHONY: clean fclean re
