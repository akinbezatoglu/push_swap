/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:46:47 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/10 15:50:59 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_context **ctx)
{
	swap(&(*ctx)->a);
	write(1, "sa\n", 3);
}

void	sb(t_context **ctx)
{
	swap(&(*ctx)->b);
	write(1, "sb\n", 3);
}

void	ss(t_context **ctx)
{
	swap(&(*ctx)->a);
	swap(&(*ctx)->b);
	write(1, "ss\n", 3);
}
