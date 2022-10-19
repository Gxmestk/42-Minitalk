/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:00:27 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/09/11 23:09:31 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_c(char c, t_format *f)
{
	char	*str;
	char	*rstr;

	if (f->wdt > 1)
		f->len_f = f->wdt;
	else if (f->p && !f->pcs)
		f->len_f = 0;
	str = (char *)malloc(sizeof(char) * f->len_f + 1);
	if (!str)
		return (NULL);
	rstr = str;
	add_char_content(&str, c, f);
	return (rstr);
}
