/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 16:32:42 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/13 16:59:11 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_simple_algorithm(t_context **context)
{
	printf("simple: %u\n", (*context)->strategy);
}

void	ft_medium_algorithm(t_context **context)
{
	printf("medium: %u\n", (*context)->strategy);
}

void	ft_complex_algorithm(t_context **context)
{
	printf("complex: %u\n", (*context)->strategy);
}

void	ft_adaptive_algorithm(t_context **context)
{
	if ((*context)->disorder < 0.2f)
		ft_simple_algorithm(context);
	else if ((*context)->disorder < 0.5f)
		ft_medium_algorithm(context);
	else
		ft_complex_algorithm(context);
}

void	ft_solve(t_context **context)
{
	if ((*context)->strategy == SIMPLE)
		ft_simple_algorithm(context);
	else if ((*context)->strategy == MEDIUM)
		ft_medium_algorithm(context);
	else if ((*context)->strategy == COMPLEX)
		ft_complex_algorithm(context);
	else
		ft_adaptive_algorithm(context);
}
