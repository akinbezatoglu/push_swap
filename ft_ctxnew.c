/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctxnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 22:41:22 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/10 10:00:21 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_context	*ft_ctxnew(void)
{
	t_context	*ctx;

	ctx = (t_context *)malloc(1 * sizeof(t_context));
	if (!ctx)
		return (NULL);
	ctx->disorder = 0.0f;
	ctx->bench = 0;
	ctx->strategy = ADAPTIVE;
	ctx->a = NULL;
	ctx->b = NULL;
	return (ctx);
}
