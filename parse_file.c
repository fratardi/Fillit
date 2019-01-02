/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 17:16:10 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/02 18:33:55 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_read(const int fd, char **str)
{
	int		ret;
	char	*buf;
	char	ch;

	buf = (char*)malloc(sizeof(char) * 20);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	if (ret < BUFF_SIZE || ft_strlen(buf) != 20 || !ft_checksum(buf))
		return (-1);
	if ((ret = read(fd, &ch, 1)) && ch != '\n')
		return (-1);
	*str = buf;
	if (ret == 0)
		return (0);
	return (1);
}

int			ft_read_file(const int fd, t_tetris **head)
{
	char		*line;
	int			ret;
	char		ch;
	t_tetris	*ele;
	unsigned short	tetri;

	ch = 'A';
	if (fd < 0 || read(fd, line, 0) < 0)
		return (0);
	while ((ret = ft_read(fd, &line)) == 1 && ch <= 'Z')
	{
		if (!ft_tetriconvert(head, ch++, line))
			return (0);
		free(line);
	}
	if (ret == -1 || ch == 'Z')
		return (0);
	if (!ft_tetriconvert(head, ch, line))
		return (0);
	free(line);
	return (1);
}
