/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 12:01:39 by fratardi          #+#    #+#             */
/*   Updated: 2019/01/02 18:16:58 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FILLIT_H
# define FILLIT_H


#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"
# define BUFF_SIZE 20

typedef struct s_tetris
{
	int					oxy[3];
	unsigned short		tetri;
	struct s_tetris		*next;
} 				t_tetris;

int	ft_checkargsforfillit(const int ,const char **argv);
int ft_checkinputisvalid(const char *tab);

t_tetris		*ft_tetrisnew(int letter, unsigned short tetris);
void			ft_tetrisaddlast(t_tetris **alst, t_tetris *new);
void			ft_tetrisdisp(t_tetris *head);
int				ft_read_file(const int fd, t_tetris **head);
unsigned short buffconvert(const char *tab);
unsigned short toplefter(unsigned short value);
int				ft_checksum(const char *str);
int				ft_read(const int fd, char **str);
int				ft_tetriconvert(t_tetris **alst, int letter, char *str);
#endif
