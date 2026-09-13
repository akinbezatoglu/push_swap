/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parse_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 17:04:32 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/02 07:39:25 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_handle_padding(char c, t_flags *flags)
{
	if (c == '#')
		flags->hash = 1;
	else if (c == ' ')
		flags->space = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (c == '-')
		flags->minus = 1;
	else if (c == '0')
		flags->zero = 1;
}

static const char	*ft_digit_shifting(const char *format)
{
	while (ft_isdigit(*format))
		format++;
	return (format);
}

const char	*ft_flags_parse(const char *format, t_flags *flags)
{
	while (ft_strchr("# +-0", *format))
	{
		ft_handle_padding(*format, flags);
		format++;
	}
	if (ft_isdigit(*format))
	{
		flags->width = ft_atoi(format);
		format = ft_digit_shifting(format);
	}
	if (*format == '.')
	{
		format++;
		if (ft_isdigit(*format))
		{
			flags->precision = ft_atoi(format);
			format = ft_digit_shifting(format);
		}
		else
			flags->precision = 0;
	}
	if (ft_strchr("cspdiuxX%", *format))
		flags->type = *format;
	return (format);
}
