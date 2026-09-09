/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctxclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 23:18:41 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/09 23:49:52 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ctxclear(t_context **ctx, void (*del)(void *))
{
	t_context	*current_ctx;

	if (!ctx || !*ctx || !del)
		return ;
	current_ctx = *ctx;
	ft_lstclear(&current_ctx->a, del);
	ft_lstclear(&current_ctx->b, del);
	free(current_ctx);
	*ctx = NULL;
}
