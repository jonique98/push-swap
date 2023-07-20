#include <stdio.h>
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


void	insertFirst(int a, stack *s)
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

void	insert(int a, stack *s)
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

	if(s->size == 0)
		return (-1);
	temp = s->top;
	value = temp->value;
	s->size--;
	if(s->size == 1)
	{
		temp->prev->prev = 0;
		temp->prev->next = 0;
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

int	peekTop(node *n)
{
	int		value;

	if (!n)
		return (-1);
	value = n->value;
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
	int		*mergeSize;
	int		*triShape;
	int		len;

	len = 0;
	a = init_stack();
	b = init_stack();
	if ((!a || !b) || ac < 2)
		exit(0);
	if(!check(av, a))
	{
		printf("error\n");
		exit(0);
	}
	mergeSize_and_triShape(&mergeSize, &triShape, &len, a->size);
	// for(int i = 0; i < len; i++){
		// printf("%d", mergeSize[i]);
	// }
	make_tri(mergeSize, triShape, len, a, b);
}
