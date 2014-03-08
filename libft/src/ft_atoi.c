/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:24:13 by pcotasso          #+#    #+#             */
/*   Updated: 2014/01/10 16:06:21 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lnbr(const char *str)
{
	if (*str && '0' <= *str && *str <= '9')
		return (ft_lnbr(str + 1) + 1);
	return (0);
}

static int	conv(const char *str)
{
	if (*str && '0' <= *str && *str <= '9')
		return (ft_power(10, ft_lnbr(str) - 1) * (*str - 48) + conv(str + 1));
	return (0);
}

int			ft_atoi(const char *str)
{
	while (*str && ((*str >= 9 && 13 >= *str) || *str == ' '))
		str++;
	if (*str == '-')
		return (-conv(++str));
	else if (*str == '+')
		return (conv(++str));
	return (conv(str));
}
