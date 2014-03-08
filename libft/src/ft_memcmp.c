/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:39:50 by pcotasso          #+#    #+#             */
/*   Updated: 2013/11/21 16:38:03 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char		*tmp1;
	const char		*tmp2;

	tmp1 = s1;
	tmp2 = s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*tmp1 != *tmp2)
			return (*tmp1 - *tmp2);
		tmp1 = tmp1 + 1;
		tmp2 = tmp2 + 1;
	}
	return (0);
}
