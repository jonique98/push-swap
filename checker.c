/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:40:49 by josumin           #+#    #+#             */
/*   Updated: 2023/07/28 16:48:01 by josumin          ###   ########.fr       */
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
	free_stacks(st);
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
	free_stacks(stacks);
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

int	main(int ac, char **av)
{
	t_stacks		*st;
	t_sortinfo		*si;

	if (ac < 2)
		error(0, 0, 0);
	st = init_stacks();
	si = init_sortinfo(st);
	if (!check(av, st))
		free_all_error(st, si, 0);
	if (!is_sorting(st->a))
	{
		if (st->a->size < 6)
			hardsorting(st, si);
		else
		{
			mergesize_and_trishape(st->a->size, si, st);
			make_tri(si, st);
			move(si, st);
		}
	}
	write(1, st->operations, ft_strlen(st->operations));
	free_all(st, si, 0);
}
