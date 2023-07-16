#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"

stack *init_stack()
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

void	init_node(int value, node *node)
{
	node->value = value;
	node->next = 0;
	node->prev = 0;
}


void	insertstack(int a, stack *s)
{
	node	*n;

	n = malloc(sizeof(node));
	if (!n)
		return ;
	init_node(a, n);
	if (s->size == 0)
	{
		s->top = n;
		s->bottom = n;
		s->size++;
	}
	else
	{
		s->bottom->prev = n;
		n->next = s->bottom;
		n->prev = s->top;
		s->top->next = n;
		s->bottom = n;
		s->size++;
	}
}

int	pop(stack *s)
{
	int		value;
	node	*temp;

	if (s->size == 0)
		return (-1);
	temp = s->top;
	value = temp->value;
	s->size--;
	if(s->size == 1)
	{
		temp->next->prev = 0;
		temp->prev->next = 0;
	}
	else
	{
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
	}
	s->top = temp->prev;
	free(temp);
	return (value);
}

int	peek(stack *s)
{
	int		value;

	if (s->size == 0)
		return (-1);
	value = s->top->value;
	return (value);
}


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
	insertstack(value, a);
}

void	pb(stack *a, stack *b)
{
	int	value;

	value = pop(a);
	if (value == -1)
		return ;
	insertstack(value, b);
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
	if (b->size == 0)
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
	if (b->size == 0)
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

int main(int ac, char **av){
	stack	*a;
	stack	*b;

	a = init_stack();
	b = init_stack();
	if (!a || !b)
		exit(0);
	for (int i = 1; i < ac; i++)
		insertstack(atoi(av[i]), a);
	
}
