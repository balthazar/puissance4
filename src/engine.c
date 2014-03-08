/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 14:21:05 by pcotasso          #+#    #+#             */
/*   Updated: 2014/03/08 14:49:49 by pcotasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int		check_win(t_env *env)
{
	int		i;
	int		j;
	int		ret;

	i = j = ret = 0;
	while (i < env->row)
	{
		j = 0;
		while (j < env->column)
		{
			if (env->board[i][j] != '.')
				ret = win(env->board, i, j);
			if (ret != 0)
				return (ret);
			j++;
		}
		i++;
	}
	return (ret);
}

int		win(char **board, int row, int col)
{
	if (row + 3 < env->row)
	{
		if (board[row + 1][col] == board[row][col]
			&& board[row + 2][col] == board[row][col]
			&& board[row + 3][col] == board[row][col])
		return (board[row][col] == 'O' ? AI_WIN : HU_WIN);		
	}
	if (row + 3 < env->row && col + 3 <env->column)
	{
		if (board[row + 1][col + 1] == board[row][col]
			&& board[row + 2][col + 2] == board[row][col]
			&& board[row + 3][col + 3] == board[row][col])
		return (board[row][col] == 'O' ? AI_WIN : HU_WIN);		
	}
	if (col + 3 <env->column)
	{
		if (board[row][col + 1] == board[row][col]
			&& board[row][col + 2] == board[row][col]
			&& board[row][col + 3] == board[row][col])
		return (board[row][col] == 'O' ? AI_WIN : HU_WIN);		
	}
	if (row - 3 < env->row && col + 3 <env->column)
	{
		if (board[row - 1][col + 1] == board[row][col]
			&& board[row - 2][col + 2] == board[row][col]
			&& board[row - 3][col + 3] == board[row][col])
		return (board[row][col] == 'O' ? AI_WIN : HU_WIN);		
	}
	return (0);
}
