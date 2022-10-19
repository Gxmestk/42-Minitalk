/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wdt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:10:22 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/09/11 23:08:08 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_wdt(char **str, t_format *f)
{
	char	w;

	if (!(*str))
		return ;
	w = ' ';
	if (f->zero && !f->minus && !f->p)
		w = '0';
	*str = (char *)ft_memset_last(*str, w, f->wdt
			- f->arr[1] - f->prefix_len);
	if (f->wdt - f->arr[1] - f->prefix_len < 0)
		f->len_f = f->arr[1] + f->prefix_len;
	else if (f->wdt - f->arr[1] > 0)
		f->len_f -= f->prefix_len;
}
