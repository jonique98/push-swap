/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maketri.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:45:25 by josumin           #+#    #+#             */
/*   Updated: 2023/07/28 16:13:59 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	make_tri(t_sortinfo *sortinfo, t_stacks *stacks)
{
	int			i;
	int			len;
	t_sortsize	*ss;

	ss = 0;
	len = stacks->a->size;
	i = -1;
	ss = init_sortsize(ss, stacks, sortinfo, 2);
	if (sortinfo->len == 9 || sortinfo->len == 81 || sortinfo->len == 729)
	{
		while (++i < len)
			push(ss, stacks, sortinfo);
		ss = init_sortsize(ss, stacks, sortinfo, 1);
	}
	i = -1;
	while (++i < sortinfo->len)
	{
		ss->size = sortinfo->mergesize[i];
		ss->shape = sortinfo->trishape[i];
		sorting(stacks, ss, sortinfo);
	}
	free(ss);
}

void	sorting(t_stacks *stacks, t_sortsize *ss, t_sortinfo *sortinfo)
{
	if (ss->size < 3)
		sort2(ss, stacks, sortinfo, 1);
	else if (ss->size == 3)
		sort3(ss, stacks, sortinfo);
	else if (ss->size == 4)
		sort4(ss, stacks, sortinfo);
	else if (ss->size == 5)
		sort5 (ss, stacks, sortinfo);
	else if (ss->size == 6)
		sort6 (ss, stacks, sortinfo);
}
