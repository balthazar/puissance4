/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:37:41 by pcotasso          #+#    #+#             */
/*   Updated: 2013/12/13 18:26:15 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char	*tmp;
	char	*tmp2;

	tmp = s1;
	tmp2 = (char *) s2;
	while (n--)
	{
		*tmp++ = *tmp2;
		if (*tmp2 == (unsigned char) c)
			return (tmp);
		tmp2++;
	}
	return (NULL);
}
