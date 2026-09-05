/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 17:18:42 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/05 20:18:04 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_parse_bench_flag(char *arg, t_config *config)
{
	if (ft_strncmp(arg, "--bench", 7) == 0)
		config->bench = 1;
	else
	{
		config->bench = 0;
		return (0);
	}
	return (1);
}

static int	ft_parse_strategy_flag(char *arg, t_config *config)
{
	if (ft_strncmp(arg, "--simple", 8) == 0)
		config->strategy = SIMPLE;
	else if (ft_strncmp(arg, "--medium", 8) == 0)
		config->strategy = MEDIUM;
	else if (ft_strncmp(arg, "--complex", 9) == 0)
		config->strategy = COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 10) == 0)
		config->strategy = ADAPTIVE;
	else
	{
		config->strategy = ADAPTIVE;
		return (0);
	}
	return (1);
}

static void	ft_print(t_stack *stack, t_config config)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
	printf("bench:[%d]\n", config.bench);
	printf("strategy:[%u]\n", config.strategy);
}

int	main(int argc, char **argv)
{
	t_config	config;
	t_stack		*stack;

	if (argc < 2)
		return (0);
	argv++;
	if (ft_parse_bench_flag(*argv, &config))
		argv++;
	if (ft_parse_strategy_flag(*argv, &config))
		argv++;
	if (!ft_isnumber(*argv))
		return (0);
	stack = ft_stacknew(*argv++);
	while (*argv)
	{
		if (!ft_isnumber(*argv))
		{
			ft_stackclear(&stack);
			return (0);
		}
		ft_stackadd_back(&stack, ft_stacknew(*argv));
		argv++;
	}
	ft_print(stack, config);
	ft_stackclear(&stack);
}
