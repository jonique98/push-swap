/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:47:54 by sumjo             #+#    #+#             */
/*   Updated: 2023/07/27 23:35:55 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	hardsort4(sortsize *ss, stacks *stacks, sortinfo *sortinfo)
{
	ss->s1 = 2;
	ss->s2 = 1;
	ss->s3 = 1;
	if (peek(ss->target->bottom) < peek(ss->target->bottom->next))
		swap(ss->target, stacks);
	realuppersort(ss, stacks, ss->target, ss->src, sortinfo);
}

void	hardsort5(sortsize *ss, stacks *stacks, sortinfo *sortinfo)
{
	ss->s1 = 2;
	ss->s2 = 2;
	ss->s3 = 1;
	if (peek(ss->target->bottom) < peek(ss->target->bottom->next))
		swap(ss->target, stacks);
	if (peek(ss->src->top) < peek(ss->src->top->prev))
		swap(ss->src, stacks);
	realuppersort(ss, stacks, ss->target, ss->src, sortinfo);
}

void hardsort3(stacks *stacks, node *node)
{
	if (peek(node) > peek(node->prev) && peek(node->prev) > peek(node->prev->prev))
	{
		swap(stacks->a, stacks);
		reverse(stacks->a, stacks);
		reverse(stacks->a, stacks);
	}
	else if (peek(node) > peek(node->prev->prev) && peek(node->prev) < peek(node->prev->prev))
		reverse(stacks->a, stacks);
	else if (peek(node->prev) > peek(node) && peek(node) > peek(node->prev->prev))
	{
		reverse(stacks->a, stacks);
		reverse(stacks->a, stacks);
	}
	else if ((peek(node->prev) > peek(node->prev->prev) && peek(node) < peek(node->prev->prev)))
	{
		rreverse(stacks->a, stacks);
		swap(stacks->a, stacks);
		reverse(stacks->a, stacks);
	}
	else if (peek(node->prev->prev) > peek(node) && peek(node->prev) < peek(node))
		swap(stacks->a, stacks);
}

void	hardsorting(stacks *stacks, sortinfo *sortinfo)
{
	sortsize	*ss;

	ss = 0;
	if (stacks->a->size == 2)
	{
		if (peek(stacks->a->top) > peek(stacks->a->top->prev))
			swap(stacks->a, stacks);
	}
	else if (stacks->a->size == 3)
		hardsort3(stacks, stacks->a->top);
	else
	{
		ss = init_sortsize(ss, stacks, sortinfo, 2);
		while (stacks->a->size > 2)
			push(ss, stacks, sortinfo);
		ss = init_sortsize(ss, stacks, sortinfo, 1);
		if (stacks->b->size == 2)
			hardsort4(ss, stacks, sortinfo);
		else if (stacks->b->size == 3)
			hardsort5(ss, stacks, sortinfo);
	}
	free(ss);
}
