/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_print_str_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 08:38:23 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/03 08:44:59 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_flags_print_str(char *s, t_flags *f, int *len)
{
	int	strlen;
	int	padding;

	if (!s)
		s = "(null)";
	strlen = ft_strlen(s);
	if (f->precision >= 0 && f->precision < strlen)
		strlen = f->precision;
	padding = f->width - strlen;
	if (f->minus == 0)
		ft_put_padding(' ', padding, len);
	ft_putnstr(s, strlen, len);
	if (f->minus == 1)
		ft_put_padding(' ', padding, len);
}
