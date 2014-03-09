/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_priority.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 12:44:59 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/09 17:27:35 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int			ft_position_score(int col, int row)
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

static int	ft_check_next(int row, int col,
						int (*fn)(int i, int j, char c, int repeat))
{
	t_env	*env;
	int		res;
	int		count;
	char	c;

	res = -1;
	env = ft_get_env();
	c = BORD(row, col);
	if (c != '.')
	{
		res = 1;
		res *= (c == 'x') ? 900 : 1000;
		count = fn(row, col, c, 1);
		if (count >= 3 && c == 'o')
			return (99998);
		else if (count >= 3 && c == 'x')
			return (99999);
		else
			res *= count;
	}
	return (res);
}

int			ft_is_hwin_move(int col, int row, t_env *env)
{
	if (col > 0)
	{
		if (row > 0 && ft_check_next(row - 1, col - 1, ft_look_up_left) == H_WIN)
			return (1);
		if (row < (env->row - 1) && ft_check_next(row + 1, col - 1, ft_look_down_left) == H_WIN)
			return (1);
		if (ft_check_next(row, col - 1, ft_look_left) == H_WIN)
			return (1);
	}
	if (col < (env->column - 1))
	{
		if (row > 0 && ft_check_next(row - 1, col + 1, ft_look_up_right) == H_WIN)
			return (1);
		if (row < (env->row - 1) && ft_check_next(row + 1, col + 1, ft_look_down_right) == H_WIN)
			return (1);
		if (ft_check_next(row, col + 1, ft_look_right) == H_WIN)
			return (1);
	}
	if (row < (env->row - 1) && ft_check_next(row + 1, col, ft_look_down) == H_WIN)
		return (1);
	return (0);
}

int			ft_is_win_move(int col, int row, t_env *env)
{
	if (col > 0)
	{
		if (row > 0 && ft_check_next(row - 1, col - 1, ft_look_up_left) == I_WIN)
			return (1);
		if (row < (env->row - 1) && ft_check_next(row + 1, col - 1, ft_look_down_left) == I_WIN)
			return (1);
		if (ft_check_next(row, col - 1, ft_look_left) == I_WIN)
			return (1);
	}
	if (col < (env->column - 1))
	{
		if (row > 0 && ft_check_next(row - 1, col + 1, ft_look_up_right) == I_WIN)
			return (1);
		if (row < (env->row - 1) && ft_check_next(row + 1, col + 1, ft_look_down_right) == I_WIN)
			return (1);
		if (ft_check_next(row, col + 1, ft_look_right) == I_WIN)
			return (1);
	}
	if (row < (env->row - 1) && ft_check_next(row + 1, col, ft_look_down) == I_WIN)
		return (1);
	return (0);
}

int			ft_determine_priority(int col, int row, t_env *env)
{
	int		res;

	res = 0;
	if (col > 0)
	{
		if (row > 0)
			res += ft_check_next(row - 1, col - 1, ft_look_up_left);
		if (row < (env->row - 1))
			res += ft_check_next(row + 1, col - 1, ft_look_down_left);
		res += ft_check_next(row, col - 1, ft_look_left);
	}
	if (col < (env->column - 1))
	{
		if (row > 0)
			res += ft_check_next(row - 1, col + 1, ft_look_up_right);
		if (row < (env->row - 1))
			res += ft_check_next(row + 1, col + 1, ft_look_down_right);
		res += ft_check_next(row, col + 1, ft_look_right);
	}
	if (row < (env->row - 1))
		res += ft_check_next(row + 1, col, ft_look_down);
	return (res);
}
