/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortutil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:49:56 by josumin           #+#    #+#             */
/*   Updated: 2023/07/28 17:07:01 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort2bottom(t_sortsize *ss, t_stacks *st)
{
	if (ss->shape == 1)
	{
		if (ss->src->b->v < ss->src->b->next->v)
		{
			re(rreverse, ss->src, st);
			swap(ss->src, st);
			re(reverse, ss->src, st);
		}
	}
	else if (ss->shape == 0)
	{
		if (ss->src->b->v > ss->src->b->next->v)
		{
			re(rreverse, ss->src, st);
			swap(ss->src, st);
			re(reverse, ss->src, st);
		}
	}
}

void	rreverse_target_s1(t_sortsize *ss, t_stacks *stacks)
{
	rreverse(ss->target, stacks);
	ss->s1--;
}

void	push_s2(t_sortsize *ss, t_stacks *stacks, t_sortinfo *sortinfo)
{
	push(ss, stacks, sortinfo);
	ss->s2--;
}

void	rreverse_src_push_s3(t_sortsize *ss, t_stacks *st, t_sortinfo *si)
{
	rreverse(ss->src, st);
	push(ss, st, si);
	ss->s3--;
}
