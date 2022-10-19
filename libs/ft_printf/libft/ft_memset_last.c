/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:50:27 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/09/09 02:33:37 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset_last(void *dst, int val, int len)
{
	unsigned char	*p_dst;

	if (len <= 0)
		return (dst);
	p_dst = (unsigned char *)dst;
	while (len-- > 0)
		*(p_dst++) = (unsigned char)val;
	return (p_dst);
}
