/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_print_nbr_u_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 22:33:05 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/06 19:51:35 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_flags_print_nbr_u(unsigned int n, t_flags *f, int *len)
{
	int		nbrlen;
	int		precision;
	int		padding;

	nbrlen = ft_count_digit_u(n, 10);
	precision = 0;
	if (n == 0 && f->precision == 0)
		nbrlen = 0;
	if (f->precision > nbrlen)
		precision = f->precision - nbrlen;
	padding = f->width - nbrlen - precision;
	if (f->minus == 0 && f->zero == 0)
		ft_put_padding(' ', padding, len);
	if (f->zero == 1)
		ft_put_padding('0', padding, len);
	ft_put_padding('0', precision, len);
	if (nbrlen > 0)
		ft_putnbr_unsigned(n, len);
	if (f->minus == 1)
		ft_put_padding(' ', padding, len);
}
