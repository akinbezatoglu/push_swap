/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_print_ptr_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 22:27:48 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/06 19:51:49 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_flags_print_ptr(void *ptr, t_flags *f, int *len)
{
	unsigned long	p;
	int				nbrlen;
	int				padding;

	p = (unsigned long)ptr;
	nbrlen = 0;
	if (p == 0)
		padding = f->width - ft_strlen("(nil)");
	else
	{
		nbrlen = ft_count_digit_u(p, 16);
		padding = f->width - nbrlen - ft_strlen("0x");
	}
	if (f->minus == 0)
		ft_put_padding(' ', padding, len);
	if (p == 0)
		ft_putstr("(nil)", len);
	else
	{
		ft_putstr("0x", len);
		ft_puthex(p, len, 'x');
	}
	if (f->minus == 1)
		ft_put_padding(' ', padding, len);
}
