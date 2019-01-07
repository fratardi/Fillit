/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtochain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 16:04:37 by fratardi          #+#    #+#             */
/*   Updated: 2019/01/07 17:32:09 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_tetris		*ft_tetrisnew(int letter, unsigned short tetris)
{
	t_tetris	*new;

	new = (t_tetris*)malloc(sizeof(t_tetris));
	new->tetri = tetris;
	new->oxy[2] = letter;
	new->next = NULL;
	return (new);
}

void			ft_tetrisaddlast(t_tetris **alst, t_tetris *new)
{
	t_tetris	*ele;

	if (!alst || !new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	ele = *alst;
	while (ele->next)
		ele = ele->next;
	ele->next = new;
}

int				ft_tetriconvert(t_tetris **alst, int letter, char *str)
{
	t_tetris			*ele;
	unsigned short		tetris;

	if (!(tetris = buffconvert(str)))
		return (0);
	if (!(ele = ft_tetrisnew(letter, tetris)))
		return (0);
	ft_tetrisaddlast(alst, ele);
	return (1);
}

void			ft_tetrisdisp(t_tetris *head)
{
	if (!head)
		return ;
	ft_putchar((char)(head->oxy[2]));
	ft_putstr("\t");
	ft_putnbr(head->tetri);
	ft_putstr("\n");
	ft_tetrisdisp(head->next);
}
