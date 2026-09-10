/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 17:18:42 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/10 16:08:39 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print(t_context *ctx)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = ctx->a;
	stack_b = ctx->b;
	while (stack_a)
	{
		printf("Stack A:\n");
		printf("%d\n", *(int *)stack_a->content);
		stack_a = stack_a->next;
	}
	while (stack_b)
	{
		printf("Stack B:\n");
		printf("%d\n", *(int *)stack_b->content);
		stack_b = stack_b->next;
	}
	printf("bench:[%d]\n", ctx->bench);
	printf("strategy:[%u]\n", ctx->strategy);
	printf("disorder:[%.2f]\n", ctx->disorder);
}

static int	write_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_context	*ctx;

	if (argc < 2)
		return (write_error());
	argv++;
	ctx = ft_parser(argv);
	if (!ctx)
		return (write_error());
	sa(&ctx);
	pb(&ctx);
	pb(&ctx);
	pb(&ctx);
	ra(&ctx);
	rrb(&ctx);
	ft_print(ctx);
	ft_ctxclear(&ctx, free);
	return (0);
}
