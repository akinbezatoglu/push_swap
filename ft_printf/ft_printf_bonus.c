/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:07:28 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/05 15:19:25 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_print_typeof(va_list *args, t_flags *f, int *len)
{
	if (f->type == 'c')
		ft_flags_print_char(va_arg(*args, int), f, len);
	else if (f->type == 's')
		ft_flags_print_str(va_arg(*args, char *), f, len);
	else if (f->type == 'd' || f->type == 'i')
		ft_flags_print_nbr(va_arg(*args, int), f, len);
	else if (f->type == 'u')
		ft_flags_print_nbr_u(va_arg(*args, unsigned int), f, len);
	else if (f->type == 'X' || f->type == 'x')
		ft_flags_print_hex(va_arg(*args, unsigned int), f, len, f->type);
	else if (f->type == 'p')
		ft_flags_print_ptr(va_arg(*args, void *), f, len);
	else if (f->type == '%')
		ft_putchar('%', len);
}

static const char	*ft_handle_one(va_list *args, const char *format, int *len)
{
	t_flags	*flags;

	flags = ft_flags_new();
	if (!flags)
		return (NULL);
	format = ft_flags_parse(format, flags);
	if (!flags->type)
	{
		free(flags);
		return (NULL);
	}
	ft_flags_override(flags);
	ft_print_typeof(args, flags, len);
	free(flags);
	return (format);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	if (!format)
		return (-1);
	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			format = ft_handle_one(&args, format, &len);
			if (!format)
			{
				va_end(args);
				return (-1);
			}
		}
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(args);
	return (len);
}
