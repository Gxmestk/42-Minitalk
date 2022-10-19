/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:12:44 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/09/10 15:16:27 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlcpy(char *dst, const char *src, int size)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (src[len] != '\0')
	{
		if (len + 1 < size)
		{
			i++;
			dst[len] = src[len];
		}
		len++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (i);
}
