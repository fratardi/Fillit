/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 06:39:55 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/03 12:57:18 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char	*rez;

	if (!(rez = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	ft_strncpy(rez, s1, n);
	return (rez);
}
