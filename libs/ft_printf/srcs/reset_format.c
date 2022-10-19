/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 04:38:09 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/09/11 23:10:57 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_format(t_printf	*pf)
{
	pf->formatting = 1;
	pf->f.plus = 0;
	pf->f.sp = 0;
	pf->f.hash = 0;
	pf->f.minus = 0;
	pf->f.zero = 0;
	pf->f.wdt = 0;
	pf->f.pcs = 0;
	pf->f.p = 0;
	pf->f.star = 0;
	pf->f.len_f = 1;
	pf->f.prefix_len = 0;
}
