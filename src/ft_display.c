/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 19:08:31 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/09 22:51:41 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

static void	ft_display_board(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->row)
	{
		j = 0;
		while (j < env->column)
		{
			ft_putchar('|');
			if (env->board[i][j] == 'o')
				ft_putstr("\033[1;31m◎");
			else if (env->board[i][j] == 'x')
				ft_putstr("\033[0;32m◎");
			else
				ft_putstr("◯");
			ft_putstr("\033[0m");
			++j;
		}
		ft_putstr("|\n");
		++i;
	}
	ft_putstr("\n");
}

static void	ft_better_show(t_env *env)
{
	int		i;

	i = 0;
	ft_putchar('|');
	while (i < env->column)
	{
		if (i >= 10)
			ft_putnbr(i / 10);
		else
			ft_putchar(' ');
		ft_putchar('|');
		++i;
	}
	ft_putstr("\n|");
}

void		ft_display(t_env *env)
{
	int		i;

	i = 0;
	ft_better_show(env);
	while (i < env->column)
	{
		ft_putnbr(i % 10);
		ft_putchar('|');
		++i;
	}
	i = 0;
	ft_putchar('\n');
	while (i < env->column)
	{
		ft_putstr("--");
		++i;
	}
	ft_putstr("-\n");
	ft_display_board(env);
}

void		ft_display_winner(t_env *env)
{
	if (env->win == IA_WIN)
		ft_putendl("\033[0;34mOur IA beat you.\033[0m");
	else if (env->win == HUMAN_WIN)
		ft_putendl("\033[0;34mYou won, cheater.\033[0m");
	else
		ft_putendl("\033[0;34mTie game.\033[0m");
	ft_putchar('\n');
}
