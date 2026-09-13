/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_override_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 22:30:22 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/05 13:39:05 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_flags_override(t_flags *flags)
{
	if (flags->minus == 1)
		flags->zero = 0;
	if (flags->plus == 1)
		flags->space = 0;
	if (flags->precision >= 0 && ft_strchr("diuxX", flags->type))
		flags->zero = 0;
	if (flags->type != 'd' && flags->type != 'i')
	{
		flags->plus = 0;
		flags->space = 0;
	}
	if (ft_strchr("csp", flags->type))
		flags->zero = 0;
}
