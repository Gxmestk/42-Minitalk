/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:55:25 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/10/19 17:30:24 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
			i++;
	if (str[i] == '-')
	{
			sign = -1;
			i++;
	}
	else if (str[i] == '+')
			i++;
	while (str[i] >= '0' && str[i] <= '9')
			result = (result * 10) + (str[i++] - 48);
	return (result * sign);
}
