/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturkeri <yturkeri@student.42istanbul.com.tr>+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 17:30:55 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/20 20:49:59 by yturkeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

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
	int			print_ops;
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
}	t_context;

t_context	*ft_ctxnew(void);
void		ft_ctxclear(t_context **ctx, void (*del)(void *));
t_context	*ft_parser(char **argv);
t_list		*ft_parse_numbers(char **argv);
float		ft_compute_disorder(t_list *a);

void		ft_sort(t_context **ctx);
void		ft_sort_three(t_context **ctx);
void		ft_sort_five(t_context **ctx);
void		ft_sort_simple_algorithm(t_context **ctx);
void		ft_sort_medium_algorithm(t_context **ctx);
void		ft_sort_complex_algorithm(t_context **ctx);
void		ft_sort_adaptive_algorithm(t_context **ctx);

size_t		ft_find_max(t_list *stack);
size_t		ft_find_min(t_list *stack);
size_t		ft_find_one(t_list *stack, int val);
void		ft_rotate_one_first_b(t_context **ctx, size_t idx);
void		ft_rotate_max_first_b(t_context **ctx);

void		swap(t_list **lst);
void		push(t_list **src, t_list **dst);
void		rotate(t_list **lst);
void		reverse_rotate(t_list **lst);
void		sa(t_context **ctx);
void		sb(t_context **ctx);
void		ss(t_context **ctx);
void		pa(t_context **ctx);
void		pb(t_context **ctx);
void		ra(t_context **ctx);
void		rb(t_context **ctx);
void		rr(t_context **ctx);
void		rra(t_context **ctx);
void		rrb(t_context **ctx);
void		rrr(t_context **ctx);

#endif