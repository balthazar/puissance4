/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:43:51 by pcotasso          #+#    #+#             */
/*   Updated: 2013/12/13 18:28:50 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lsplit(const char *s, char c)
{
	int		nb;

	nb = (*s == c) ? 0 : 1;
	while (*s)
	{
		if (*s == c && *(s + 1) && *(s + 1) != c)
			nb++;
		s++;
	}
	return (nb);
}

char			**ft_strsplit(const char *s, char c)
{
	unsigned int	start;
	size_t			len;
	char			**array;
	unsigned int	i;

	array = (char **) ft_memalloc(sizeof(char **) * (ft_lsplit(s, c) + 1));
	start = (*s == (unsigned char) c) ? 1 : 0;
	len = 0;
	i = 0;
	while (s[start])
	{
		if (s[start] == (unsigned char) c && len == 0)
			start++;
		else if (s[start + len] == (unsigned char) c || s[start + len] == '\0')
		{
			array[i++] = ft_strsub(s, start, len);
			start += len;
			len = 0;
		}
		else
			len++;
	}
	array[i] = 0;
	return (array);
}
