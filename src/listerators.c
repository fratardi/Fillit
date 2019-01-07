/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listerators.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:56:08 by fratardi          #+#    #+#             */
/*   Updated: 2019/01/07 18:05:12 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	set_pos_x_y_to_zero(t_tetris *first)
{
	if (first)
	{
		first->oxy[2] = 0;
		first->oxy[3] = 0;
		set_pos_x_y_to_zero(first->next);
	}
	return ;
}

void	sort_list_according_to_o(t_tetris *first)
{
	;
}
