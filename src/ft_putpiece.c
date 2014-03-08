/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpiece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 20:28:49 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/08 20:36:18 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

void	ft_putpiece(int col, int player)
{
	int		i;
	t_env	*env;

	i = 0;
	env = ft_get_env();
	while (i <= env->row && env->board[i][col] == '.')
		++i;
	printf("pute %d\n", i);
	if (player == HUMAN)
		env->board[i][col] = 'o';
	else
		env->board[i][col] = 'x';
}
