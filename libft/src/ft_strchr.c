/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:43:53 by pcotasso          #+#    #+#             */
/*   Updated: 2013/12/13 17:57:17 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	c = (char) c;
	while (*s && *s != c)
		s++;
	if (*s == 0 && c != 0)
		return (NULL);
	return ((char *) s);
}
