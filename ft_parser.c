/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 22:35:10 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/09 23:55:28 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_parse_bench_flag(char *arg, t_context *ctx)
{
	if (!arg)
		return (0);
	if (ft_strncmp(arg, "--bench", 7) == 0)
		ctx->bench = 1;
	else
		return (0);
	return (1);
}

static int	ft_parse_strategy_flag(char *arg, t_context *ctx)
{
	if (!arg)
		return (0);
	if (ft_strncmp(arg, "--simple", 8) == 0)
		ctx->strategy = SIMPLE;
	else if (ft_strncmp(arg, "--medium", 8) == 0)
		ctx->strategy = MEDIUM;
	else if (ft_strncmp(arg, "--complex", 9) == 0)
		ctx->strategy = COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 10) == 0)
		ctx->strategy = ADAPTIVE;
	else
		return (0);
	return (1);
}

static int	ft_isnumber(char *val)
{
	if (*val == '-' || *val == '+')
		val++;
	while (*val)
	{
		if (!ft_isdigit(*val))
			return (0);
		val++;
	}
	return (1);
}

static t_list	*ft_parse_numbers(char **argv)
{
	t_list	*stack;
	t_list	*new;
	int		*nbr;

	stack = NULL;
	while (*argv)
	{
		if (!ft_isnumber(*argv))
			return (NULL);
		nbr = malloc(sizeof(int));
		if (!nbr)
			return (NULL);
		*nbr = ft_atoi(*argv);
		new = ft_lstnew(nbr);
		if (!new)
			return (NULL);
		ft_lstadd_back(&stack, new);
		argv++;
	}
	return (stack);
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
	ctx->a = stack_a;
	return (ctx);
}
