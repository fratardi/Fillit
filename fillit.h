/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 12:01:39 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/29 15:07:51 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FILLIT_H
# define FILLIT_H

#include ".libft/libft.a"

int	ft_checkargsforfillit(const int ,const char **argv);
int ft_checkinputisvalid(const char *tab);
unsigned short *gridtoshort(const char *tab);



#endif
