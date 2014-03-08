/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:36:20 by pcotasso          #+#    #+#             */
/*   Updated: 2013/12/06 11:54:10 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*tmp;

	if (b == NULL)
		return (NULL);
	tmp = b;
	if (len != 0)
	{
		while (len--)
		{
			*tmp++ = c;
		}
	}
	return (b);
}
