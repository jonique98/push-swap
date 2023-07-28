/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conquer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:40:56 by josumin           #+#    #+#             */
/*   Updated: 2023/07/28 16:45:54 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	move(t_sortinfo *sortinfo, t_stacks *stacks)
{
	int			size;
	int			i;
	t_sortsize	*ss;

	ss = 0;
	if (stacks->a->size == 0)
		ss = init_sortsize(ss, stacks, sortinfo, 1);
	else
		ss = init_sortsize(ss, stacks, sortinfo, 2);
	while (!is_sorting(stacks->a))
	{
		i = -1;
		size = 0;
		while (++i < sortinfo->len / 3)
			size += sortinfo->mergesize[sortinfo->len - i - 1];
		while (0 <= --size)
			push(ss, stacks, sortinfo);
		realsort(sortinfo, ss, stacks);
		sortinfo->trishape = resettrishape(stacks, sortinfo, ss);
		sortinfo->mergesize = resetmergesize(stacks, sortinfo, ss);
		sortinfo->len = sortinfo->len / 3;
		switchsortsize(ss, stacks);
	}
	free(ss);
}

int	*resetmergesize(t_stacks *stacks, t_sortinfo *sortinfo, t_sortsize *ss)
{
	int	*arr;
	int	i;
	int	len;

	len = sortinfo->len;
	arr = malloc(sizeof(int) * len / 3);
	if (!arr)
		free_all_error(stacks, sortinfo, ss);
	i = -1;
	while (++i < len / 3)
	{
		arr[i] = sortinfo->mergesize[i];
		arr[i] += sortinfo->mergesize[len - (len / 3) - i - 1];
		arr[i] += sortinfo->mergesize[len - i - 1];
	}
	free(sortinfo->mergesize);
	return (arr);
}

int	*resettrishape(t_stacks *stacks, t_sortinfo *sortinfo, t_sortsize *ss)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * sortinfo->len / 3);
	if (!arr)
		free_all_error(stacks, sortinfo, ss);
	while (i < sortinfo->len / 3)
	{
		arr[i] = sortinfo->trishape[i];
		i++;
	}
	free(sortinfo->trishape);
	return (arr);
}

t_sortsize	*init_sortsize(t_sortsize *p, t_stacks *st, t_sortinfo *si, int a)
{
	t_sortsize	*ss;

	ss = malloc(sizeof(t_sortsize));
	if (!ss)
		free_all_error(st, si, p);
	if (a == 1)
	{
		ss->target = st->a;
		ss->src = st->b;
	}
	else if (a == 2)
	{
		ss->target = st->b;
		ss->src = st->a;
	}
	free(p);
	return (ss);
}

void	switchsortsize(t_sortsize *ss, t_stacks *stacks)
{
	if (ss->target == stacks->a)
	{
		ss->target = stacks->b;
		ss->src = stacks->a;
	}
	else if (ss->target == stacks->b)
	{
		ss->target = stacks->a;
		ss->src = stacks->b;
	}
}
