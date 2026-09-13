/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_new_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:32:29 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/06 20:47:05 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_flags	*ft_flags_new(void)
{
	t_flags	*f;

	f = (t_flags *)malloc(1 * sizeof(t_flags));
	if (!f)
		return (NULL);
	f->type = 0;
	f->minus = 0;
	f->zero = 0;
	f->precision = -1;
	f->width = 0;
	f->hash = 0;
	f->space = 0;
	f->plus = 0;
	return (f);
}
