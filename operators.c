#include "pushswap.h"


void swap(stack *s, stacks *stacks)
{
	if (s->size < 2)
		return ;
	node *top = s->top;
	node *second = s->top->prev;
	top->prev = second->prev;
	second->prev->next = top;
	second->next = top->next;
	top->next->prev = second;
	top->next = second;
	second->prev = top;
	s->top = second;
	if (s->size == 2)
		s->bottom = top;
	stacks->cnt++;
}

void	push(stack *a, stack *b, stacks *stacks)
{
	int	value;

	value = pop(a);
	if (value == -1)
		return ;
	insert(value, b);
	stacks->cnt++;
}

void	reverse(stack *a, stacks *stacks)
{
	if (a->size < 2)
		return ;
	a->top = a->top->prev;
	a->bottom = a->bottom->prev;
	stacks->cnt++;
}

void	rreverse(stack *a, stacks *stacks)
{
	if (a->size < 2)
		return ;
	a->top = a->top->next;
	a->bottom = a->bottom->next;
	stacks->cnt++;
}

void	rr(stack *a, stack *b, stacks *stacks)
{
	reverse(a, stacks);
	reverse(b, stacks);
	stacks->cnt++;
}

void	rrr(stack *a, stack *b, stacks *stacks)
{
	rreverse(a, stacks);
	rreverse(b, stacks);
	stacks->cnt++;
}

int     peek(node *a)
{
	return a->value;
}
