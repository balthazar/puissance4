/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:42:45 by pcotasso          #+#    #+#             */
/*   Updated: 2013/12/13 18:26:53 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*tdst;
	const char	*tsrc;
	size_t		len;
	size_t		i;

	tdst = dst;
	tsrc = src;
	len = size;
	while (len-- != 0 && *tdst != '\0')
		tdst++;
	i = tdst - dst;
	len = size - i;
	if (len == 0)
		return (i + ft_strlen(tsrc));
	while (*tsrc != '\0')
	{
		if (len != 1)
		{
			*tdst++ = *tsrc;
			len--;
		}
		tsrc++;
	}
	*tdst = '\0';
	return (i + (tsrc - src));
}
