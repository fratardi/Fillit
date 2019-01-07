/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isgridvalid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:32:13 by fratardi          #+#    #+#             */
/*   Updated: 2019/01/07 18:41:04 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
 * function that gets the content of a tetrimino line and moves the x position to get it right
*/
unsigned short	linejuster(unsigned short tetris, int linetoget, int position)
{
	if(linetoget == 0)
		return ((tetris & 61440)>>position);
	if (linetoget == 1)
		return (((tetris & 3840)<<4)>>position);
	if (linetoget == 2)
		return (((tetris & 240)<<8)>>position);
	if (linetoget == 4)
		return (((tetris & 15)<<12)>>position);
	return (0);
}
/*
**check if the line applied does not goes out of the line border  
*/
int				within_line_border(unsigned short linetocheck, int	gridsize)
{
	return (((linetocheck & 65535) << gridsize) > 0 );
}
//	check if grid is valid line by line
int				isgridvalid(t_tetris *tetris,int gridsize)
{
	unsigned short	line;

	line = 0;
	while (tetris->next != NULL)
	{
		if (within_line_border(line,gridsize) == 0)
			return (0);
		line = 0;
	}
	return (1);
}
