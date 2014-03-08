/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:02:47 by pcotasso          #+#    #+#             */
/*   Updated: 2014/01/25 18:51:24 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*ret;
	size_t		k;

	ret = ft_memalloc(len + 1);
	if (ret == NULL)
		return (NULL);
	k = 0;
	while (len - k)
	{
		ret[k] = s[start + k];
		k++;
	}
	ret[k] = 0;
	return (ret);
}
