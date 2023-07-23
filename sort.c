#include "pushswap.h"

node *max(node *a, node *b, node *c)
{
	node *max;

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

	if (a != 0 && a->value < b->value)
		min = a;
	else
		min = b;
	if (min->value > c->value)
		return (c);
	else
		return (min);
}

void	sort3(sortsize *ss, int shape, stacks *stacks)
{
	push(ss->src, ss->target, stacks);
	reverse(ss->target, stacks);
	ss->size1 = 1;
	ss->size2 = 1;
	ss->size3 = 1;
	if (shape == 1)
		realuppersort(ss, stacks, ss->target, ss->src);
	else if (shape == 0)
		reallowersort(ss, stacks, ss->target, ss->src);
}

void	sort4(sortsize *ss, int shape, stacks *stacks)
{
	push(ss->src, ss->target, stacks);
	reverse(ss->target, stacks);

	ss->size1 = 1;
	ss->size2 = 2;
	ss->size3 = 1;
	if (shape == 1)
	{
		if (peek(ss->src->top) < peek(ss->src->top->prev))
			swap(ss->src, stacks);
		realuppersort(ss, stacks, ss->target, ss->src);
	}
	else if (shape == 0)
	{
		if (peek(ss->src->top) > peek(ss->src->top->prev))
			swap(ss->src, stacks);
		reallowersort(ss, stacks, ss->target, ss->src);
	}
}

void	sort5(sortsize *ss, int shape, stacks *stacks)
{   
	ss->size1 = 2;
	ss->size2 = 2;
	ss->size3 = 1;
	if (shape == 1)
	{
		if (peek(ss->src->top) < peek(ss->src->top->prev))
			swap(ss->src, stacks);
		push(ss->src, ss->target, stacks);
		push(ss->src, ss->target, stacks);
		reverse(ss->target, stacks);
		reverse(ss->target, stacks);
		if (peek(ss->src->top) < peek(ss->src->top->prev))
			swap(ss->src, stacks);
		realuppersort(ss, stacks, ss->target, ss->src);
	}
	else if (shape == 0)
	{
		if (peek(ss->src->top) > peek(ss->src->top->prev))
			swap(ss->src, stacks);
		push(ss->src, ss->target, stacks);
		push(ss->src, ss->target, stacks);
		reverse(ss->target, stacks);
		reverse(ss->target, stacks);
		if (peek(ss->src->top) > peek(ss->src->top->prev))
			swap(ss->src, stacks);
		reallowersort(ss, stacks, ss->target, ss->src);
	}
}

void	sort2(sortsize *ss, int shape, stacks *stacks)
{
	if (shape == 1)
	{
		if (ss->src->top->value < ss->src->top->prev->value)
			swap(ss->src, stacks);
	}
	else if (shape == 0)
	{
		if (ss->src->top->value > ss->src->top->prev->value)
			swap(ss->src, stacks);
	}
	push(ss->src, ss->target, stacks);
	push(ss->src, ss->target, stacks);
}
