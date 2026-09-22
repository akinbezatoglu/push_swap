/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 22:35:10 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/22 14:28:25 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_parse_bench_flag(char *arg, t_context *ctx)
{
	if (!arg)
		return (0);
	if (ft_strncmp(arg, "--bench", 8) == 0)
		ctx->bench = 1;
	else
		return (0);
	return (1);
}

static int	ft_parse_strategy_flag(char *arg, t_context *ctx)
{
	if (!arg)
		return (0);
	if (ft_strncmp(arg, "--simple", 9) == 0)
		ctx->strategy = SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		ctx->strategy = MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		ctx->strategy = COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		ctx->strategy = ADAPTIVE;
	else
		return (0);
	return (1);
}

t_context	*ft_parser(char **argv)
{
	t_context	*ctx;
	t_list		*stack_a;

	ctx = ft_ctxnew();
	if (!ctx)
		return (NULL);
	if (ft_parse_bench_flag(*argv, ctx))
		argv++;
	if (ft_parse_strategy_flag(*argv, ctx))
		argv++;
	stack_a = ft_parse_numbers(argv);
	if (!stack_a)
	{
		ft_ctxclear(&ctx, free);
		return (NULL);
	}
	ft_assign_indexes(stack_a);
	ctx->a = stack_a;
	ctx->disorder = ft_compute_disorder(stack_a);
	return (ctx);
}
