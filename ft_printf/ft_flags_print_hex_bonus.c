/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_print_hex_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 22:28:48 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/06 19:52:35 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_put_hash(char x, int *len)
{
	ft_putchar('0', len);
	ft_putchar(x, len);
}

void	ft_flags_print_hex(unsigned int n, t_flags *f, int *len, char x)
{
	int	nbrlen;
	int	precision;
	int	padding;

	precision = 0;
	nbrlen = ft_count_digit_u(n, 16);
	if (n == 0 && f->precision == 0)
		nbrlen = 0;
	if (f->precision > nbrlen)
		precision = f->precision - nbrlen;
	padding = f->width - nbrlen - precision;
	if (f->hash == 1)
		padding -= 2;
	if (f->minus == 0 && f->zero == 0)
		ft_put_padding(' ', padding, len);
	if (f->hash == 1 && n != 0)
		ft_put_hash(x, len);
	if (f->zero == 1)
		ft_put_padding('0', padding, len);
	ft_put_padding('0', precision, len);
	if (nbrlen > 0)
		ft_puthex(n, len, x);
	if (f->minus == 1)
		ft_put_padding(' ', padding, len);
}
