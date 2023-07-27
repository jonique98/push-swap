/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:44:07 by sumjo             #+#    #+#             */
/*   Updated: 2023/07/27 23:35:00 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	realsort(sortinfo *sortinfo, sortsize *ss, stacks *stacks)
{
	int	i;
	int	len;

	i = -1;
	len = sortinfo->len;
	while (++i < sortinfo->len / 3)
	{
		ss->s1 = sortinfo->mergeSize[len - i - 1];
		ss->s2 = sortinfo->mergeSize[len - ((len / 3) + i + 1)];
		ss->s3 = sortinfo->mergeSize[i];
		ss->shape = sortinfo->triShape[i];
		if (ss->shape == 1)
			realuppersort(ss, stacks, ss->target, ss->src, sortinfo);
		else if (ss->shape == 0)
			reallowersort(ss, stacks, ss->target, ss->src, sortinfo);
	}
}

void	reallowersort(sortsize *ss, stacks *stacks, stack *t, stack *s, sortinfo *sortinfo)
{
	while (ss->s1 != 0 || ss->s2 != 0 || ss->s3 != 0)
	{
		if (ss->s1 != 0 && ((ss->s2 == 0 && ss->s3 == 0) || (MINS1)
				|| (ss->s2 == 0 && t->bottom->value < s->bottom->value)
				|| (ss->s3 == 0 && t->bottom->value < s->top->value)))
		{
			rreverse(ss->target, stacks);
			ss->s1--;
		}
		else if (ss->s2 != 0 && ((ss->s1 == 0 && ss->s3 == 0) || (MINS2)
				|| (ss->s3 == 0 && s->top->value < t->bottom->value)
				|| (ss->s1 == 0 && s->top->value < s->bottom->value)))
		{
			push(ss, stacks, sortinfo);
			ss->s2--;
		}
		else if (ss->s3 != 0 && ((ss->s1 == 0 && ss->s2 == 0) || (MINS3)
				|| (ss->s1 == 0 && s->bottom->value < s->top->value)
				|| (ss->s2 == 0 && s->bottom->value < t->bottom->value)))
		{
			rreverse(ss->src, stacks);
			push(ss, stacks, sortinfo);
			ss->s3--;
		}
	}
}

void	realuppersort(sortsize *ss, stacks *stacks, stack *t, stack *s, sortinfo *sortinfo)
{
	while (ss->s1 != 0 || ss->s2 != 0 || ss->s3 != 0)
	{
		if (ss->s1 != 0 && ((ss->s2 == 0 && ss->s3 == 0) || (MAXS1)
				|| (ss->s2 == 0 && t->bottom->value > s->bottom->value)
				|| (ss->s3 == 0 && t->bottom->value > s->top->value)))
		{
			rreverse(ss->target, stacks);
			ss->s1--;
		}
		else if (ss->s2 != 0 && ((ss->s1 == 0 && ss->s3 == 0) || (MAXS2)
				|| (ss->s3 == 0 && s->top->value > t->bottom->value)
				|| (ss->s1 == 0 && s->top->value > s->bottom->value)))
		{
			push(ss, stacks, sortinfo);
			ss->s2--;
		}
		else if (ss->s3 != 0 && ((ss->s1 == 0 && ss->s2 == 0) || (MAXS3)
				|| (ss->s1 == 0 && s->bottom->value > s->top->value)
				|| (ss->s2 == 0 && s->bottom->value > t->bottom->value)))
		{
			rreverse(ss->src, stacks);
			push(ss, stacks, sortinfo);
			ss->s3--;
		}
	}
}
