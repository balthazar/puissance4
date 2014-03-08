/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 19:08:31 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/08 19:38:10 by bgronon          ###   ########.fr       */
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
			ft_putchar(env->board[i][j]);
			++j;
		}
		ft_putstr("|\n");
		++i;
	}
	ft_putstr("\n");
}

void		ft_display(t_env *env)
{
	int		i;

	i = 0;
	ft_putchar('|');
	while (i <= env->row)
	{
		ft_putnbr(i);
		ft_putchar('|');
		++i;
	}
	i = 0;
	ft_putchar('\n');
	while (i <= env->row)
	{
		ft_putstr("--");
		++i;
	}
	ft_putstr("-\n");
	ft_display_board(env);
}
