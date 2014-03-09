/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 20:20:49 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/09 18:11:01 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int			ft_check_col(int col)
{
	t_env	*env;

	env = ft_get_env();
	if (col < 0 || col >= env->column)
		return (0);
	if (env->board[0][col] == '.')
		return (1);
	return (0);
}

static int	ft_look_win(int i, int j, char c)
{
	if (ft_look_up(i, j, c, 1) >= 4
		|| ft_look_down(i, j, c, 1) >= 4
		|| ft_look_left(i, j, c, 1) >= 4
		|| ft_look_right(i, j, c, 1) >= 4
		|| ft_look_up_right(i, j, c, 1) >= 4
		|| ft_look_up_left(i, j, c, 1) >= 4
		|| ft_look_down_right(i, j, c, 1) >= 4
		|| ft_look_down_left(i, j, c, 1) >= 4)
		return (1);
	return (0);
}

int			ft_check_win(t_env *env)
{
	int		i;
	int		j;
	char	c;

	i = env->last.x;
	j = env->last.y;
	c = env->board[i][j];
	if (ft_look_win(i, j, c))
	{
		if (c == 'x')
			env->win = IA_WIN;
		else if (c == 'o')
			env->win = HUMAN_WIN;
	}
	return (0);
}
