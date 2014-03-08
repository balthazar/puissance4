/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:53:05 by pcotasso          #+#    #+#             */
/*   Updated: 2014/03/09 00:12:28 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

static int	init(char **av, t_env *env, int i)
{
	env->row = ft_atoi(av[1]);
	env->column = ft_atoi(av[2]);
	srand(time(NULL));
	env->turn = rand() % 2;
	env->win = 0;
	if (env->row < 6 || env->column < 7)
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

static void	game(t_env *env)
{
	while (!env->win && env->pieces <= env->max_pieces)
	{
		ft_display(env);
		ft_current_player(env->turn);
		if (env->turn == IA)
			ft_ia_play(env);
		else
			ft_player_play();
		++env->pieces;
		env->turn = !env->turn;
		ft_check_win(env);
	}
	ft_display(env);
	ft_display_winner(env);
	ft_exit(env);
}

int			main(int ac, char **av)
{
	t_env		*env;
	int			ret;

	if (ac == 3)
	{
		env = ft_get_env();
		ret = init(av, env, 0);
		if (ret == 1)
			game(env);
		else
			ft_error(ret);
	}
	else
		ft_error(ER_USAGE);
	return (0);
}
