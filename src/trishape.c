/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trishape.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:44:18 by sumjo             #+#    #+#             */
/*   Updated: 2023/07/28 16:44:28 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*make_trishape_arr(int *trishape, int len, int *one, int *zero)
{
	int	*returnarr;

	returnarr = inside_trishape(trishape, len, one, zero);
	if (!returnarr)
		return (0);
	free(trishape);
	return (returnarr);
}

int	*inside_trishape(int *trishape, int len, int *one, int *zero)
{
	int	i;
	int	j;
	int	k;
	int	*returnarr;

	returnarr = malloc(sizeof(int) * (len * 3));
	if (!returnarr)
		return (0);
	i = -1;
	j = 0;
	while (++i < len)
	{
		k = 0;
		if (trishape[i] == 1)
		{
			while (k < 3)
				returnarr[j++] = one[k++];
		}
		else if (trishape[i] == 0)
		{
			while (k < 3)
				returnarr[j++] = zero[k++];
		}
	}
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

void	make_trishape(int len, t_sortinfo *sortinfo, t_stacks *stacks)
{
	int	one[3];
	int	zero[3];

	one[0] = 1;
	one[1] = 0;
	one[2] = 0;
	zero[0] = 1;
	zero[1] = 1;
	zero[2] = 0;
	if (len == 0)
	{
		sortinfo->trishape = init_trishape();
		if (!sortinfo->trishape)
			free_all_error(stacks, sortinfo, 0);
		return ;
	}
	sortinfo->trishape = make_trishape_arr(sortinfo->trishape, len, one, zero);
	if (!sortinfo->trishape)
		free_all_error(stacks, sortinfo, 0);
}
