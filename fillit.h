/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 12:01:39 by fratardi          #+#    #+#             */
/*   Updated: 2019/01/02 16:55:11 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FILLIT_H
# define FILLIT_H

#include "libft/libft.h"

typedef struct s_tetris
{
	int					oxy[3];
	unsigned short		tetri;
	struct s_tetris		*next;
} 				t_tetris;

int	ft_checkargsforfillit(const int ,const char **argv);
int ft_checkinputisvalid(const char *tab);
unsigned short buffconvert(const char *tab);

#endif
