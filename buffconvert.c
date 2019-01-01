/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffconvert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 17:26:07 by fratardi          #+#    #+#             */
/*   Updated: 2019/01/01 19:08:12 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "./libft/libft.h"
# define BUFF_SIZE 20
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>


//#define TETRI (52224 && 19520 )

unsigned short	toplefter(unsigned short value);

int			ft_checksum(char *str)
{
	int sum;
	int total;


	total = 0;
	sum = 4 * (int)('#') + 12 * (int)('.') + 4 * (int)('\n');
	
	while(*str)
		total = total + (int)*(str++);
	return (total == sum);
}

unsigned short	buffconvert(char *str)
{
	unsigned short	mask;
	unsigned short 	ret;
	size_t			pos;
	
	pos = 0;
	ret = 0;
	mask = 32768;
	if (ft_strlen(str) != 20 || !ft_checksum(str))
		return (0);
	while(pos < 21 && str[pos])
	{
		while(str[pos] && str[pos] != '\n')
		{
			if(str[pos] == '#')
				ret =ret | mask;
			mask = mask>>1;
			pos++;
		}
		pos++;
	}
	return(toplefter(ret));
}

unsigned short			*ft_arr()
{
	unsigned short	*arr;

	arr = (unsigned short*)malloc(sizeof(unsigned short) * 15);
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
	arr[11] = 58368;
	arr[12] = 19968;
	arr[13] = 35968;
	arr[14] = 19520;

	return (arr);
}

int					ft_eq(unsigned short *arr, unsigned short value)
{
	int		i;

	i = 0;
	while (i < 15)
		if (arr[i++] == value)
			return (1);
	return (0);
}

unsigned short		toplefter(unsigned short value)
{
	unsigned short		*arr;

	arr = ft_arr();
	while(value != 0 && !ft_eq(arr, value))
		value = value << 1 ;	
	return(value);
}

char				*ft_read(char *file)
{
	int		fd;
	int		ret;
	char	*buf;
	char	ch;

	fd = open(file, O_RDONLY);
	buf = (char*)malloc(sizeof(char) * 20);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	if (ret < BUFF_SIZE || ft_strlen(buf) != 20 || !ft_checksum(buf))
		return (0);
	if ((ret = read(fd, &ch, 1)) && ch != '\n')
		return (0);
	return (buf);
}

int main(int ac, char **av)
{
	char str[21]= "....\n##..\n.##.\n....\n"; 

	printf("%s", ft_read(av[1]));
//	printf("RETURN : %d\n", buffconvert(str));
//	printf("OUTPUT : %d\n", TETRI);
//	printf("RET2RN : %d", toplefter(buffconvert(str)));
}
