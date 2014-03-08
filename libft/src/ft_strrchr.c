/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:38:22 by pcotasso          #+#    #+#             */
/*   Updated: 2013/12/13 18:34:12 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	char		*ret;

	ret = NULL;
	if (!*s)
		return (ret);
	while (*s)
	{
		if (*s == (char) c)
		{
			ret = (char *) s;
		}
		s++;
	}
	if (c == 0)
		return ((char *) s);
	return (ret);
}
