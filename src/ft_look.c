/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_look.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 22:23:19 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/08 22:23:43 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int			ft_look_left(t_env *env, int i, int j)
{
	int		res;

	(void)env;
	res = 0;
	while (i < 0)
	{
		--j;
		--i;
	}
	return (res);
}
/*
static int	ft_look_around(t_env *env, int i, int j)
{
	if (i >= 3)
	{
		ft_look_left(env, i, j);
		if (j >= 3)
			ft_look_up_left(env, i, j);
		if (j <= (env->row - 3))
			ft_look_down_left(env, i, j);
	}
	if (j >= 3)
		ft_look_up(env, i, j);
	if (j <= (env->row - 3))
		ft_look_down(env, i, j);
	if (i <= (env->column - 3))
	{
		ft_look_right(env, i, j);
		if (j >= 3)
			ft_look_up_right(env, i, j);
		if (j <= (env->row - 3))
			ft_look_down_right(env, i, j);
	}
	return (0);
}
*/
