/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 11:08:36 by pcotasso          #+#    #+#             */
/*   Updated: 2013/12/13 18:31:26 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;
	void	*begin;

	if (size == 0)
		return (NULL);
	str = (char *) malloc(sizeof(str) * size + 1);
	if (str)
	{
		begin = str;
		while ((int) size--)
			*str++ = '\0';
		return (begin);
	}
	return (NULL);
}
