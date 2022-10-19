/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_int_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:55:13 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/09/11 23:10:23 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_int_content(char **str, long d, t_format *f)
{
	if (len(d, f) == f->arr[0] || f->pcs == f->arr[0])
		zero_abs_itoa(d, str, f);
	else if (f->wdt == f->arr[0])
	{
		if (f->minus)
		{
			zero_abs_itoa(d, str, f);
			print_wdt(str, f);
		}
		else
		{
			print_wdt(str, f);
			if (!f->zero || f->p)
				add_int_prefix(str, d, f);
			zero_abs_itoa(d, str, f);
		}
	}
	**str = '\0';
}
