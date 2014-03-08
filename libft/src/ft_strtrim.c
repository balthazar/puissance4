/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:17:11 by pcotasso          #+#    #+#             */
/*   Updated: 2013/11/25 18:25:51 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t			size;
	unsigned int	i;
	size_t			j;

	size = ft_strlen(s);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == size)
		return (ft_strsub(s, 0, 0));
	j = 0;
	while (s[size - j - 1] == ' ' || s[size - j - 1] == '\n'
			|| s[size - j - 1] == '\t')
		j++;
	return (ft_strsub(s, i, size - i - j));
}
