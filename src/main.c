/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:53:05 by pcotasso          #+#    #+#             */
/*   Updated: 2014/03/08 14:51:57 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int		init(char **av, t_env *env)
{
	int			i;

	env->row = ft_atoi(av[1]);
	env->column = ft_atoi(av[2]);
	srand(time(NULL));
	env->turn = rand() % SIZE;
	env->win = RUNNING;
	if (env->row < 6 || env->column < 7)
		return (ER_SIZE);
	if (!(env->board = (char **)malloc(sizeof(char *) * env->row)))
		return (ER_MALLOC);
	i = 0;
	while (i < env->row)
	{
		if (!(env->board[i] = (char *)malloc(sizeof(char) * env->column + 1)))
			return (ER_MALLOC);
		ft_memset(env->board[i], '.', env->column);
		env->board[i][env->column] = 0;
		i++;
	}
	return (1);
}

void	display(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->row)
	{
		ft_putendl(env->board[i]);
		i++;
	}
	i = 1;
	while (i <= env->row)
	{
		ft_putnbr(i);
		i++;
	}
	ft_putstr("\n");
}

void	ft_free(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->row)
	{
		free(env->board[i]);
		i++;
	}
	free(env->board);
}


void	game(t_env *env)
{

	display(env);
	ft_free(env);
}

void	ft_error(int type)
{
	if (type == ER_MALLOC)
		ft_putendl_fd("Malloc error\n", 2);
	else if (type == ER_SIZE)
		ft_putstr_fd("Not enough rows or columns\n", 2);
	else if (type == ER_USAGE)
		ft_putstr_fd("usage: puissance-4 [rowsize] [columnsize] ...\n", 2);
}

int		main(int ac, char **av)
{
	t_env		env;
	int			ret;

	if (ac == 3)
	{
		ret = init(av, &env);
		if (ret == 1)
			game(&env);
		else
			ft_error(ret);
	}
	else
		ft_error(ER_USAGE);
	return (0);
}
