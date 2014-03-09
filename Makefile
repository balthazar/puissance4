# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/12 14:52:05 by pcotasso          #+#    #+#              #
#    Updated: 2014/03/09 11:47:45 by bgronon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC       =  clang
CFLAGS  +=  -Wextra -Wall -Werror -I./includes -I./libft/inc
LDFLAGS +=  -L libft -lft
DEBUG    =  -g3 -fno-inline -DD_ERRORS_ON

OBJDIR   =  .objs
LISTDIR  =  src
LIBDIR   =  libft
DIRSRC   =  src

NAME     =  puissance-4

SRC      =  $(DIRSRC)/main.c \
			$(DIRSRC)/ft_get_env.c \
			$(DIRSRC)/ft_ia.c \
			$(DIRSRC)/ft_player.c \
			$(DIRSRC)/ft_putpiece.c \
			$(DIRSRC)/ft_checks.c \
			$(DIRSRC)/ft_look.c \
			$(DIRSRC)/ft_look_diagonals.c \
			$(DIRSRC)/ft_display.c \
			$(DIRSRC)/ft_errors.c \
			$(DIRSRC)/ft_exit.c \

OBJ      =  $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

.SILENT:

all: libft $(NAME)

libft:
	make -C libft

$(addprefix $(OBJDIR)/, %.o): %.c
	$(CC) $(CFLAGS) -o $@ -c $<
	printf '\033[0;34mObject $@ [\033[0;32m✔\033[0;34m]\n'

$(NAME): includes $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)
	printf '\033[1;35mProgram $(NAME) compiled [\033[0;32m✔\033[1;35m]\n\n'

clean:
	make -C $(LIBDIR) $@
	/bin/rm	-fr $(OBJDIR)
	printf '\n\033[1;31m%s\n\033[0m' "Clean $(NAME)"

fclean: clean
	make -C $(LIBDIR) $@
	/bin/rm -fr $(NAME)
	printf '\033[1;31m%s\n\033[0m' "Fclean $(NAME)"

re:	fclean all

debug:	CFLAGS += $(DEBUG)
debug:	re
	printf '\033[1;31mDebug version [%s]\n' "$(DEBUG)"

$(OBJDIR):
	/bin/mkdir $(OBJDIR);			\
	for DIR in $(LISTDIR);			\
	do								\
		/bin/mkdir $(OBJDIR)/$$DIR;	\
	done							\

.PHONY:	clean fclean re debug libft
