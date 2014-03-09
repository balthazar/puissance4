/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 19:41:09 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/09 12:38:39 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "puissance.h"

void	ft_free_choices(t_list **choices)
{
	t_list	*swap;
	t_list	*tmp;

	tmp = *choices;
	while (tmp)
	{
		swap = tmp;
		tmp = tmp->next;
		free(swap->content);
		free(swap);
	}
}

void	ft_exit(t_env *env)
{
	ft_free_tab((void ***)&env->board);
}
