/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_priority.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 12:44:59 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/09 15:29:02 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int		ft_position_score(int col, int row)
{
	t_env	*env;
	int		res;

	env = ft_get_env();
	if (!ft_check_col(col))
		return (-1);
	res = 0;
	res += (col == 0 || col == (env->column)) ? 2 : 0;
	res += (col == 1 || col == (env->column - 1)) ? 5 : 0;
	res += (col == 2 || col == (env->column - 2)) ? 10 : 0;
	res += (col >= 3 || col <= (env->column - 3)) ? 20 : 0;
	res += (row == 0 || row == (env->row)) ? 2 : 0;
	res += (row == 1 || row == (env->row - 1)) ? 5 : 0;
	res += (row == 2 || row == (env->row - 2)) ? 10 : 0;
	res += (row >= 3 || row <= (env->row - 3)) ? 20 : 0;
	return (res);
}

int		ft_is_hight_target(int col, int row)
{
	t_env	*env;
	int		res;

	env = ft_get_env();
	if (col > 0)
	{
		if (row > 0)
			res = ft_look_up_left(row - 1, col - 1, env->board[row - 1][col - 1], 1);
		if (row < (env->row - 1))
			res = ft_look_down_left(row + 1, col - 1, env->board[row + 1][col - 1], 1);
		res = ft_look_left(row, col - 1, env->board[row][col - 1], 1);
	}
	if (col < (env->column - 1))
	{
		if (row > 0)
			res = ft_look_up_right(row - 1, col + 1, env->board[row - 1][col + 1], 1);
		if (row < (env->row - 1))
			res = ft_look_down_right(row + 1, col + 1, env->board[row + 1][col + 1], 1);
		res = ft_look_right(row, col + 1, env->board[row][col + 1], 1);
	}
	return (0);
}
