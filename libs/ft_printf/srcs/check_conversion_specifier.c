/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conversion_specifier.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 10:41:11 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/09/12 01:14:06 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	check_conversion_specifier(char c)
{
	if (ft_strchr("cspdiuxX%%", c))
		return (c);
	return (0);
}
