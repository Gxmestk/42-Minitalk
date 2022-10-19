/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_by_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 03:01:00 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/09/12 01:29:09 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_by_format(char c, va_list args, t_format *f)
{
	char	*str;

	str = NULL;
	if (c == 'c')
		str = print_c(va_arg(args, int), f);
	else if (c == 's')
		str = print_s(va_arg(args, char *), f);
	else if (c == 'p')
		str = print_p((unsigned long long) va_arg(args, void *), f);
	else if (c == 'i' || c == 'd')
		str = print_d(va_arg(args, int), f);
	else if (c == 'u')
		str = print_u(va_arg(args, unsigned int), f);
	else if (c == 'x')
		str = print_x(va_arg(args, unsigned int), f, 0);
	else if (c == 'X')
		str = print_x(va_arg(args, unsigned int), f, 1);
	else if (c == '%')
		str = print_c('%', f);
	write(1, str, f->len_f);
	free(str);
	return (f->len_f);
}
