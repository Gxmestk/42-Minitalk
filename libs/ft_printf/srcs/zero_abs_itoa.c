/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_abs_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:12:31 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/09/11 23:07:53 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len(long n, t_format *f)
{
	int	size;

	size = 0;
	if (n == 0 && (f->pcs || !f->p))
		size++;
	while (n)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

void	zero_abs_itoa(long n, char **str, t_format *f)
{
	int		size;
	long	num;

	if (!(*str))
		return ;
	size = len(n, f);
	*str = (char *)ft_memset_last(*str, '0', f->pcs - size);
	num = n;
	if (num < 0)
		num = -num;
	if (num == 0 && (f->pcs || !f->p))
		**str = '0';
	size--;
	while (num)
	{
		*((*str) + size) = (num % 10) + 48;
		num = num / 10;
		size--;
	}
	*str += len(n, f);
}
/*
 num != 0 || (!f->pcs && f->p)
 */
