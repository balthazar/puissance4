/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:41:56 by pcotasso          #+#    #+#             */
/*   Updated: 2013/12/13 18:35:00 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *s1, const char *s2)
{
	const char		*ret;
	size_t			size;

	if (!*s2)
		return ((char *) s1);
	size = ft_strlen(s2);
	while (*s1)
	{
		if (*s1 == *s2)
		{
			ret = s1;
			if (!ft_strcmp(s2, ft_strsub(ret, 0, size)))
				return ((char *) s1);
		}
		s1++;
	}
	return (NULL);
}
