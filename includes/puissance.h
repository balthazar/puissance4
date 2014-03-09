/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 12:06:56 by pcotasso          #+#    #+#             */
/*   Updated: 2014/03/09 11:21:29 by bgronon          ###   ########.fr       */
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
# define IA_WIN		2
# define HUMAN_WIN	3
# define DRAW		4

# define ER_SIZE	-1
# define ER_MALLOC	-2
# define ER_USAGE	-3

# define IA			0
# define HUMAN		1
# define COL		env->column
# define ROW		env->row

typedef struct	s_choice
{
	int			col;
	int			priority;
}				t_choice;

typedef struct	s_xy
{
	int			x;
	int			y;
}				t_xy;

typedef struct	s_env
{
	char		**board;
	int			row;
	int			column;
	int			win;
	int			pieces;
	int			max_pieces;
	int			turn;
	t_xy		last;
}				t_env;

/*
** ft_get_env.c
*/
t_env	*ft_get_env(void);

/*
** ft_ia.c && ft_player.c && ft_putpiece.c
*/
void	ft_ia_play(t_env *env);
void	ft_player_play(void);
void	ft_putpiece(int col, int player);

/*
** ft_checks.c && ft_looks.c && ft_looks_diagonals.c
*/
int		ft_check_col(int col);
int		ft_check_win(t_env *env);
int		ft_look_left(t_env *env, int i, int j, char c);
int		ft_look_right(t_env *env, int i, int j, char c);
int		ft_look_down(t_env *env, int i, int j, char c);
int		ft_look_up(t_env *env, int i, int j, char c);
int		ft_look_down_right(t_env *env, int i, int j, char c);
int		ft_look_down_left(t_env *env, int i, int j, char c);
int		ft_look_up_right(t_env *env, int i, int j, char c);
int		ft_look_up_left(t_env *env, int i, int j, char c);

/*
** ft_display.c
*/
void	ft_display(t_env *env);
void	ft_current_player(int player);
void	ft_display_winner(t_env *env);

/*
** ft_errors.c
*/
void	ft_error(int type);

/*
** ft_exit.c
*/
void	ft_exit(t_env *env);

#endif /* !PUISSANCE_H */
