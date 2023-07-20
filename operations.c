#include "pushswap.h"

void sa(stack *s)
{
    if (s->size < 2)
        return;
    node *top = s->top;
    node *second = s->top->prev;

    top->prev = second->prev;
    second->prev->next = top;

    second->next = top->next;
    top->next->prev = second;

    top->next = second;
    second->prev = top;

    s->top = second;

    // 스택의 맨 아래 노드인 경우, bottom도 변경
    if (s->size == 2)
        s->bottom = top;
}

void sb(stack *s)
{
    if (s->size < 2)
        return;

    node *top = s->top;
    node *second = s->top->prev;

    top->prev = second->prev;
    second->prev->next = top;

    second->next = top->next;
    top->next->prev = second;

    top->next = second;
    second->prev = top;

    s->top = second;

    // 스택의 맨 아래 노드인 경우, bottom도 변경
    if (s->size == 2)
        s->bottom = top;
}

void	pa(stack *b, stack *a)
{
	int	value;

	value = pop(b);
	if (value == -1)
		return ;
	insert(value, a);
}

void	pb(stack *a, stack *b)
{
	int	value;

	value = pop(a);
	if (value == -1)
		return ;
	insert(value, b);
}

void	ra(stack *a)
{
	if (a->size == 0)
		return ;
	a->top = a->top->prev;
	a->bottom = a->bottom->prev;
}

void	rb(stack *b)
{
	if (b->size <= 1)
		return ;
	b->top = b->top->prev;
	b->bottom = b->bottom->prev;
}

void	rra(stack *a)
{
	if (a->size == 0)
		return ;
	a->top = a->top->next;
	a->bottom = a->bottom->next;
}

void	rrb(stack *b)
{
	if (b->size <= 1)
		return ;
	b->top = b->top->next;
	b->bottom = b->bottom->next;
}

void	rr(stack *a, stack *b)
{
	ra(a);
	rb(b);
}

void	rrr(stack *a, stack *b)
{
	rra(a);
	rrb(b);
}
