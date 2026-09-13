/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 09:10:04 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/02 09:26:05 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putnstr(char *s, int n, int *len)
{
	while (*s && n > 0)
	{
		ft_putchar(*s, len);
		s++;
		n--;
	}
}
