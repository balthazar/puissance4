/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:40:59 by pcotasso          #+#    #+#             */
/*   Updated: 2014/01/25 18:51:32 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *s1, const char *s2)
{
	char		*temp;

	if (s2 == NULL)
		return (s1);
	if (s1 == NULL)
		return (NULL);
	temp = s1;
	if (*s2 != 0)
	{
		while (*s2)
		{
			*s1++ = *s2++;
		}
	}
	*s1 = 0;
	return (temp);
}
