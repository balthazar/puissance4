/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 19:40:01 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/09 18:43:39 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

void	ft_error(int type)
{
	if (type == ER_MALLOC)
		ft_putendl_fd("Malloc error\n", 2);
	else if (type == ER_SIZE)
		ft_putstr_fd("Problem with rows or columns\n", 2);
	else if (type == ER_USAGE)
		ft_putstr_fd("usage: puissance-4 [rowsize] [columnsize] ...\n", 2);
}
