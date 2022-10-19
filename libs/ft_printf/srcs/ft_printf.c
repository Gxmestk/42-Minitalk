/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:01:57 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/09/12 01:11:50 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	read_input(char *str, t_printf *pf)
{
	while (*str)
	{
		if (*str == '%' || pf->formatting)
		{
			if (pf->formatting)
			{
				pf->c = check_format(*str, pf->args, &pf->f);
				if (pf->c)
				{
					pf->len += print_by_format(pf->c, pf->args, &pf->f);
					pf->formatting = 0;
				}
			}
			else
				reset_format(pf);
		}
		else
			pf->len += write(1, str, 1);
		str++;
	}
}

int	ft_printf(const char *str, ...)
{
	t_printf	pf;

	if (str == NULL)
		return (0);
	pf.formatting = 0;
	pf.len = 0;
	va_start(pf.args, str);
	read_input((char *)str, &pf);
	va_end(pf.args);
	return (pf.len);
}
