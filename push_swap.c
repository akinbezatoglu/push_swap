/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 17:18:42 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/14 14:27:04 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_total_ops(t_context *ctx)
{
	int	total;

	total = 0;
	total += ctx->sa;
	total += ctx->sb;
	total += ctx->ss;
	total += ctx->pa;
	total += ctx->pb;
	total += ctx->ra;
	total += ctx->rb;
	total += ctx->rr;
	total += ctx->rra;
	total += ctx->rrb;
	total += ctx->rrr;
	return (total);
}

static void	print_strategy(t_context *ctx)
{
	if (ctx->strategy == ADAPTIVE && ctx->disorder < 0.2f)
		ft_printf("[bench] strategy: Adaptive / O(n^2)\n");
	else if (ctx->strategy == ADAPTIVE && ctx->disorder < 0.5f)
		ft_printf("[bench] strategy: Adaptive / O(n√n)\n");
	else if (ctx->strategy == ADAPTIVE)
		ft_printf("[bench] strategy: Adaptive / O(nlogn)\n");
	else if (ctx->strategy == SIMPLE)
		ft_printf("[bench] strategy: Simple / O(n^2)\n");
	else if (ctx->strategy == MEDIUM)
		ft_printf("[bench] strategy: Medium / O(n√n)\n");
	else if (ctx->strategy == COMPLEX)
		ft_printf("[bench] strategy: Complex / O(nlogn)\n");
}

static void	ft_benchmark(t_context *ctx)
{
	int	whole;
	int	decimal;

	whole = (int)ctx->disorder;
	decimal = (int)((ctx->disorder - whole) * 100);
	ft_printf("[bench] disorder: %d.%02d%%\n", whole, decimal);
	print_strategy(ctx);
	ft_printf("[bench] total_ops: %d\n", ft_total_ops(ctx));
	ft_printf("[bench] sa: %d sb: %d ss: %d", ctx->sa, ctx->sb, ctx->ss);
	ft_printf(" pa: %d pb: %d\n", ctx->pa, ctx->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d", ctx->ra, ctx->rb, ctx->rr);
	ft_printf(" rra: %d rrb: %d rrr: %d\n", ctx->rra, ctx->rrb, ctx->rrr);
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
	if (ctx->bench)
	{
		ft_sort(&ctx, 0);
		ft_benchmark(ctx);
	}
	else
		ft_sort(&ctx, 1);
	ft_ctxclear(&ctx, free);
	return (0);
}
