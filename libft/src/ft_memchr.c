/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:39:14 by pcotasso          #+#    #+#             */
/*   Updated: 2013/11/21 16:08:20 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*tmp;

	c = (unsigned char) c;
	tmp = s;
	if (n == 0)
		return (NULL);
	while (n--)
	{
		if (*tmp == c)
			return ((void *) tmp);
		++tmp;
	}
	return (NULL);
}
