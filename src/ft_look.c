/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_look.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 22:23:19 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/08 23:02:49 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int			ft_look_left(t_env *env, int i, int j, char c)
{
	int		cpt;

	cpt = 0;
	while (cpt <= 3 && (j - cpt) >= 0)
	{
		if (env->board[i][j - cpt] != c)
			return (cpt);
		++cpt;
	}
	return (cpt);
}

int			ft_look_right(t_env *env, int i, int j, char c)
{
	int		cpt;

	cpt = 0;
	while (cpt <= 3 && (j + cpt) < env->column)
	{
		if (env->board[i][j + cpt] != c)
			return (cpt);
		++cpt;
	}
	return (cpt);
}

int			ft_look_up(t_env *env, int i, int j, char c)
{
	int		cpt;

	cpt = 0;
	while (cpt <= 3 && (i - cpt) >= 0)
	{
		if (env->board[i - cpt][j] != c)
			return (cpt);
		++cpt;
	}
	return (cpt);
}

int			ft_look_up_right(t_env *env, int i, int j, char c)
{
	int		cpt;

	cpt = 0;
	while (cpt <= 3 && (i - cpt) >= 0 && (j + cpt) < env->column)
	{
		if (env->board[i - cpt][j + cpt] != c)
			return (cpt);
		++cpt;
	}
	return (cpt);
}

int			ft_look_up_left(t_env *env, int i, int j, char c)
{
	int		cpt;

	cpt = 0;
	while (cpt <= 3 && (i - cpt) >= 0 && (j - cpt) >= 0)
	{
		if (env->board[i - cpt][j - cpt] != c)
			return (cpt);
		++cpt;
	}
	return (cpt);
}

int			ft_look_down(t_env *env, int i, int j, char c)
{
	int		cpt;

	cpt = 0;
	while (cpt <= 3 && (i + cpt) < env->column)
	{
		if (env->board[i + cpt][j] != c)
			return (cpt);
		++cpt;
	}
	return (cpt);
}

int			ft_look_down_right(t_env *env, int i, int j, char c)
{
	int		cpt;

	cpt = 0;
	while (cpt <= 3 && (i + cpt) < env->column && (j + cpt) < env->column)
	{
		if (env->board[i + cpt][j + cpt] != c)
			return (cpt);
		++cpt;
	}
	return (cpt);
}

int			ft_look_down_left(t_env *env, int i, int j, char c)
{
	int		cpt;

	cpt = 0;
	while (cpt <= 3 && (i + cpt) < env->column && (j - cpt) >= 0)
	{
		if (env->board[i + cpt][j - cpt] != c)
			return (cpt);
		++cpt;
	}
	return (cpt);
}

int			ft_look_around(t_env *env, int i, int j)
{
	if (i >= 3)
	{
		ft_look_left(env, i, j, env->board[i][j]);
		if (j >= 3)
			ft_look_up_left(env, i, j, env->board[i][j]);
		if (j <= (env->row - 3))
			ft_look_down_left(env, i, j, env->board[i][j]);
	}
	if (j >= 3)
		ft_look_up(env, i, j, env->board[i][j]);
	if (j <= (env->row - 3))
		ft_look_down(env, i, j, env->board[i][j]);
	if (i <= (env->column - 3))
	{
		ft_look_right(env, i, j, env->board[i][j]);
		if (j >= 3)
			ft_look_up_right(env, i, j, env->board[i][j]);
		if (j <= (env->row - 3))
			ft_look_down_right(env, i, j, env->board[i][j]);
	}
	return (0);
}

