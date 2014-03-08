/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcotasso <pcotasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 12:06:56 by pcotasso          #+#    #+#             */
/*   Updated: 2014/03/08 19:14:18 by bgronon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE_H
# define PUISSANCE_H

# include "libft.h"
# include <stdlib.h>
# include <time.h>
# include <stdio.h> /* TODO REMOVE */

# define	SIZE		2
# define	RUNNING		1
# define	AI_WIN		2
# define	H_WIN		3
# define	DRAW		4

# define	ER_SIZE		-1
# define	ER_MALLOC	-2
# define	ER_USAGE	-3

typedef struct			s_env
{
	char				**board;
	int					row;
	int					column;
	int					win;
	int					turn;
}						t_env;

void	ft_display(t_env *env);

#endif /* !PUISSANCE_H */
