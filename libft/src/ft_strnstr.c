/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:42:32 by pcotasso          #+#    #+#             */
/*   Updated: 2013/12/13 18:35:55 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char		*ret;
	size_t		num;
	size_t		size2;

	size2 = ft_strlen(s2);
	num = -1;
	ret = NULL;
	if (!*s2)
		return ((char *) s1);
	while (*s1)
	{
		if (*s1 == 0 || ret)
			break ;
		else if (*s1 == *s2 && (num + size2) < n)
			ret = ft_strstr(s1, s2);
		num++;
		s1++;
	}
	return (ret);
}
