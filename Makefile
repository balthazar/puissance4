# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/12 14:52:05 by pcotasso          #+#    #+#              #
#    Updated: 2014/03/08 11:52:34 by pcotasso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = puissance-4
CC = llvm-gcc
CFLAGS = -Wall -Wextra -Werror -g
PATH_INC = includes
PATH_OBJ = obj
PATH_SRC = src

SRC = \
	  main.c \

OBJ = $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L ./libft -lft

$(PATH_OBJ)/%.o : $(addprefix $(PATH_SRC)/, %.c)
	@mkdir -p $(PATH_OBJ)
	@$(CC) $(CFLAGS) -o $@ -c $^ -I $(PATH_INC)

clean:
	@make -C ./libft clean
	@rm -f $(OBJ)
	@if [ -d obj ]; then rm -d obj; fi

fclean: clean
	@make -C ./libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY:
	clean fclean re all
