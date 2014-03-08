/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 19:43:37 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/08 19:46:25 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "puissance.h"

t_env	*ft_get_env(void)
{
	static t_env	*env = NULL;

	if (!env)
	{
		if (!(env = (t_env *) malloc(sizeof(t_env))))
			ft_error(ER_MALLOC);
	}
	return (env);
}
