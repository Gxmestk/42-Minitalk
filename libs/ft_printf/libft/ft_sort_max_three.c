/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_max_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:54:50 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/09/11 23:13:10 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int	ft_sort_max_three(int arr[3], int a, int b, int c)
{
	if (a < b)
		ft_swap(&a, &b);
	if (a < c)
		ft_swap(&a, &c);
	if (b < c)
		ft_swap(&b, &c);
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	return (arr[0]);
}
