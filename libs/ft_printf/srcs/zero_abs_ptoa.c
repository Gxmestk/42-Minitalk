/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_abs_ptoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:01:06 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/09/11 22:50:21 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lenp(unsigned long long n)
{
	int	size;

	size = 0;
	if (n == 0)
		size++;
	while (n)
	{
		size++;
		n = n / 16;
	}
	return (size);
}

void	zero_abs_ptoa(unsigned long long p, char **str, t_format *f)
{
	int					size;
	unsigned long long	addr;

	if (!(*str))
		return ;
	size = lenp(p);
	*str = (char *)ft_memset_last(*str, '0', f->pcs - size);
	if (p == 0 && (f->pcs || !f->p))
	{
		**str = '0';
		(*str)++;
		if (f->hash)
			f->len_f -= f->prefix_len;
		return ;
	}
	size--;
	addr = p;
	while (p)
	{
		*((*str) + size) = "0123456789abcdef"[p % 16];
		p = p / 16;
		size--;
	}
	*str += lenp(addr);
}
