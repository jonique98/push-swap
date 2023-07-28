/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 21:37:46 by sumjo             #+#    #+#             */
/*   Updated: 2023/07/28 23:34:20 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pushswap.h"

int	peek(t_node *n)
{
	return (n->v);
}

void	push_check(t_stack *src, t_stack *target, t_stacks *stacks)
{
	int	value;

	if (src->size == 0)
		return ;
	value = peek(src->t);
	pop(src);
	if (!insert(value, target))
		free_all_error(stacks, 0, 0);
}

void	swap_check(t_stack *s)
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
}

void	reverse_check(t_stack *a)
{
	if (a->size < 2)
		return ;
	a->t = a->t->prev;
	a->b = a->b->prev;
}

void	rreverse_check(t_stack *a)
{
	if (a->size < 2)
		return ;
	a->t = a->t->next;
	a->b = a->b->next;
}
