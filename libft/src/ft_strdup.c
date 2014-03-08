/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:40:25 by pcotasso          #+#    #+#             */
/*   Updated: 2014/01/26 11:51:36 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char		*temp;
	size_t		size;

	size = ft_strlen(s1) + 1;
	temp = (char *) malloc(size);
	if (temp == NULL)
		return (NULL);
	ft_strcpy(temp, s1);
	return (temp);
}
