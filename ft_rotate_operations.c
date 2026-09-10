/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:55:49 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/10 21:56:10 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_context **ctx, int should_print)
{
	rotate(&(*ctx)->a);
	if (should_print)
		write(1, "ra\n", 3);
}

void	rb(t_context **ctx, int should_print)
{
	rotate(&(*ctx)->b);
	if (should_print)
		write(1, "rb\n", 3);
}

void	rr(t_context **ctx, int should_print)
{
	rotate(&(*ctx)->a);
	rotate(&(*ctx)->b);
	if (should_print)
		write(1, "rr\n", 3);
}
