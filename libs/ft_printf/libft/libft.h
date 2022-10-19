/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:07:54 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/09/10 14:15:59 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_isdigit(int c);
char	*ft_strchr(const char *str, int c);
int		ft_sort_max_three(int arr[3], int a, int b, int c);
void	*ft_memset_last(void *dst, int val, int len);
char	*ft_strupper(char *str);
int		ft_strlen(const char *str);
int		ft_strlcpy(char *dst, const char *src, int size);
#endif
