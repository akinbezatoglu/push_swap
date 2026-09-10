/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:51:45 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/10 15:55:33 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_context **ctx)
{
	push(&(*ctx)->b, &(*ctx)->a);
	write(1, "pa\n", 3);
}

void	pb(t_context **ctx)
{
	push(&(*ctx)->a, &(*ctx)->b);
	write(1, "pb\n", 3);
}
