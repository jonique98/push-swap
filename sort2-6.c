/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2-6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:42:54 by josumin           #+#    #+#             */
/*   Updated: 2023/07/28 17:07:10 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort2(t_sortsize *ss, t_stacks *stacks, t_sortinfo *sortinfo, int a)
{
	if (ss->shape == 1)
	{
		if (ss->src->t->v < ss->src->t->prev->v)
			swap(ss->src, stacks);
	}
	else if (ss->shape == 0)
	{
		if (ss->src->t->v > ss->src->t->prev->v)
			swap(ss->src, stacks);
	}
	if (a == 1)
	{
		push(ss, stacks, sortinfo);
		push(ss, stacks, sortinfo);
	}
}

void	sort3(t_sortsize *ss, t_stacks *stacks, t_sortinfo *sortinfo)
{
	push(ss, stacks, sortinfo);
	reverse(ss->target, stacks);
	ss->s1 = 1;
	ss->s2 = 1;
	ss->s3 = 1;
	if (ss->shape == 1)
		realuppersort(ss, stacks, sortinfo);
	else if (ss->shape == 0)
		reallowersort(ss, stacks, sortinfo);
}

void	sort4(t_sortsize *ss, t_stacks *stacks, t_sortinfo *sortinfo)
{
	push(ss, stacks, sortinfo);
	reverse(ss->target, stacks);
	ss->s1 = 1;
	ss->s2 = 2;
	ss->s3 = 1;
	if (ss->shape == 1)
	{
		if (peek(ss->src->t) < peek(ss->src->t->prev))
			swap(ss->src, stacks);
		realuppersort(ss, stacks, sortinfo);
	}
	else if (ss->shape == 0)
	{
		if (peek(ss->src->t) > peek(ss->src->t->prev))
			swap(ss->src, stacks);
		reallowersort(ss, stacks, sortinfo);
	}
}


void	sort5(t_sortsize *ss, t_stacks *stacks, t_sortinfo *sortinfo)
{
	ss->s1 = 2;
	ss->s2 = 2;
	ss->s3 = 1;
	sort2(ss, stacks, sortinfo, 1);
	re(reverse, ss->target, stacks);
	sort2(ss, stacks, sortinfo, 2);
	if (ss->shape == 1)
		realuppersort(ss, stacks, sortinfo);
	else
		reallowersort(ss, stacks, sortinfo);

}
void	sort6(t_sortsize *ss, t_stacks *stacks, t_sortinfo *sortinfo)
{
	ss->s1 = 2;
	ss->s2 = 2;
	ss->s3 = 2;
	sort2(ss, stacks, sortinfo, 1);
	re(reverse, ss->target, stacks);
	sort2(ss, stacks, sortinfo, 2);
	sort2bottom(ss, stacks);
	if (ss->shape == 1)
		realuppersort(ss, stacks, sortinfo);
	else
		reallowersort(ss, stacks, sortinfo);
}
