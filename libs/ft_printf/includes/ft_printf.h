/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhemniw <gt.khemniwat@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 22:34:52 by tkhemniw          #+#    #+#             */
/*   Updated: 2022/09/11 01:59:39 by tkhemniw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "limits.h"

typedef struct s_format
{
	int			plus;
	int			sp;
	int			hash;
	int			minus;
	int			zero;
	int			wdt;
	int			pcs;
	int			p;
	int			star;
	long long	len_f;
	int			prefix_len;
	int			arr[3];
}		t_format;

typedef struct s_printf
{
	va_list		args;
	size_t		len;
	t_format	f;
	char		c;
	int			formatting;
}		t_printf;

int		ft_printf(const char *str, ...);
char	check_format(char c, va_list args, t_format *f);
int		check_flag(char c, t_format *f);
int		check_min_width(char c, va_list args, t_format *f);
int		check_precision(char c, t_format *f);
int		check_length_modifier(char c, va_list args, t_format *f);
char	check_conversion_specifier(char c);
int		print_by_format(char c, va_list args, t_format *f);
char	*print_d(int d, t_format *f);
char	*print_c(char c, t_format *f);
char	*print_u(unsigned int u, t_format *f);
char	*print_x(unsigned int x, t_format *f, int upper);
char	*print_p(unsigned long long p, t_format *f);
char	*print_s(char *s, t_format *f);
void	add_int_prefix(char **str, long d, t_format *f);
void	add_int_content(char **str, long d, t_format *f);
void	zero_abs_itoa(long n, char **str, t_format *f);
void	print_wdt(char **str, t_format *f);
int		len(long n, t_format *f);
void	reset_format(t_printf	*pf);
void	add_hex_prefix(char **str, unsigned long long x, t_format *f);
void	add_hex_content(char **str, unsigned long long x, t_format *f);
int		lenx(unsigned long long n, t_format *f);
int		lenp(unsigned long long n);
void	zero_abs_htoa(unsigned long long x, char **str, t_format *f);
void	add_addr_prefix(char **str);
void	add_addr_content(char **str, unsigned long long x, t_format *f);
void	zero_abs_ptoa(unsigned long long x, char **str, t_format *f);
int		lenw(char *s, t_format *f);
void	add_char_content(char **str, char c, t_format *f);
void	add_str_content(char **str, char *s, t_format *f, int lenw);
#endif