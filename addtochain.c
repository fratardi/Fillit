/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtochain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 16:04:37 by fratardi          #+#    #+#             */
/*   Updated: 2019/01/02 16:57:53 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>


t_tetris	*addtochain(t_tetris *iteralink, unsigned short tetris)
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
		if(!(new = (t_tetris)ft_memalloc(sizeof(t_tetris))))			
			return(NULL);
		new.oxy[2] = (letter + 1);
		new.next = NULL;
		iteralink->next = &new;
		return(ret);
	}	
	return(NULL);	
}
