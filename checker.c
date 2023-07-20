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

stacks *init_stacks()
{
	stacks *st;
	st = malloc(sizeof(stacks));
	st->a = init_stack();
	st->b = init_stack();

	return st;
}

sortinfo *init_sortinfo()
{
	sortinfo *si;

	si = malloc(sizeof(sortinfo));
	si->len = 0;
	si->mergeSize = 0;
	si->triShape = 0;

	return (si);
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

int	peekTop(node *n)
{
	int		value;

	if (!n)
		return (-1);
	value = n->value;
	return (value);
}




int main(int ac, char **av){
	stacks *st;
	sortinfo *si;

	si = init_sortinfo();
	st = init_stacks();
		
	if ((!st->a || !st->b) || ac < 2)
		exit(0);
	if(!check(av, st))
	{
		printf("error\n");
		exit(0);
	}
	// for(int i = 0; i < 9; i++){
	// 	int a = pop(st->a) + '0';
	// 	write(1, &a, 2);
	// }
	mergeSize_and_triShape(st->a->size, si);
	make_tri(si, st);
	move(si, st);
	while(st->b->size != 0){
		printf("%d", pop(st->b));
	}
	printf("\n");
	while(st->a->size != 0){
		printf("%d", pop(st->a));
	}
}
