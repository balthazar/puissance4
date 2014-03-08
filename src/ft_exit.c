/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 19:41:09 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/08 19:42:12 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

void	ft_exit(t_env *env)
{
	ft_free_tab((void ***)&env->board);
}
