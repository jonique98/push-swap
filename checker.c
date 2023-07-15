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
		s->top->next = n;
		n->prev = s->top;
		n->next = s->bottom;
		s->bottom->prev = n;
		s->top = n;
		s->size++;
	}
}

int	pop(stack *s)
{
	int		value;
	node	*temp;

	temp = s->top;
	value = temp->value;
	if (s->size == 0)
		return (-1);
	temp->next->prev = temp->prev;
	temp->prev->next = temp->next;
	s->top = temp->prev;
	s->size--;
	free(temp);
	return (value);
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
	int		n;

	a = init_stack();
	b = init_stack();
	if (!a || !b)
		return (0);
	for (int i = 1; i < ac; i++)
		insertstack(n, atoi(av[i]));
	pb(a, b);
	pb(a, b);
	pb(a, b);
	pb(a, b);
	rr(a, b);
	rr(a, b);
	printf("%d", pop(a));
	printf("%d", pop(a));
	printf("%d", pop(a));
	printf("%d\n", pop(a));
	printf("%d", pop(b));
	printf("%d", pop(b));
	printf("%d", pop(b));
	printf("%d", pop(b));
}
