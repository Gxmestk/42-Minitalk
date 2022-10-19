/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:49:53 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/09/11 23:08:04 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_u(unsigned int u, t_format *f)
{
	char	*str;
	char	*rstr;

	f->len_f = ft_sort_max_three(f->arr, f->wdt, f->pcs, len(u, f));
	str = (char *)malloc(sizeof(char) * f->len_f + 1);
	if (!str)
		return (NULL);
	rstr = str;
	add_int_content(&str, u, f);
	return (rstr);
}
