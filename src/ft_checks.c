/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 20:20:49 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/08 20:26:16 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int		ft_check_col(int col)
{
	t_env	*env;

	env = ft_get_env();
	if (col >= env->column)
		return (0);
	if (env->board[0][col] == '.')
		return (1);
	return (0);
}
