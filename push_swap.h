/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 17:30:55 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/22 18:04:38 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
void		ft_assign_indexes(t_list *stack);
float		ft_compute_disorder(t_list *a);

void		ft_sort(t_context **ctx);
void		ft_sort_three(t_context **ctx);
void		ft_sort_five(t_context **ctx);
void		ft_sort_simple_algorithm(t_context **ctx);
void		ft_sort_medium_algorithm(t_context **ctx);
void		ft_sort_complex_algorithm(t_context **ctx);
void		ft_sort_adaptive_algorithm(t_context **ctx);

int			ft_is_sorted_chunk(t_list *stack, int size, int is_a);
int			ft_find_pivot(t_list *stack, int size);
void		ft_sort_small(t_context **ctx, int size, int is_a);
int			ft_partition_a_to_b(t_context **ctx, int size, int pivot);
void		ft_quicksort_a(t_context **ctx, int size);
void		ft_quicksort_b(t_context **ctx, int size);

int			ft_find_min_pos(t_list *stack);
int			ft_get_target_pos(t_list *stack, int target_idx);
void		ft_rotate_a_target_pos_to_first(t_context **ctx, int target_pos);
void		ft_rotate_b_target_pos_to_first(t_context **ctx, int target_pos);
void		ft_rotate_b_max_to_first(t_context **ctx);

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