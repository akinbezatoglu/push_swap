/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_padding_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 08:43:04 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/03 08:44:21 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_put_padding(char c, int strlen, int *len)
{
	while (strlen > 0)
	{
		ft_putchar(c, len);
		strlen--;
	}
}
