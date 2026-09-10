/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 17:18:42 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/10 10:06:14 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print(t_context *ctx)
{
	t_list	*tmp;

	tmp = ctx->a;
	while (tmp)
	{
		printf("%d\n", *(int *)tmp->content);
		tmp = tmp->next;
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
	ft_print(ctx);
	ft_ctxclear(&ctx, free);
	return (0);
}
