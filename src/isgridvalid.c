/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isgridvalid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:32:13 by fratardi          #+#    #+#             */
/*   Updated: 2019/01/06 17:59:05 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



//function that gets the content of a tetrimino line and moves the x position to get it right
unsigned short 	tetrilinejuster(unsigned short tetris, int  linetoget, int position)
{
	if(linetoget == 0)
		return ((tetris & 61440)>>position);
	if (linetoget == 1)
		return (((tetris & 3840)<<4)>>position);
	if(linetoget == 2)
		return (((tetris & 240)<<8)>>position);
	if(linetoget == 4)
		return (((tetris & 15)<<12)>>position);
}

unsigned short  filllinex(s_struct *tetri,int linetocheck)
{
	unsigned short line;
	
	line = 0;
	
	while(tetri->next != NULL)
	{
			
	}
}

int		within_line_border(unsigned short linetocheck, int	gridsize)
{
	unsigned short		mask;

	mask = 65535;
	return (((mask = mask>>gridsize) > 0 ) ? 0 : 1);
}

int		isgridvalid(t_tetris *tetris,int gridsize)
{
	while()
	{
	}
	return (0);
}
