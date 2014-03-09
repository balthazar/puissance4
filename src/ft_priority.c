/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_priority.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 12:44:59 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/09 13:03:31 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int		ft_position_score(int col)
{
	t_env	*env;
	int		res;
	int		i;
	int		row;

	env = ft_get_env();
	res = 0;
	i = 0;
	row = 0;
	res += (col == 0 || col == (env->column)) ? 1 : 0;
	res += (col == 1 || col == (env->column - 1)) ? 2 : 0;
	res += (col == 2 || col == (env->column - 2)) ? 3 : 0;
	res += (col >= 3 || col <= (env->column - 3)) ? 5 : 0;
	
	return (res);
}
