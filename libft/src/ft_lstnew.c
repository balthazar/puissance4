/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 11:04:12 by pcotasso          #+#    #+#             */
/*   Updated: 2013/11/27 11:11:24 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*ret;

	ret = (t_list *) malloc(sizeof(t_list));
	if (ret == NULL)
		return (NULL);
	if (content == 0)
	{
		(*ret).content = 0;
		(*ret).content_size = 0;
	}
	else
	{
		(*ret).content = malloc(sizeof(void *) * content_size);
		if (!(*ret).content)
		{
			free(ret);
			return (NULL);
		}
		ft_memcpy((*ret).content, content, content_size);
		(*ret).content_size = content_size;
	}
	(*ret).next = NULL;
	return (ret);
}
