/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:41:35 by pcotasso          #+#    #+#             */
/*   Updated: 2013/11/22 17:30:22 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	char		*temp;

	temp = s1;
	while (*s1)
		s1 = s1 + 1;
	while (*s2)
	{
		*s1++ = *s2++;
	}
	*s1 = 0;
	return (temp);
}
