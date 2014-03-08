/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 19:08:31 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/08 20:36:25 by bgronon          ###   ########.fr       */
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
				ft_putstr("\033[1;31m");
			else if (env->board[i][j] == 'x')
				ft_putstr("\033[0;32m");
			ft_putchar(env->board[i][j]);
			ft_putstr("\033[0m");
			++j;
		}
		ft_putstr("|\n");
		++i;
	}
	ft_putstr("\n");
}

void		ft_current_player(int player)
{
	if (player == IA)
		ft_putendl("Our IA gonna play.");
	else
		ft_putendl("Your turn to play.");
}

void		ft_display(t_env *env)
{
	int		i;

	i = 0;
	ft_putchar('|');
	while (i < env->column)
	{
		ft_putnbr(i);
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
