/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_look.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 22:23:19 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/09 13:45:10 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int			ft_look_left(int i, int j, char c, int repeat)
{
	t_env	*env;
	int		cpt;

	env = ft_get_env();
	cpt = 0;
	if (repeat)
		cpt = ft_look_right(i, j, c, 0);
	while (cpt <= 3 && (j - cpt) >= 0)
	{
		if (env->board[i][j - cpt] != c)
			return (cpt);
		++cpt;
	}
	return (cpt);
}

int			ft_look_right(int i, int j, char c, int repeat)
{
	t_env	*env;
	int		cpt;

	env = ft_get_env();
	cpt = 0;
	if (repeat)
		cpt = ft_look_left(i, j, c, 0);
	while (cpt <= 3 && (j + cpt) < env->column)
	{
		if (env->board[i][j + cpt] != c)
			return (cpt);
		++cpt;
	}
	return (cpt);
}

int			ft_look_up(int i, int j, char c, int repeat)
{
	t_env	*env;
	int		cpt;

	env = ft_get_env();
	cpt = 0;
	if (repeat)
		cpt = ft_look_down(i, j, c, 0);
	while (cpt <= 3 && (i - cpt) >= 0)
	{
		if (env->board[i - cpt][j] != c)
			return (cpt);
		++cpt;
	}
	return (cpt);
}

int			ft_look_down(int i, int j, char c, int repeat)
{
	t_env	*env;
	int		cpt;

	env = ft_get_env();
	cpt = 0;
	if (repeat)
		cpt = ft_look_up(i, j, c, 0);
	while (cpt <= 3 && (i + cpt) < env->row)
	{
		if (env->board[i + cpt][j] != c)
			return (cpt);
		++cpt;
	}
	return (cpt);
}

int			ft_look_around(t_env *env, int i, int j)
{
	if (i >= 3)
	{
		ft_look_left(i, j, env->board[i][j], 1);
		if (j >= 3)
			ft_look_up_left(i, j, env->board[i][j], 1);
		if (j <= (env->row - 3))
			ft_look_down_left(i, j, env->board[i][j], 1);
	}
	if (j >= 3)
		ft_look_up(i, j, env->board[i][j], 1);
	if (j <= (env->row - 3))
		ft_look_down(i, j, env->board[i][j], 1);
	if (i <= (env->column - 3))
	{
		ft_look_right(i, j, env->board[i][j], 1);
		if (j >= 3)
			ft_look_up_right(i, j, env->board[i][j], 1);
		if (j <= (env->row - 3))
			ft_look_down_right(i, j, env->board[i][j], 1);
	}
	return (0);
}
