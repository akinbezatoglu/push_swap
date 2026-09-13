/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_print_nbr_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 09:51:22 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/06 19:46:00 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	ft_get_prefix(int *n, t_flags *f)
{
	if (*n < 0)
	{
		*n *= -1;
		return ('-');
	}
	if (f->plus == 1)
		return ('+');
	if (f->space == 1)
		return (' ');
	return (0);
}

void	ft_flags_print_nbr(int n, t_flags *f, int *len)
{
	int		nbrlen;
	int		precision;
	int		padding;
	char	prefix;

	prefix = ft_get_prefix(&n, f);
	nbrlen = ft_count_digit(n);
	precision = 0;
	if (n == 0 && f->precision == 0)
		nbrlen = 0;
	if (f->precision > nbrlen)
		precision = f->precision - nbrlen;
	padding = f->width - nbrlen - precision - (prefix != 0);
	if (f->minus == 0 && f->zero == 0)
		ft_put_padding(' ', padding, len);
	if (prefix != 0)
		ft_putchar(prefix, len);
	if (f->zero == 1)
		ft_put_padding('0', padding, len);
	ft_put_padding('0', precision, len);
	if (nbrlen > 0)
		ft_putnbr_unsigned(n, len);
	if (f->minus == 1)
		ft_put_padding(' ', padding, len);
}
