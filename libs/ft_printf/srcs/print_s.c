/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:49:04 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/09/11 23:09:06 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lenw(char *s, t_format *f)
{	
	int	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (f->p && f->pcs < s_len)
		return (f->pcs);
	return (s_len);
}

char	*print_s(char *s, t_format *f)
{
	char	*str;
	char	*rstr;
	int		len;

	if (!s)
		len = lenw("(null)", f);
	else
		len = lenw(s, f);
	if (f->wdt > len)
		f->len_f = f->wdt;
	else
		f->len_f = len;
	str = (char *)malloc(sizeof(char) * f->len_f + 1);
	if (!str)
		return (NULL);
	rstr = str;
	if (!s)
		add_str_content(&str, "(null)", f, len);
	else
		add_str_content(&str, s, f, len);
	return (rstr);
}
