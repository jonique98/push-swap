/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:47:54 by sumjo             #+#    #+#             */
/*   Updated: 2023/07/28 16:28:28 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	hardsort4(t_sortsize *ss, t_stacks *stacks, t_sortinfo *sortinfo)
{
	ss->s1 = 2;
	ss->s2 = 1;
	ss->s3 = 1;
	if (peek(ss->target->b) < peek(ss->target->b->next))
		swap(ss->target, stacks);
	realuppersort(ss, stacks, sortinfo);
}

void	hardsort5(t_sortsize *ss, t_stacks *stacks, t_sortinfo *sortinfo)
{
	ss->s1 = 2;
	ss->s2 = 2;
	ss->s3 = 1;
	if (peek(ss->target->b) < peek(ss->target->b->next))
		swap(ss->target, stacks);
	if (peek(ss->src->t) < peek(ss->src->t->prev))
		swap(ss->src, stacks);
	realuppersort(ss, stacks, sortinfo);
}

void	hardsort3(t_stacks *stacks, t_node *node)
{
	if (peek(node) > peek(node->prev)
		&& peek(node->prev) > peek(node->prev->prev))
	{
		swap(stacks->a, stacks);
		re(reverse, stacks->a, stacks);
	}
	else if (peek(node) > peek(node->prev->prev)
		&& peek(node->prev) < peek(node->prev->prev))
		reverse(stacks->a, stacks);
	else if (peek(node->prev) > peek(node)
		&& peek(node) > peek(node->prev->prev))
		re(reverse, stacks->a, stacks);
	else if ((peek(node->prev) > peek(node->prev->prev)
			&& peek(node) < peek(node->prev->prev)))
	{
		rreverse(stacks->a, stacks);
		swap(stacks->a, stacks);
		reverse(stacks->a, stacks);
	}
	else if (peek(node->prev->prev) > peek(node)
		&& peek(node->prev) < peek(node))
		swap(stacks->a, stacks);
}

void	hardsorting(t_stacks *stacks, t_sortinfo *sortinfo)
{
	t_sortsize	*ss;

	ss = 0;
	if (stacks->a->size == 2)
	{
		if (peek(stacks->a->t) > peek(stacks->a->t->prev))
			swap(stacks->a, stacks);
	}
	else if (stacks->a->size == 3)
		hardsort3(stacks, stacks->a->t);
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
