#include "pushswap.h"

stack	*init_stack()
{
	stack	*s;

	s = malloc(sizeof(stack));
	if (!s)
		return (0);
	s->size = 0;
	s->top = 0;
	s->bottom = 0;
	return (s);
}	

stacks	*init_stacks(void)
{
	stacks *st;

	st = malloc(sizeof(stacks));
	st->a = init_stack();
	st->b = init_stack();
	st->cnt = 0;
	return (st);
}

sortinfo *init_sortinfo(void)
{
	sortinfo *si;

	si = malloc(sizeof(sortinfo));
	si->len = 0;
	si->mergeSize = 0;
	si->triShape = 0;
	return (si);
}
