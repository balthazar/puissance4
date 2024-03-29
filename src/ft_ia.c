/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgronon <bgronon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 19:56:52 by bgronon           #+#    #+#             */
/*   Updated: 2014/03/09 23:04:06 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "puissance.h"

static t_choice	*ft_priority_col(int col)
{
	t_choice	*out;
	t_env		*env;

	out = NULL;
	env = ft_get_env();
	if (!(out = (t_choice *) malloc(sizeof(t_choice))))
		return (NULL);
	out->col = col;
	out->row = 0;
	while (out->row < (env->row - 1) && env->board[out->row + 1][col] == '.')
		++out->row;
	out->pos = ft_position_score(col, out->row);
	if (out->pos != -1)
	{
		out->priority = 0;
		if (ft_is_win_move(col, out->row, env))
			out->priority = I_WIN;
		else if (ft_is_hwin_move(col, out->row, env))
			out->priority = H_WIN;
		else
			out->priority = ft_determine_priority(col, out->row, env);
	}
	return (out);
}

static int		ft_priorities(t_env *env, t_list **choices)
{
	t_choice	*new;
	int			i;

	i = 0;
	while (i < env->column)
	{
		new = ft_priority_col(i);
		if (!new)
			return (-1);
		ft_lstpush(choices, ft_lstnew(new, sizeof(t_choice)));
		free(new);
		++i;
	}
	return (0);
}

static void		ft_choose_best(t_list *choices)
{
	t_list	*best;

	best = NULL;
	while (choices)
	{
		if (GET(choices, priority) == I_WIN)
		{
			best = choices;
			break ;
		}
		if (!best || ((GET(choices, priority) > GET(best, priority))
					&& GET(choices, pos) > 0
					&& !ft_ennemy_win(GET(choices, col), GET(choices, row))))
			best = choices;
		choices = choices->next;
	}
	if (best)
		ft_putpiece(GET(best, col), IA);
}

int				ft_ia_play(t_env *env)
{
	t_list	*choices;

	if (env->pieces == 0)
		ft_putpiece((env->column / 2), IA);
	else
	{
		choices = NULL;
		if (ft_priorities(env, &choices) == -1)
			return (0);
		ft_choose_best(choices);
		ft_free_choices(&choices);
	}
	return (1);
}
