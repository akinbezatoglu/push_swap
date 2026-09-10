/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 17:09:39 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/10 22:19:49 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_map_operations(char *op, t_context **ctx)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		sa(ctx, 0);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		sb(ctx, 0);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ss(ctx, 0);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		pa(ctx, 0);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		pb(ctx, 0);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ra(ctx, 0);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rb(ctx, 0);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		rr(ctx, 0);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		rra(ctx, 0);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		rrb(ctx, 0);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		rrr(ctx, 0);
	else
		return (0);
	return (1);
}

static char	*ft_read_stdin(void)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = (char *)malloc(5 * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(0, buffer, 4);
		if (bytes == -1 || bytes == 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
	}
	return (buffer);
}

static int	write_error(t_context **ctx)
{
	if (ctx)
		ft_ctxclear(ctx, free);
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_context	*ctx;
	char		*op;

	if (argc < 2)
		return (0);
	ctx = ft_parser(++argv);
	if (!ctx)
		return (write_error(NULL));
	while (1)
	{
		op = ft_read_stdin();
		if (!op)
			break ;
		if (ft_map_operations(op, &ctx) == 0)
		{
			free(op);
			return (write_error(&ctx));
		}
	}
	if (ft_compute_disorder(ctx->a) == 0.0f && ctx->b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_ctxclear(&ctx, free);
	return (0);
}
