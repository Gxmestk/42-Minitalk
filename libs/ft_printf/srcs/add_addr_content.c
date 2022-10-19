/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_addr_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:51:36 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/09/11 23:06:58 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_addr_content(char **str, unsigned long long p, t_format *f)
{
	if (lenp(p) == f->arr[0] || f->pcs == f->arr[0])
		zero_abs_ptoa(p, str, f);
	else if (f->wdt == f->arr[0])
	{
		if (f->minus)
		{
			zero_abs_ptoa(p, str, f);
			print_wdt(str, f);
		}
		else
		{
			print_wdt(str, f);
			if (!f->zero)
				add_addr_prefix(str);
			zero_abs_ptoa(p, str, f);
		}
	}
	**str = '\0';
}
