/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffconvert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 17:26:07 by fratardi          #+#    #+#             */
/*   Updated: 2019/01/03 15:57:45 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static unsigned short		*ft_arr(void)
{
	unsigned short	*arr;

	arr = (unsigned short*)malloc(sizeof(unsigned short) * NO_OF_TETRIMINOS);
	arr[0] = 19584;
	arr[1] = 50688;
	arr[2] = 27648;
	arr[3] = 35904;
	arr[4] = 52224;
	arr[5] = 34952;
	arr[6] = 61440;
	arr[7] = 59392;
	arr[8] = 50240;
	arr[9] = 51328;
	arr[10] = 57856;
	arr[11] = 36352;
	arr[12] = 11776;
	arr[13] = 58368;
	arr[14] = 19968;
	arr[15] = 35968;
	arr[16] = 19520;
	return (arr);
}

static int					ft_eq(unsigned short *arr, unsigned short value)
{
	int		i;

	i = 0;
	while (i < NO_OF_TETRIMINOS)
		if (arr[i++] == value)
			return (1);
	return (0);
}

static unsigned short		toplefter(unsigned short value)
{
	unsigned short		*arr;

	arr = ft_arr();
	while (value != 0 && !ft_eq(arr, value))
		value = value << 1;
	free(arr);
	return (value);
}

unsigned short				buffconvert(const char *str)
{
	unsigned short		mask;
	unsigned short		ret;
	size_t				pos;
	int					b;

	pos = 0;
	ret = 0;
	mask = 32768;
	b = 0;
	while (pos < 21 && str[pos])
	{
		while (str[pos] && str[pos] != '\n')
		{
			if (str[pos] == '#' && (b = 1))
				ret = ret | mask;
			mask = mask >> 1;
			pos++;
		}
		mask = b ? mask : 32768;
		pos++;
	}
	return (toplefter(ret));
}
