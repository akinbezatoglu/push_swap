/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 17:30:55 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/10 14:21:40 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
}	t_strategy;

typedef struct s_context
{
	float		disorder;
	int			bench;
	t_strategy	strategy;
	t_list		*a;
	t_list		*b;
}	t_context;

t_context	*ft_ctxnew(void);
void		ft_ctxclear(t_context **ctx, void (*del)(void *));
t_context	*ft_parser(char **argv);
float		ft_compute_disorder(t_list *a);
t_strategy	ft_strategy_determination(float disorder);

void		swap(t_list **lst);

#endif