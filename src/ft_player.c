/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 20:02:54 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/09 18:11:31 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "puissance.h"

static int		ft_is_entry_okay(int c)
{
	return (ft_isdigit(c) || c == '\n');
}

int				ft_player_play(void)
{
	char	line[2048];
	int		ok;
	int		number;

	ok = 0;
	while (!ok)
	{
		ft_bzero(line, 2048);
		if ((read(0, line, 2048)) == -1)
			return (0);
		if (line)
		{
			number = ft_atoi(line);
			if (line[0] != '\0' && line[0] != '\n'
				&& ft_stronly(line, ft_is_entry_okay)
				&& ft_check_col(number))
				ok = 1;
			else
				ft_putendl("\033[1;31m[ERROR]\033[0m Invalid number.");
		}
	}
	ft_putpiece(number, HUMAN);
	ft_putchar('\n');
	return (1);
}
