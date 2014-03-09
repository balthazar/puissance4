/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 19:56:52 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/09 11:39:07 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

void	ft_ia_play(t_env *env)
{
	t_list	*choices;

	if (env->pieces == 0)
		ft_putpiece((env->column / 2), IA);
	else
	{
		choices = NULL;
		
	}
}
