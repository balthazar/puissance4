/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 09:00:47 by pcotasso          #+#    #+#             */
/*   Updated: 2013/12/07 09:34:17 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	char		*temp;

	temp = s1;
	if (n == 0)
		return (temp);
	while (*s1)
		s1 = s1 + 1;
	while (*s2 && n--)
		*s1++ = *s2++;
	*s1 = 0;
	return (temp);
}
