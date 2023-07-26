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

stacks	*init_stacks()
{
	stacks *st;

	st = malloc(sizeof(stacks));
	if (!st)
		error(0, 0, 0);
	st->a = init_stack();
	st->b = init_stack();
	if (!st->a || !st->b)
		free_all_error(st, 0, 0);
	st->operations = 0;
	return (st);
}

sortinfo	*init_sortinfo(stacks *stacks)
{
	sortinfo *si;

	si = malloc(sizeof(sortinfo));
	if (!si)
		free_all_error(stacks, 0, 0);
	si->len = 0;
	si->mergeSize = 0;
	si->triShape = 0;
	return (si);
}
