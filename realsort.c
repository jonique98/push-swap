#include "pushswap.h"

void	realsort(sortinfo *sortinfo, sortsize *ss, stacks *stacks)
{
	int i;
	int	len;

	i = -1;
	len = sortinfo->len;
	while (++i < sortinfo->len / 3)
	{
		ss->size1 = sortinfo->mergeSize[len - i - 1];
		ss->size2 = sortinfo->mergeSize[len - ((len / 3) + i + 1)];
		ss->size3 = sortinfo->mergeSize[i];
		ss->shape = sortinfo->triShape[i];
		if (ss->shape == 1)
			realuppersort(ss, stacks, ss->target, ss->src, sortinfo);
		else if(ss->shape == 0)
			reallowersort(ss, stacks, ss->target, ss->src, sortinfo);
	}
}

void	reallowersort(sortsize *ss, stacks *stacks, stack *t, stack *s, sortinfo *sortinfo)
{
	while (ss->size1 != 0 || ss->size2 != 0 || ss->size3 != 0)
	{
		if (ss->size1 != 0 && ((ss->size2 == 0 && ss->size3 == 0)
				|| (min(t->bottom, s->top, s->bottom) == t->bottom)
				|| (ss->size2 == 0 && t->bottom->value < s->bottom->value)
				|| (ss->size3 == 0 && t->bottom->value < s->top->value)))
		{
			rreverse(ss->target, stacks);
			ss->size1--;
		}
		else if (ss->size2 != 0 && ((ss->size1 == 0 && ss->size3 == 0) 
				|| (min(t->bottom, s->top, s->bottom) == s->top)
				|| (ss->size3 == 0 && s->top->value < t->bottom->value)
				|| (ss->size1 == 0 && s->top->value < s->bottom->value)))
		{
			push(ss, stacks, sortinfo);
			ss->size2--;
		}
		else if (ss->size3 != 0 && ((ss->size1 == 0 && ss->size2 == 0)
				|| (min(t->bottom, s->top, s->bottom) == s->bottom)
				|| (ss->size1 == 0 && s->bottom->value < s->top->value)
				|| (ss->size2 == 0 && s->bottom->value < t->bottom->value)))
		{
			rreverse(ss->src, stacks);
			push(ss, stacks, sortinfo);
			ss->size3--;
		}
	}
}

void realuppersort(sortsize *ss, stacks *stacks, stack *t, stack *s, sortinfo *sortinfo)
{
	while (ss->size1 != 0 || ss->size2 != 0 || ss->size3 != 0)
	{
		if (ss->size1 != 0 && ((ss->size2 == 0 && ss->size3 == 0)
				|| (max(t->bottom, s->top, s->bottom) == t->bottom)
				|| (ss->size2 == 0 && t->bottom->value > s->bottom->value)
				|| (ss->size3 == 0 && t->bottom->value > s->top->value)))
		{
			rreverse(ss->target, stacks);
			ss->size1--;
		}
		else if (ss->size2 != 0 && ((ss->size1 == 0 && ss->size3 == 0) 
				|| (max(t->bottom, s->top, s->bottom) == s->top)
				|| (ss->size3 == 0 && s->top->value > t->bottom->value)
				|| (ss->size1 == 0 && s->top->value > s->bottom->value)))
		{
			push(ss, stacks, sortinfo);
			ss->size2--;
		}
		else if (ss->size3 != 0 && ((ss->size1 == 0 && ss->size2 == 0)
				|| (max(t->bottom, s->top, s->bottom) == s->bottom)
				|| (ss->size1 == 0 && s->bottom->value > s->top->value)
				|| (ss->size2 == 0 && s->bottom->value > t->bottom->value)))
		{
			rreverse(ss->src, stacks);
			push(ss, stacks, sortinfo);
			ss->size3--;
		}
	}
}