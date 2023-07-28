/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:52:13 by josumin           #+#    #+#             */
/*   Updated: 2023/07/28 16:32:04 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*max(t_node *a, t_node *b, t_node *c)
{
	t_node	*max;

	if (a != 0 && a->v > b->v)
		max = a;
	else
		max = b;
	if (max->v < c->v)
		return (c);
	else
		return (max);
}

t_node	*min(t_node *a, t_node *b, t_node *c)
{
	t_node	*min;

	if (a != 0 && b != 0 && a->v < b->v)
		min = a;
	else
		min = b;
	if (min->v > c->v)
		return (c);
	else
		return (min);
}

void	re(void (*f)(t_stack *s, t_stacks *st), t_stack *s, t_stacks *st)
{
	f(s, st);
	f(s, st);
}
