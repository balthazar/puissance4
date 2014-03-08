/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 20:20:49 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/08 22:30:23 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int			ft_check_col(int col)
{
	t_env	*env;

	env = ft_get_env();
	if (col >= env->column)
		return (0);
	if (env->board[0][col] == '.')
		return (1);
	return (0);
}

static int	ft_win_rows(t_env *env, int i, int j)
{
	char	last;
	int		cpt;

	while (env->board[i])
	{
		j = 0;
		cpt = 0;
		while (env->board[i][j])
		{
			if (env->board[i][j] == 'o')
				cpt = (cpt == 0 || last == 'o') ? (cpt + 1) : 0;
			else if (env->board[i][j] == 'x')
				cpt = (cpt == 0 || last == 'x') ? (cpt + 1) : 0;
			if (cpt == 4 && env->board[i][j] == 'x')
				return (IA);
			else if (cpt == 4 && env->board[i][j] == 'o')
				return (HUMAN);
			last = env->board[i][j];
			++j;
		}
		++i;
	}
	return (-1);
}

static int	ft_win_cols(t_env *env, int i, int j)
{
	char	last;
	int		cpt;

	while (j < (env->row - 1))
	{
		i = 0;
		cpt = 0;
		while (i < (env->column - 1))
		{
			if (env->board[i][j] == 'o')
				cpt = (cpt == 0 || last == 'o') ? (cpt + 1) : 0;
			else if (env->board[i][j] == 'x')
				cpt = (cpt == 0 || last == 'x') ? (cpt + 1) : 0;
			if (cpt == 4 && env->board[i][j] == 'x')
				return (IA);
			else if (cpt == 4 && env->board[i][j] == 'o')
				return (HUMAN);
			last = env->board[i][j];
			++i;
		}
		++j;
	}
	return (-1);
}

int			ft_check_win(t_env *env)
{
	int	res;

	res = 0;
	res = ft_win_rows(env, 0, 0);
	if (res == IA)
		env->win = IA_WIN;
	else if (res == HUMAN)
		env->win = HUMAN_WIN;
	res = ft_win_cols(env, 0, 0);
	if (res == IA)
		env->win = IA_WIN;
	else if (res == HUMAN)
		env->win = HUMAN_WIN;
	return (0);
}
