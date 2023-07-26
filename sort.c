#include "pushswap.h"

node	*max(node *a, node *b, node *c)
{
	node	*max;

	if (a != 0 && a->value > b->value)
		max = a;
	else
		max = b;
	if (max->value < c->value)
		return (c);
	else
		return (max);
}

node *min(node *a, node *b, node *c)
{
	node *min;

	if (a != 0 && b != 0 && a->value < b->value)
		min = a;
	else
		min = b;
	if (min->value > c->value)
		return (c);
	else
		return (min);
}

void	sort3(sortsize *ss, stacks *stacks, sortinfo *sortinfo)
{
	push(ss, stacks, sortinfo);
	reverse(ss->target, stacks);
	ss->size1 = 1;
	ss->size2 = 1;
	ss->size3 = 1;
	if (ss->shape == 1)
		realuppersort(ss, stacks, ss->target, ss->src, sortinfo);
	else if (ss->shape == 0)
		reallowersort(ss, stacks, ss->target, ss->src, sortinfo);
}

void	sort4(sortsize *ss, stacks *stacks, sortinfo *sortinfo)
{
	push(ss, stacks, sortinfo);
	reverse(ss->target, stacks);

	ss->size1 = 1;
	ss->size2 = 2;
	ss->size3 = 1;
	if (ss->shape == 1)
	{
		if (peek(ss->src->top) < peek(ss->src->top->prev))
			swap(ss->src, stacks);
		realuppersort(ss, stacks, ss->target, ss->src, sortinfo);
	}
	else if (ss->shape == 0)
	{
		if (peek(ss->src->top) > peek(ss->src->top->prev))
			swap(ss->src, stacks);
		reallowersort(ss, stacks, ss->target, ss->src, sortinfo);
	}
}

void	sort6(sortsize *ss, stacks *stacks, sortinfo *sortinfo)
{
	ss->size1 = 2;
	ss->size2 = 2;
	ss->size3 = 2;

		sort2(ss, stacks, sortinfo, 1);
		reverse(ss->target, stacks);
		reverse(ss->target, stacks);
		sort2(ss, stacks, sortinfo, 2);
		if(ss->shape == 1)
		{
			if (peek(ss->src->bottom) < peek(ss->src->bottom->next))
			{
				rreverse(ss->src, stacks);
				rreverse(ss->src, stacks);
				swap(ss->src, stacks);
				reverse(ss->src, stacks);
				reverse(ss->src, stacks);
			}
			realuppersort(ss, stacks, ss->target, ss->src, sortinfo);
		}
		else
		{
			if(peek(ss->src->bottom) > peek(ss->src->bottom->next))
			{
				rreverse(ss->src, stacks);
				rreverse(ss->src, stacks);
				swap(ss->src, stacks);
				reverse(ss->src, stacks);
				reverse(ss->src, stacks);
			}
			reallowersort(ss, stacks, ss->target, ss->src, sortinfo);
		}
}

void	sort5(sortsize *ss, stacks *stacks, sortinfo *sortinfo)
{  
	ss->size1 = 2;
	ss->size2 = 2;
	ss->size3 = 1;

	sort2(ss, stacks, sortinfo, 1);
	reverse(ss->target, stacks);
	reverse(ss->target, stacks);
	sort2(ss, stacks, sortinfo, 2);
	if (ss->shape == 1)
		realuppersort(ss, stacks, ss->target, ss->src, sortinfo);
	else
		reallowersort(ss, stacks, ss->target, ss->src, sortinfo);
}

void	sort2(sortsize *ss, stacks *stacks, sortinfo *sortinfo, int a)
{
	if (ss->shape == 1)
	{
		if (ss->src->top->value < ss->src->top->prev->value)
			swap(ss->src, stacks);
	}
	else if (ss->shape == 0)
	{
		if (ss->src->top->value > ss->src->top->prev->value)
			swap(ss->src, stacks);
	}
	if (a == 1)
	{
		push(ss, stacks, sortinfo);
		push(ss, stacks, sortinfo);
	}
}


