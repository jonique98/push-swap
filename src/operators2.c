/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:00:10 by josumin           #+#    #+#             */
/*   Updated: 2023/07/28 16:15:40 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rr(t_stack *a, t_stack *b, t_stacks *stacks)
{
	reverse(a, stacks);
	reverse(b, stacks);
}

void	rrr(t_stack *a, t_stack *b, t_stacks *stacks)
{
	rreverse(a, stacks);
	rreverse(b, stacks);
}
