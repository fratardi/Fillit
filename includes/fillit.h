/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 12:01:39 by fratardi          #+#    #+#             */
/*   Updated: 2019/01/08 15:50:01 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# define BUFF_SIZE 20
# define NO_OF_TETRIMINOS 19

typedef struct			s_tetris
{
	int					oxy[3];
	unsigned short		tetri;
	struct s_tetris		*next;
}						t_tetris;

/*
** TETRIS MANIPULATION FUNCTIONS
*/
t_tetris				*ft_tetrisnew(int letter, unsigned short tetris);
void					ft_tetrisaddlast(t_tetris **alst, t_tetris *new);
void					ft_tetrisdisp(t_tetris *head);
int						ft_tetriconvert(t_tetris **alst, int letter, char *str);

/*
** READING FILES
*/
int						ft_read_file(const int fd, t_tetris **head);
unsigned short			buffconvert(const char *tab);

/*
** SOLVING THE TETRIS FUNCTIONS
*/
int						ft_solve(unsigned int **grid, int size, t_tetris *head);

/*
** DISPLAY FUNCTIONS
*/
int						ft_display(t_tetris *head, const int size);

/*
** GRID OPERATION FUNCTIONS
*/
unsigned int			*ft_intarrnew(int size);
unsigned int			*ft_intarrdup(unsigned int *arr, int size);
void					ft_intarrdel(unsigned int **arr, int size);

int						ft_findsqrt(int num);

#endif
