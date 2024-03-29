/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:53:05 by pcotasso          #+#    #+#             */
/*   Updated: 2014/03/09 18:53:29 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "puissance.h"

static int	init(char **av, t_env *env, int i)
{
	env->row = ft_atoi(av[1]);
	env->column = ft_atoi(av[2]);
	srand(time(NULL));
	env->turn = rand() % 2;
	env->win = 0;
	if (env->row < 6 || env->column < 7 || env->row > 100 || env->column > 100)
		return (ER_SIZE);
	if (!(env->board = (char **)malloc(sizeof(char *) * (ROW + 1))))
		return (ER_MALLOC);
	env->max_pieces = env->row * env->column;
	env->pieces = 0;
	env->last.x = 0;
	env->last.y = 0;
	env->board[env->row + 1] = NULL;
	while (i < env->row)
	{
		if (!(env->board[i] = (char *)malloc(sizeof(char) * (COL + 1))))
			return (ER_MALLOC);
		ft_memset(env->board[i], '.', env->column);
		env->board[i][env->column] = '\0';
		++i;
	}
	return (1);
}

static int	game(t_env *env)
{
	while (!env->win && env->pieces < env->max_pieces)
	{
		ft_display(env);
		if (env->turn == IA)
		{
			if (!ft_ia_play(env))
				return (0);
		}
		else
		{
			if (!ft_player_play())
				return (0);
		}
		++env->pieces;
		env->turn = !env->turn;
		ft_check_win(env);
	}
	ft_display(env);
	ft_display_winner(env);
	ft_exit(env);
	return (1);
}

int			main(int ac, char **av)
{
	t_env		*env;
	int			ret;

	if (ac == 3)
	{
		ret = -1;
		env = ft_get_env();
		if (env)
			ret = init(av, env, 0);
		if (ret == 1 && env)
		{
			if (!game(env))
			{
				ft_putendl("\033[1;31m[FATAL ERROR]\033[0m");
				ft_exit(env);
			}
		}
		else
			ft_error(ret);
	}
	else
		ft_error(ER_USAGE);
	return (0);
}
