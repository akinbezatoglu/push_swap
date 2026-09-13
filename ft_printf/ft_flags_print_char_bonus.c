/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_print_char_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 07:46:19 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/03 08:45:26 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_flags_print_char(char c, t_flags *f, int *len)
{
	int	padding;

	padding = f->width - 1;
	if (f->minus == 0)
		ft_put_padding(' ', padding, len);
	ft_putchar(c, len);
	if (f->minus == 1)
		ft_put_padding(' ', padding, len);
}
