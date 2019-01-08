/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 10:59:10 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/08 16:22:40 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_check_line_overflow(unsigned int grid_l, int j, \
									unsigned int tetri_l, int size)
{
	unsigned int	mask;
	unsigned int	grid_mask;

	mask = 0xF;
	grid_mask = 0x8 << (32 - j - 4);
	while (mask && j < size)
	{
		if (tetri_l & grid_l & grid_mask)
			return (0);
		grid_mask = grid_mask >> 1;
		mask = mask >> 1;
		j++;
	}
	if (mask && j >= size && (tetri_l & grid_mask))
		return (0);
	return (1);
}

int			ft_check_line(unsigned int grid_l, t_tetris *head, \
							int mask, int size)
{
	int					j;
	unsigned int		grid_mask;
	unsigned int		tetri_cpy;

	grid_mask = 0xF;
	j = head->oxy[1];
	tetri_cpy = head->tetri & mask;
	while (mask != 0xF)
	{
		tetri_cpy = tetri_cpy >> 1;
		mask = mask >> 1;
	}
	tetri_cpy = tetri_cpy << (32 - j - 4);
	if (!ft_check_line_overflow(grid_l, j, tetri_cpy, size))
		return (-1);
	return (grid_l ^ tetri_cpy);
}

int			ft_isvalid(unsigned int *grid, t_tetris *head, const int size)
{
	int		i;
	int		j;
	int		mask;
	int		ret;

	i = head->oxy[0];
	j = head->oxy[1];
	if (i >= size || j >= size || i < 0 || j < 0)
		return (0);
	mask = 0xF000;
	if ((ret = ft_check_line(grid[i], head, mask, size)) == -1)
		return (0);
	grid[i] = ret;
	while ((mask = mask >> 4) && ++i < size)
	{
		if ((ret = ft_check_line(grid[i], head, mask, size)) == -1)
			return (0);
		grid[i] = ret;
	}
	if (mask && i >= size && (mask & head->tetri))
		return (0);
	return (1);
}

int			ft_compute(unsigned int **grid, int size, t_tetris *head)
{
	unsigned int		*dup;
	int					ret;

	dup = ft_intarrdup(*grid, size);
	ret = ft_isvalid(dup, head, size);
	if ((ret))
		ret = ft_solve(&dup, size, head->next);
	ft_intarrdel(&dup, size);
	return (ret);
}

int			ft_solve(unsigned int **grid, int size, t_tetris *head)
{
	if (!head)
		return (1);
	head->oxy[0] = 0;
	while (head->oxy[0] < size)
	{
		head->oxy[1] = -1;
		while (++(head->oxy[1]) < size)
			if (ft_compute(grid, size, head))
				return (1);
		head->oxy[0] = head->oxy[0] + 1;
	}
	return (0);
}
