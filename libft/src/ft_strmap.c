/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 11:28:31 by pcotasso          #+#    #+#             */
/*   Updated: 2013/11/25 19:34:29 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char		*ret;
	size_t		i;

	i = 0;
	ret = ft_memalloc(ft_strlen(s) + 1);
	ft_strcpy(ret, s);
	while (ret[i])
	{
		ret[i] = f(ret[i]);
		i++;
	}
	return (ret);
}
