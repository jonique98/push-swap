/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstructs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:36:58 by josumin           #+#    #+#             */
/*   Updated: 2023/07/28 16:13:13 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*init_stack(void)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (0);
	s->size = 0;
	s->t = 0;
	s->b = 0;
	return (s);
}	

t_stacks	*init_stacks(void)
{
	t_stacks	*st;

	st = malloc(sizeof(t_stacks));
	if (!st)
		error(0, 0, 0);
	st->a = init_stack();
	st->b = init_stack();
	if (!st->a || !st->b)
		free_all_error(st, 0, 0);
	st->operations = 0;
	return (st);
}

t_sortinfo	*init_sortinfo(t_stacks *stacks)
{
	t_sortinfo	*si;

	si = malloc(sizeof(t_sortinfo));
	if (!si)
		free_all_error(stacks, 0, 0);
	si->len = 0;
	si->mergesize = 0;
	si->trishape = 0;
	return (si);
}
