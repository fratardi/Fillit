/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fitnexttoprev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:08:48 by fratardi          #+#    #+#             */
/*   Updated: 2019/01/07 18:49:56 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	fitnexttoprev(t_tetri *prev, t_tetri *next,int  gridsize)
{
	if((((next->oxy[2]) - prev->oxy[2]) || (next->oxy[3] - prev->oxy[3])) >= 4)
		means no need to check because there is no way they overlap
}
