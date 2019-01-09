/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffconvert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 17:26:07 by fratardi          #+#    #+#             */
/*   Updated: 2019/01/09 17:18:08 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static unsigned short		*ft_arr(void)
{
	unsigned short	*arr;

	arr = (unsigned short*)malloc(sizeof(unsigned short) * NO_OF_TETRIMINOS);
	arr[0] = 0x4C80;
	arr[1] = 0xC600;
	arr[2] = 0x6C00;
	arr[3] = 0x8C40;
	arr[4] = 0xCC00;
	arr[5] = 0x8888;
	arr[6] = 0xF000;
	arr[7] = 0xE800;
	arr[8] = 0xC440;
	arr[9] = 0xC880;
	arr[10] = 0xE200;
	arr[11] = 0x8E00;
	arr[12] = 0x2E00;
	arr[13] = 0x88C0;
	arr[14] = 0x44C0;
	arr[15] = 0xE400;
	arr[16] = 0x4E00;
	arr[17] = 0x8C80;
	arr[18] = 0x4C40;
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
