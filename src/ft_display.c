/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:57:30 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/08 15:51:30 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		**ft_strarrnew(size_t size)
{
	char		**str;
	size_t		i;

	if (!(str = (char**)malloc(sizeof(char*) * (size + 1))))
		return (0);
	i = 0;
	while (i < size)
		str[i++] = ft_strnew(size);
	str[i] = 0;
	return (str);
}

void		ft_strarrdel(char ***as)
{
	char	**str;

	if (!as || !*as)
		return ;
	str = *as;
	while (*str)
		ft_strdel(str++);
	free(*as);
	*as = 0;
}

void		ft_strarrdisp(char **str, const int size)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 0;
		while (i < size)
			ft_putchar((c = (*str)[i++]) ? c : '.');
		str++;
		ft_putchar('\n');
	}
}

void		ft_fit_tetri(t_tetris *head, char **str)
{
	int			mask;
	int			i1;
	int			j1;
	int			i;

	i = 0;
	i1 = head->oxy[0];
	j1 = head->oxy[1];
	mask = 0x8000;
	while (i++ < 16)
	{
		if (mask & head->tetri)
			str[i1][j1] = (char)head->oxy[2];
		mask = mask >> 1;
		j1 = j1 + 1;
		if (i % 4 == 0 && (i1 = i1 + 1))
			j1 = head->oxy[1];
	}
}

int			ft_display(t_tetris *head, const int size)
{
	t_tetris	*ele;
	char		**str;
	int			i;

	ele = head;
	if (!(str = ft_strarrnew(size)))
		return (0);
	while (ele)
	{
		ft_fit_tetri(ele, str);
		ele = ele->next;
	}
	i = 0;
	ft_strarrdisp(str, size);
	ft_strarrdel(&str);
	return (1);
}
