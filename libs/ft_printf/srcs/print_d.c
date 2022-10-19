/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 03:20:18 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/09/12 01:27:03 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_d(int d, t_format *f)
{
	char	*str;
	char	*rstr;

	f->len_f = ft_sort_max_three(f->arr, f->wdt, f->pcs, len(d, f));
	if (f->plus || f->sp || d < 0)
	{
		f->len_f++;
		f->prefix_len++;
	}
	str = (char *)malloc(sizeof(char) * f->len_f + 1);
	if (!str)
		return (NULL);
	rstr = str;
	if (f->wdt != f->arr[0] || f->minus || (f->zero && !f->p)
		|| f->arr[0] == f->arr[1])
		add_int_prefix(&str, d, f);
	add_int_content(&str, d, f);
	return (rstr);
}

/*len_d, f->pcs, f->wdt
	len_d, f->wdt, f->pcs

	f->wdt, len_d, f->pcs
	f->wdt, f->pcs, len_d

	f->pcs, len_d, f->wdt
	f->pcs, f->wdt, len_d

	f->minus;
	f->zero; 

	zero ignore with minus, precision
    sp  ignore with plus
	while til technique is interesting while while i++ s++   s++*/