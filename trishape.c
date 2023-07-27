/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trishape.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:44:18 by sumjo             #+#    #+#             */
/*   Updated: 2023/07/27 21:44:19 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*make_trishape_arr(int *triShape, int len, int *one, int *zero)
{
	int	i;
	int	j;
	int	k;
	int	*returnarr;

	i = -1;
	j = 0;
	returnarr = malloc(sizeof(int) * (len * 3));
	if (!returnarr)
		return (0);
	while (++i < len)
	{
		k = 0;
		if (triShape[i] == 1)
		{
			while (k < 3)
				returnarr[j++] = one[k++];
		}
		else if (triShape[i] == 0)
		{
			while (k < 3)
				returnarr[j++] = zero[k++];
		}
	}
	free(triShape);
	return (returnarr);
}

int	*init_trishape(void)
{
	int	*arr;

	arr = malloc(sizeof(int) * 3);
	if (!arr)
		return (0);
	arr[0] = 1;
	arr[1] = 0;
	arr[2] = 0;
	return (arr);
}

void	make_triShape(int len, sortinfo *sortinfo, stacks *stacks)
{
	int one[3];
	int zero[3];

	one[0] = 1;
	one[1] = 0;
	one[2] = 0;
	zero[0] = 1;
	zero[1] = 1;
	zero[2] = 0;
	if (len == 0)
	{
		sortinfo->triShape = init_trishape();
		if (!sortinfo->triShape)
			free_all_error(stacks, sortinfo, 0);
		return ;
	}
	sortinfo->triShape = make_trishape_arr(sortinfo->triShape, len, one, zero);
	if (!sortinfo->triShape)
		free_all_error(stacks, sortinfo, 0);
}
