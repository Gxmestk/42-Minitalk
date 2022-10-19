/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_int_prefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:00:35 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/09/11 23:11:50 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_int_prefix(char **str, long d, t_format *f)
{
	if (d < 0)
		**str = '-';
	else if (f->plus)
		**str = '+';
	else if (f->sp)
		**str = ' ';
	else
		return ;
	(*str)++;
}
