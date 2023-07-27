#include "pushswap.h"


void	swap(stack *s, stacks *stacks)
{
	node	*top;
	node	*second;

	if (s->size < 2)
		return ;
	top = s->top;
	second = s->top->prev;
	top->prev = second->prev;
	second->prev->next = top;
	second->next = top->next;
	top->next->prev = second;
	top->next = second;
	second->prev = top;
	s->top = second;
	if (s->size == 2)
		s->bottom = top;
	if (s == stacks->a)
		stacks->operations = ft_strjoin_op(stacks->operations, "sa\n", 0, 0);
	else
		stacks->operations = ft_strjoin_op(stacks->operations, "sb\n", 0, 0);
}

void	push(sortsize *ss, stacks *stacks, sortinfo *sortinfo)
{
	int	value;

	value = peek(ss->src->top);
	pop(ss->src);
	if (!insert(value, ss->target))
		free_all_error(stacks, sortinfo, ss);
	if (ss->target == stacks->a)
		stacks->operations = ft_strjoin_op(stacks->operations, "pa\n", 0, 0);
	else
		stacks->operations = ft_strjoin_op(stacks->operations, "pb\n", 0, 0);
}

void	reverse(stack *a, stacks *stacks)
{
	if (a->size < 2)
		return ;
	a->top = a->top->prev;
	a->bottom = a->bottom->prev;
	if (a == stacks->a)
		stacks->operations = ft_strjoin_op(stacks->operations, "ra\n", 0, 0);
	else
		stacks->operations = ft_strjoin_op(stacks->operations, "rb\n", 0, 0);
}

void	rreverse(stack *a, stacks *stacks)
{
	if (a->size < 2)
		return ;
	a->top = a->top->next;
	a->bottom = a->bottom->next;
	if (a == stacks->a)
		stacks->operations = ft_strjoin_op(stacks->operations, "rra\n", 0, 0);
	else
		stacks->operations = ft_strjoin_op(stacks->operations, "rrb\n", 0, 0);
}

void	rr(stack *a, stack *b, stacks *stacks)
{
	reverse(a, stacks);
	reverse(b, stacks);
}

void	rrr(stack *a, stack *b, stacks *stacks)
{
	rreverse(a, stacks);
	rreverse(b, stacks);
}

int     peek(node *a)
{
	return a->value;
}
