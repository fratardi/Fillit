/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtochain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 16:04:37 by fratardi          #+#    #+#             */
/*   Updated: 2019/01/02 18:14:52 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

t_tetris	*ft_tetrisnew(int letter, unsigned short tetris)
{
	t_tetris	*new;

	new = (t_tetris*)malloc(sizeof(t_tetris));
	new->tetri = tetris;
	new->oxy[2] = letter;
	new->next = NULL;
	return (new);
}

void	ft_tetrisaddlast(t_tetris **alst, t_tetris *new)
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

int		ft_tetriconvert(t_tetris **alst, int letter, char *str)
{
	t_tetris	*ele;
	unsigned short	tetris;

	if (!(tetris = buffconvert(str)))
		return (0);
	if(!(ele = ft_tetrisnew(letter, tetris)))
		return (0);
	ft_tetrisaddlast(alst, ele);
	return (1);
}

void	ft_tetrisdisp(t_tetris *head)
{
	if (!head)
		return ;
	ft_putchar((char)(head->oxy[2]));
	ft_putstr("\t");
	ft_putnbr(head->tetri);
	ft_putstr("\n");
	ft_tetrisdisp(head->next);
}

/*t_tetris	*addtochain(t_tetris *iteralink, unsigned short tetris)
{
	t_tetris	*ret;
	t_tetris	new;
	int 	letter;

	ret = iteralink;
	letter  = (int)'a';
	if(!iteralink)
	{
		if(!(ret = (t_tetris*)ft_memalloc(sizeof(t_tetris))))
			return(NULL);
		ret->tetri = tetris;
		ret->oxy[2] = letter;
		ret->next = NULL;
		return(ret);
	}
	while(iteralink->next != NULL && iteralink->oxy[2] < (int)'z')
	{
		letter = iteralink->oxy[2];
		iteralink = iteralink->next ;
	}
	if(iteralink->next == NULL && iteralink->oxy[2]  < (int)'z')
	{
		new.oxy[2] = (letter + 1);
		new.next = NULL;
		iteralink->next = &new;
		return(ret);
	}
	return(NULL);
}*/
