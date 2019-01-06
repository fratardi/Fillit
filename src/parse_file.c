/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 17:16:10 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/05 18:07:43 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int			ft_checkadj(const char *str, const int i)
{
	int		count;

	count = 0;
	if (i % 5 != 0)
		count = str[i - 1] == '#' ? count + 1 : count;
	if ((i + 2) % 5 != 0)
		count = str[i + 1] == '#' ? count + 1 : count;
	if (i < 15)
		count = str[i + 5] == '#' ? count + 1 : count;
	if (i > 4)
		count = str[i - 5] == '#' ? count + 1 : count;
	return (count);
}

static int			ft_checksum(const char *str)
{
	int			cnt_dot;
	int			cnt_hash;
	int			cnt;
	int			i;

	i = 0;
	cnt_dot = 0;
	cnt_hash = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == '#' && (cnt_hash = cnt_hash + 1))
			cnt += ft_checkadj(str, i);
		if (str[i] == '.')
			cnt_dot++;
		if (str[i] == '\n' && (i + 1) % 5 != 0)
			return (0);
		i++;
	}
	return (cnt_dot + cnt_hash == 16 && (cnt == 6 || cnt == 8));
}

static int			ft_read(const int fd, char **str)
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

int					ft_read_file(const int fd, t_tetris **head)
{
	char			*line;
	int				ret;
	char			ch;
	t_tetris		*ele;
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
