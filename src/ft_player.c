/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 20:02:54 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/08 20:36:16 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "puissance.h"

void	ft_player_play(void)
{
	char	*line;
	int		ok;
	int		number;

	ok = 0;
	while (get_next_line(0, &line) && !ok)
	{
		number = ft_atoi(line);
		if (ft_check_col(number))
			ok = 1;
		else
			ft_putendl("Please enter a valid number.");
		free(line);
	}
	free(line);
	ft_putpiece(number, HUMAN);
}
