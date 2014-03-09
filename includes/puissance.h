/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 12:06:56 by pcotasso          #+#    #+#             */
/*   Updated: 2014/03/09 18:33:26 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE_H
# define PUISSANCE_H

# include "libft.h"
# include <stdlib.h>
# include <time.h>

# define ER_SIZE	-1
# define ER_MALLOC	-2
# define ER_USAGE	-3

# define IA			0
# define HUMAN		1
# define IA_WIN		2
# define HUMAN_WIN	3
# define I_WIN		99999
# define H_WIN		99998
# define COL		env->column
# define ROW		env->row
# define GET(E, T)	((t_choice *) (E)->content)->T
# define BORD(X, Y)	(env->board[X][Y])
# define LDL		ft_look_down_left
# define LDR		ft_look_down_right

typedef struct	s_choice
{
	int			col;
	int			row;
	int			priority;
	int			pos;
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
** ft_ia.c && ft_priority.c && ft_player.c && ft_putpiece.c
*/
int		ft_ia_play(t_env *env);
int		ft_player_play(void);
void	ft_putpiece(int col, int player);
int		ft_position_score(int col, int row);
int		ft_is_win_move(int col, int row, t_env *env);
int		ft_is_hwin_move(int col, int row, t_env *env);
int		ft_determine_priority(int col, int row, t_env *env);

/*
** ft_checks.c && ft_looks.c && ft_looks_diagonals.c
*/
int		ft_check_col(int col);
int		ft_check_win(t_env *env);
int		ft_look_left(int i, int j, char c, int repeat);
int		ft_look_right(int i, int j, char c, int repeat);
int		ft_look_down(int i, int j, char c, int repeat);
int		ft_look_up(int i, int j, char c, int repeat);
int		ft_look_down_right(int i, int j, char c, int repeat);
int		ft_look_down_left(int i, int j, char c, int repeat);
int		ft_look_up_right(int i, int j, char c, int repeat);
int		ft_look_up_left(int i, int j, char c, int repeat);

/*
** ft_display.c
*/
void	ft_display(t_env *env);
void	ft_display_winner(t_env *env);

/*
** ft_errors.c
*/
void	ft_error(int type);

/*
** ft_exit.c
*/
void	ft_exit(t_env *env);
void	ft_free_choices(t_list **choices);

#endif /* !PUISSANCE_H */
