#include "pushswap.h"

void	init_node(int value, node *node)
{
	node->value = value;
	node->next = 0;
	node->prev = 0;
}

int	insertFirst(int a, stack *s)
{
	node	*n;

	n = malloc(sizeof(node));
	if (!n)
		return (0);
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
	return (1);
}

int	insert(int a, stack *s)
{
	node	*n;

	n = malloc(sizeof(node));
	if (!n)
		return 0;
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
	return (1);
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
	if (s->size == 1)
	{
		temp->prev->prev = temp->prev;
		temp->prev->next = temp->next;
	}
	else if (s->size > 1)
	{
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
	}
	s->top = temp->prev;
	free(temp);
	return (value);
}