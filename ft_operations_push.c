/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:51:45 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/20 09:48:08 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_context **ctx)
{
	push(&(*ctx)->b, &(*ctx)->a);
	(*ctx)->pa += 1;
	if ((*ctx)->print_ops)
		write(1, "pa\n", 3);
}

void	pb(t_context **ctx)
{
	push(&(*ctx)->a, &(*ctx)->b);
	(*ctx)->pb += 1;
	if ((*ctx)->print_ops)
		write(1, "pb\n", 3);
}
