/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarrop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:27:45 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/08 13:50:04 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

unsigned int		*ft_intarrnew(int size)
{
	int		i;
	unsigned int		*arr;

	if (!(arr = (unsigned int*)malloc(sizeof(int) * (size))))
		return (0);
	i = 0;
	while (i < size)
		arr[i++] = 0;
	return (arr);
}

unsigned int		*ft_intarrdup(unsigned int *arr, int size)
{
	int					i;
	unsigned int		*dup;

	if (!(dup = ft_intarrnew(size)))
		return (0);
	i = -1;
	while (++i < size)
		dup[i] = arr[i];
	return (dup);
}

void	ft_intarrdel(unsigned int **arr, int size)
{
	int		i;

	if (!arr || !*arr)
		return ;
	i = -1;
	while (++i < size)
		(*arr)[i] = 0;
	free(*arr);
	*arr = 0;
}

int		ft_findsqrt(int num)
{
	int		i;

	i = 1;
	if (num == 0 || num == 1)
		return (num);
	while (++i < 46340)
		if (i * i >= num)
			return (i);
	return (i);
}
