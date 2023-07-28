/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:37:18 by josumin           #+#    #+#             */
/*   Updated: 2023/07/28 16:15:26 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_stack *s, t_stacks *stacks)
{
	t_node	*top;
	t_node	*second;

	if (s->size < 2)
		return ;
	top = s->t;
	second = s->t->prev;
	top->prev = second->prev;
	second->prev->next = top;
	second->next = top->next;
	top->next->prev = second;
	top->next = second;
	second->prev = top;
	s->t = second;
	if (s->size == 2)
		s->b = top;
	if (s == stacks->a)
		stacks->operations = ft_strjoin_op(stacks->operations, "sa\n", 0, 0);
	else
		stacks->operations = ft_strjoin_op(stacks->operations, "sb\n", 0, 0);
}

void	push(t_sortsize *ss, t_stacks *stacks, t_sortinfo *sortinfo)
{
	int	value;

	value = peek(ss->src->t);
	pop(ss->src);
	if (!insert(value, ss->target))
		free_all_error(stacks, sortinfo, ss);
	if (ss->target == stacks->a)
		stacks->operations = ft_strjoin_op(stacks->operations, "pa\n", 0, 0);
	else
		stacks->operations = ft_strjoin_op(stacks->operations, "pb\n", 0, 0);
}

void	reverse(t_stack *a, t_stacks *stacks)
{
	if (a->size < 2)
		return ;
	a->t = a->t->prev;
	a->b = a->b->prev;
	if (a == stacks->a)
		stacks->operations = ft_strjoin_op(stacks->operations, "ra\n", 0, 0);
	else
		stacks->operations = ft_strjoin_op(stacks->operations, "rb\n", 0, 0);
}

void	rreverse(t_stack *a, t_stacks *stacks)
{
	if (a->size < 2)
		return ;
	a->t = a->t->next;
	a->b = a->b->next;
	if (a == stacks->a)
		stacks->operations = ft_strjoin_op(stacks->operations, "rra\n", 0, 0);
	else
		stacks->operations = ft_strjoin_op(stacks->operations, "rrb\n", 0, 0);
}

int	peek(t_node *a)
{
	return (a->v);
}
