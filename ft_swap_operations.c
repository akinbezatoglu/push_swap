/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:46:47 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/13 15:57:32 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_context **ctx, int should_print)
{
	swap(&(*ctx)->a);
	(*ctx)->sa += 1;
	if (should_print)
		write(1, "sa\n", 3);
}

void	sb(t_context **ctx, int should_print)
{
	swap(&(*ctx)->b);
	(*ctx)->sb += 1;
	if (should_print)
		write(1, "sb\n", 3);
}

void	ss(t_context **ctx, int should_print)
{
	swap(&(*ctx)->a);
	swap(&(*ctx)->b);
	(*ctx)->ss += 1;
	if (should_print)
		write(1, "ss\n", 3);
}
