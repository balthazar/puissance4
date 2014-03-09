/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_look_diagonals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 11:20:37 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/09 14:14:30 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int			ft_look_up_right(int i, int j, char c, int repeat)
{
	t_env	*env;
	int		cpt;
	int		revert;

	env = ft_get_env();
	cpt = 0;
	revert = 0;
	if (repeat)
		revert = ft_look_down_left(i, j, c, 0) - 1;
	revert = (revert < 0) ? 0 : revert;
	while (cpt <= 3 && (i - cpt) >= 0 && (j + cpt) < env->column)
	{
		if (env->board[i - cpt][j + cpt] != c)
			return (cpt + revert);
		++cpt;
	}
	return (cpt + revert);
}

int			ft_look_up_left(int i, int j, char c, int repeat)
{
	t_env	*env;
	int		cpt;
	int		revert;

	env = ft_get_env();
	cpt = 0;
	revert = 0;
	if (repeat)
		revert = ft_look_down_right(i, j, c, 0) - 1;
	revert = (revert < 0) ? 0 : revert;
	while (cpt <= 3 && (i - cpt) >= 0 && (j - cpt) >= 0)
	{
		if (env->board[i - cpt][j - cpt] != c)
			return (cpt + revert);
		++cpt;
	}
	return (cpt + revert);
}

int			ft_look_down_right(int i, int j, char c, int repeat)
{
	t_env	*env;
	int		cpt;
	int		revert;

	env = ft_get_env();
	cpt = 0;
	revert = 0;
	if (repeat)
		revert = ft_look_up_left(i, j, c, 0) - 1;
	revert = (revert < 0) ? 0 : revert;
	while (cpt <= 3 && (i + cpt) < env->row && (j + cpt) < env->column)
	{
		if (env->board[i + cpt][j + cpt] != c)
			return (cpt + revert);
		++cpt;
	}
	return (cpt + revert);
}

int			ft_look_down_left(int i, int j, char c, int repeat)
{
	t_env	*env;
	int		cpt;
	int		revert;

	env = ft_get_env();
	cpt = 0;
	revert = 0;
	if (repeat)
		revert = ft_look_up_right(i, j, c, 0) - 1;
	revert = (revert < 0) ? 0 : revert;
	while (cpt <= 3 && (i + cpt) < env->row && (j - cpt) >= 0)
	{
		if (env->board[i + cpt][j - cpt] != c)
			return (cpt + revert);
		++cpt;
	}
	return (cpt + revert);
}
