/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 18:54:54 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/07 18:42:26 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

void	ft_freetetri(t_tetris **head)
{
	if (!head || !*head)
		return ;
	ft_freetetri(&((*head)->next));
	free(*head);
	*head = 0;
}

int		ft_puterror(int ac, t_tetris **head, int i)
{
	if (ac != 2)
	{
		ft_putendl("usage: fillit input_file");
		return (0);
	}
	if (head && *head)
		ft_freetetri(head);
	if (!i)
		ft_putstr("error");
	return (0);
}

/*int		main(int ac, char **av)
{
	t_tetris	*link;
	int			fd;

	if (ac != 2)
		return (ft_puterror(ac, 0, 0));
	if (0 > (fd = open(av[1], O_RDONLY)))
		return (ft_puterror(ac, 0, 0));
	if (!(ft_read_file(fd, &link)))
		return (ft_puterror(ac, &link, 0));
	ft_tetrisdisp(link);
	return (ft_puterror(ac, &link, 1));
}*/

int			main(int ac, char **av)
{
	int			fd;
	char		buf[13];
	char		**str;
	int			ret;
	int			size;
	t_tetris	*head;
	t_tetris	*ele;

	fd = open(av[1], O_RDONLY);
	size = 4;
	head = 0;
	while ((ret = read(fd, buf, 12)) == 12)
	{
		buf[ret] = 0;
		str = ft_strsplit(buf, ' ');
		ele = ft_tetrisnew(str[0][0], (unsigned short)ft_atoi(str[1]));
		ele->oxy[0] = ft_atoi(str[2]);
		ele->oxy[1] = ft_atoi(str[3]);
		ft_tetrisaddlast(&head, ele);
	}
	ft_display(head, size);
	return (0);
}
