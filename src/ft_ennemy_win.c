/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ennemy_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 22:53:49 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/09 23:06:12 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int		ft_ennemy_win(int col, int row)
{
	t_env	*env;

	row += 1;
	env = ft_get_env();
	if (row >= (env->row - 1))
		return (0);
	if (ft_check_col(col))
	{
		if (ft_is_hwin_move(col, row, env))
			return (1);
	}
	return (0);
}
