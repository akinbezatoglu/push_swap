/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_operations.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:59:45 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/10 16:07:37 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_context **ctx)
{
	reverse_rotate(&(*ctx)->a);
	write(1, "rra\n", 4);
}

void	rrb(t_context **ctx)
{
	reverse_rotate(&(*ctx)->b);
	write(1, "rrb\n", 4);
}

void	rrr(t_context **ctx)
{
	reverse_rotate(&(*ctx)->a);
	reverse_rotate(&(*ctx)->b);
	write(1, "rrr\n", 4);
}
