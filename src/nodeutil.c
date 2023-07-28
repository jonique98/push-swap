/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodeutil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:44:45 by josumin           #+#    #+#             */
/*   Updated: 2023/07/28 16:26:20 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_node(int value, t_node *node)
{
	node->v = value;
	node->next = 0;
	node->prev = 0;
}

int	insertfirst(int a, t_stack *s)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		return (0);
	init_node(a, n);
	if (s->size == 0)
	{
		s->t = n;
		s->b = n;
		s->size++;
	}
	else
	{
		s->b->prev = n;
		n->next = s->b;
		n->prev = s->t;
		s->t->next = n;
		s->b = n;
		s->size++;
	}
	return (1);
}

int	insert(int a, t_stack *s)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		return (0);
	init_node(a, n);
	if (s->size == 0)
	{
		s->t = n;
		s->b = n;
		s->size++;
	}
	else
	{
		s->t->next = n;
		n->prev = s->t;
		n->next = s->b;
		s->b->prev = n;
		s->t = n;
		s->size++;
	}
	return (1);
}

void	pop(t_stack *s)
{
	t_node	*temp;

	if (s->size == 0)
		return ;
	temp = s->t;
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
	s->t = temp->prev;
	free(temp);
}
