/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_look_diagonals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 11:20:37 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/09 11:21:04 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

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

int			ft_look_down_right(t_env *env, int i, int j, char c)
{
	int		cpt;

	cpt = 0;
	while (cpt <= 3 && (i + cpt) < env->row && (j + cpt) < env->column)
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
	while (cpt <= 3 && (i + cpt) < env->row && (j - cpt) >= 0)
	{
		if (env->board[i + cpt][j - cpt] != c)
			return (cpt);
		++cpt;
	}
	return (cpt);
}
