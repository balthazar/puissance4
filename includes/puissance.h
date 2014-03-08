/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 12:06:56 by pcotasso          #+#    #+#             */
/*   Updated: 2014/03/08 20:06:26 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE_H
# define PUISSANCE_H

# include "libft.h"
# include <stdlib.h>
# include <time.h>
# include <stdio.h> /* TODO REMOVE */

# define SIZE		2
# define RUNNING	1
# define AI_WIN		2
# define H_WIN		3
# define DRAW		4

# define ER_SIZE	-1
# define ER_MALLOC	-2
# define ER_USAGE	-3

# define IA_TURN	1
# define HU_TURN	0

typedef struct			s_env
{
	char				**board;
	int					row;
	int					column;
	int					win;
	int					turn;
}						t_env;

/*
** ft_get_env.c
*/
t_env	*ft_get_env(void);

/*
** ft_ia.c && ft_player.c
*/
void	ft_ia_play(t_env *env);
void	ft_player_play(t_env *env);

/*
** ft_display.c
*/
void	ft_display(t_env *env);
void	ft_current_player(int player);

/*
** ft_errors.c
*/
void	ft_error(int type);

/*
** ft_exit.c
*/
void	ft_exit(t_env *env);

#endif /* !PUISSANCE_H */
