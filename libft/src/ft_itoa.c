/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:18:53 by pcotasso          #+#    #+#             */
/*   Updated: 2014/01/10 16:06:47 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(int n)
{
	int		r;

	if (n < 0)
		return (nbrlen(n * (-1)));
	r = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		r++;
		n = n / 10;
	}
	return (r);
}

static int	power(int n)
{
	int		r;

	r = 1;
	while (--n)
		r = r * 10;
	return (r);
}

char		*ft_itoa(int n)
{
	char		*ret;
	char		*temp;
	int			size;

	if (n == -2147483648)
		return ("-2147483648");
	size = nbrlen(n);
	ret = (char *) malloc (size * sizeof(char) + 2);
	if (ret == NULL)
		return (NULL);
	temp = ret;
	if (n < 0)
	{
		*ret++ = '-';
		n = n * (-1);
	}
	size = power(size);
	while (size)
	{
		*ret++ = (n / size) + 48;
		n = n - (n / size) * size;
		size = size / 10;
	}
	*ret = 0;
	return (temp);
}
