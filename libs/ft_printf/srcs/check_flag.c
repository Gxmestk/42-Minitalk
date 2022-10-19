/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 06:13:35 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/09/12 01:11:44 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flag(char c, t_format *f)
{
	if (c == '+')
		f->plus = 1;
	else if (c == ' ')
		f->sp = 1;
	else if (c == '#')
		f->hash = 1;
	else if (c == '0' && !f->wdt && !f->pcs)
		f->zero = 1;
	else if (c == '-' && !f->minus)
		f->minus = 1;
	else
		return (0);
	return (1);
}
