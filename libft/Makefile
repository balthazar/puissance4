# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/25 08:50:08 by pcotasso          #+#    #+#              #
#    Updated: 2014/03/08 20:04:08 by bgronon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
LIBF = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
PATH_INC = includes
PATH_OBJ = obj
PATH_SRC = src

SRC = \
	  ft_power.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_itoa.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_free_tab.c \
	  get_next_line.c \

OBJ = $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $@.a $(OBJ)
	@ranlib $(LIBF)

$(PATH_OBJ)/%.o : $(addprefix $(PATH_SRC)/, %.c)
	@mkdir -p $(PATH_OBJ)
	@$(CC) $(CFLAGS) -o $@ -c $^ -I $(PATH_INC)

clean:
	@rm -rf $(OBJ) 
	@if [ -d obj ]; then rm -d obj; fi

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBF)

re: fclean all

.PHONY:
	clean fclean re all
