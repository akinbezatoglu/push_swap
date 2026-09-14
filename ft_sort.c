/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 16:32:42 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/13 16:59:11 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_simple_algorithm(t_context **context, int should_print)
{
	printf("simple(%d): %u\n", should_print, (*context)->strategy);
}

void	ft_medium_algorithm(t_context **context, int should_print)
{
	printf("medium(%d): %u\n", should_print, (*context)->strategy);
}

void	ft_complex_algorithm(t_context **context, int should_print)
{
	printf("complex(%d): %u\n", should_print, (*context)->strategy);
}

void	ft_adaptive_algorithm(t_context **context, int should_print)
{
	if ((*context)->disorder < 0.2f)
		ft_simple_algorithm(context, should_print);
	else if ((*context)->disorder < 0.5f)
		ft_medium_algorithm(context, should_print);
	else
		ft_complex_algorithm(context, should_print);
}

void	ft_sort(t_context **context, int should_print)
{
	if ((*context)->strategy == SIMPLE)
		ft_simple_algorithm(context, should_print);
	else if ((*context)->strategy == MEDIUM)
		ft_medium_algorithm(context, should_print);
	else if ((*context)->strategy == COMPLEX)
		ft_complex_algorithm(context, should_print);
	else
		ft_adaptive_algorithm(context, should_print);
}
