#include "pushswap.h"

void	realsort(sortinfo *sortinfo, sortsize *ss, stacks *stacks)
{
	int i;

	i = -1;
	while (++i < sortinfo->len / 3)
	{
		ss->size1 = sortinfo->mergeSize[sortinfo->len - i - 1];
		ss->size2 = sortinfo->mergeSize[sortinfo->len - ((sortinfo->len / 3) + i + 1)];
		ss->size3 = sortinfo->mergeSize[i];
		ss->shape = sortinfo->triShape[i];
		if (ss->shape == 1)
			realuppersort(ss, stacks, ss->target, ss->src);
		else if(ss->shape == 0)
			reallowersort(ss, stacks, ss->target, ss->src);
	}
}

void	reallowersort(sortsize *ss, stacks *stacks, stack *target, stack *src)
{
	while (ss->size1 != 0 || ss->size2 != 0 || ss->size3 != 0)
	{
		if (ss->size1 != 0 && ((min(target->bottom, src->top, src->bottom) == target->bottom)
				|| (ss->size3 != 0 && ss->size2 == 0 && target->bottom->value < src->bottom->value)
				|| (ss->size2 != 0 && ss->size3 == 0 && target->bottom->value < src->top->value) || (ss->size2 == 0 && ss->size3 == 0)))
		{
			rreverse(ss->target, stacks);
			ss->size1--;
		}
		else if (ss->size2 != 0 && ((min(target->bottom, src->top, src->bottom) == src->top)
				|| (ss->size1 != 0 && ss->size3 == 0 && src->top->value < target->bottom->value)
		 		|| (ss->size3 != 0 && ss->size1 == 0 && src->top->value < src->bottom->value) || (ss->size1 == 0 && ss->size3 == 0)))
		{
			push(ss->src, ss->target, stacks);
			ss->size2--;
		}
		else if (ss->size3 != 0 && ((ss->size1 == 0 && ss->size2 == 0) ||
				(min(target->bottom, src->top, src->bottom) == src->bottom) 
				|| (ss->size1 == 0 && src->bottom->value < src->top->value) 
				|| (ss->size2 == 0 && src->bottom->value < target->bottom->value)))
		{
			rreverse(ss->src, stacks);
			push(ss->src, ss->target, stacks);
			ss->size3--;
		}
	}
}

void realuppersort(sortsize *ss, stacks *stacks, stack *target, stack *src)
{
	while(ss->size1 != 0 || ss->size2 != 0 || ss->size3 != 0)
	{
		if(ss->size1 != 0 && ((ss->size2 !=0 && ss->size3 != 0 && max(target->bottom, src->top, src->bottom) == target->bottom) 
		|| (ss->size3 != 0 && ss->size2 == 0 && target->bottom->value > src->bottom->value) 
		|| (ss->size2 != 0 && ss->size3 == 0 && target->bottom->value > src->top->value) || (ss->size2 == 0 && ss->size3 == 0)))
		{
			rreverse(ss->target, stacks);
			ss->size1--;
		}
		else if(ss->size2 != 0 && ((ss->size1 !=0 && ss->size3 != 0 && max(target->bottom, src->top, src->bottom) == src->top) 
		|| (ss->size1 != 0 && ss->size3 == 0 && src->top->value > target->bottom->value)
		 || (ss->size3 != 0 && ss->size1 == 0 && src->top->value > src->bottom->value) || (ss->size1 == 0 && ss->size3 == 0)))
		{
			push(ss->src, ss->target, stacks);
			ss->size2--;
		}
		else if(ss->size3 != 0 && ((ss->size1 !=0 && ss->size2 != 0 && max(target->bottom, src->top, src->bottom) == src->bottom) 
		|| (ss->size2 != 0 && ss->size1 == 0 && src->bottom->value > src->top->value) 
		|| (ss->size1 != 0 && ss->size2 == 0 && src->bottom->value > target->bottom->value) || (ss->size1 == 0 && ss->size2 == 0)))
		{
			rreverse(ss->src, stacks);
			push(ss->src, ss->target, stacks);
			ss->size3--;
		}
	}
}