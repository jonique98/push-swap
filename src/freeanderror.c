/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeanderror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:15:21 by sumjo             #+#    #+#             */
/*   Updated: 2023/07/28 23:24:50 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_all_error(t_stacks *st, t_sortinfo *si, t_sortsize *ss)
{
	if (si != 0)
	{
		free(si->mergesize);
		free(si->trishape);
		free(si);
	}
	if (ss != 0)
		free(ss);
	error(0, 0, 0);
	if (st != 0)
		free_stacks(st);
	else
		exit(0);
}

void	free_all(t_stacks *stacks, t_sortinfo *sortinfo, t_sortsize *sortsize)
{
	if (sortinfo != 0)
	{
		if (sortinfo->mergesize != 0)
			free(sortinfo->mergesize);
		if (sortinfo->trishape != 0)
			free(sortinfo->trishape);
		free(sortinfo);
	}
	if (sortsize != 0)
		free(sortsize);
	if (stacks != 0)
		free_stacks(stacks);
	else
		exit(0);
}

void	free_stacks(t_stacks *stacks)
{
	t_node	*temp;
	t_node	*freenode;
	int		i;

	i = -1;
	temp = stacks->a->t;
	while (++i < stacks->a->size)
	{
		freenode = temp;
		temp = temp->prev;
		free(freenode);
	}
	i = -1;
	temp = stacks->b->t;
	while (++i < stacks->b->size)
	{
		freenode = temp;
		temp = temp->prev;
		free(freenode);
	}
	free(stacks->a);
	free(stacks->b);
	free(stacks->operations);
	free(stacks);
	exit(0);
}

void	error(void *p1, void *p2, void *p3)
{
	free(p1);
	free(p2);
	free(p3);
	write(1, "error\n", 6);
}
