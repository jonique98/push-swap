/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:44:07 by sumjo             #+#    #+#             */
/*   Updated: 2023/07/28 16:53:32 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	realsort(t_sortinfo *sortinfo, t_sortsize *ss, t_stacks *stacks)
{
	int	i;
	int	len;

	i = -1;
	len = sortinfo->len;
	while (++i < sortinfo->len / 3)
	{
		ss->s1 = sortinfo->mergesize[len - i - 1];
		ss->s2 = sortinfo->mergesize[len - ((len / 3) + i + 1)];
		ss->s3 = sortinfo->mergesize[i];
		ss->shape = sortinfo->trishape[i];
		if (ss->shape == 1)
			realuppersort(ss, stacks, sortinfo);
		else if (ss->shape == 0)
			reallowersort(ss, stacks, sortinfo);
	}
}

void	reallowersort(t_sortsize *ss, t_stacks *stacks, t_sortinfo *sortinfo)
{
	while (ss->s1 != 0 || ss->s2 != 0 || ss->s3 != 0)
	{
		if (ss->s1 != 0 && ((ss->s2 == 0 && ss->s3 == 0)
				|| (min(ss->target->b, ss->src->t, ss->src->b) == ss->target->b)
				|| (ss->s2 == 0 && ss->target->b->v < ss->src->b->v)
				|| (ss->s3 == 0 && ss->target->b->v < ss->src->t->v)))
			rreverse_target_s1(ss, stacks);
		else if (ss->s2 != 0 && ((ss->s1 == 0 && ss->s3 == 0)
				|| (min(ss->target->b, ss->src->t, ss->src->b) == ss->src->t)
				|| (ss->s3 == 0 && ss->src->t->v < ss->target->b->v)
				|| (ss->s1 == 0 && ss->src->t->v < ss->src->b->v)))
			push_s2(ss, stacks, sortinfo);
		else if (ss->s3 != 0 && ((ss->s1 == 0 && ss->s2 == 0)
				|| (min(ss->target->b, ss->src->t, ss->src->b) == ss->src->b)
				|| (ss->s1 == 0 && ss->src->b->v < ss->src->t->v)
				|| (ss->s2 == 0 && ss->src->b->v < ss->target->b->v)))
			rreverse_src_push_s3(ss, stacks, sortinfo);
	}
}

void	realuppersort(t_sortsize *ss, t_stacks *stacks, t_sortinfo *sortinfo)
{
	while (ss->s1 != 0 || ss->s2 != 0 || ss->s3 != 0)
	{
		if (ss->s1 != 0 && ((ss->s2 == 0 && ss->s3 == 0)
				|| (max(ss->target->b, ss->src->t, ss->src->b) == ss->target->b)
				|| (ss->s2 == 0 && ss->target->b->v > ss->src->b->v)
				|| (ss->s3 == 0 && ss->target->b->v > ss->src->t->v)))
			rreverse_target_s1(ss, stacks);
		else if (ss->s2 != 0 && ((ss->s1 == 0 && ss->s3 == 0)
				|| (max(ss->target->b, ss->src->t, ss->src->b) == ss->src->t)
				|| (ss->s3 == 0 && ss->src->t->v > ss->target->b->v)
				|| (ss->s1 == 0 && ss->src->t->v > ss->src->b->v)))
			push_s2(ss, stacks, sortinfo);
		else if (ss->s3 != 0 && ((ss->s1 == 0 && ss->s2 == 0)
				|| (max(ss->target->b, ss->src->t, ss->src->b) == ss->src->b)
				|| (ss->s1 == 0 && ss->src->b->v > ss->src->t->v)
				|| (ss->s2 == 0 && ss->src->b->v > ss->target->b->v)))
			rreverse_src_push_s3(ss, stacks, sortinfo);
	}
}
