/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 19:45:51 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/06 21:06:57 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_digit_u(unsigned long n, int base)
{
	int		count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

int	ft_count_digit(int n)
{
	long	nb;

	nb = n;
	if (n < 0)
		nb = -nb;
	return (ft_count_digit_u(nb, 10));
}
