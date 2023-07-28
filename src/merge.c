/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:33:29 by sumjo             #+#    #+#             */
/*   Updated: 2023/07/28 16:14:31 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*make_mergesize_arr(int *mergeSize, int *arr, int *len)
{
	int		i;
	int		j;
	int		*returnarr;

	i = 0;
	j = 0;
	returnarr = malloc (sizeof(int) * (*len + 3));
	if (!returnarr)
		return (0);
	while (i < *len)
	{
		returnarr[i] = mergeSize[i];
		i++;
	}
	while (j < 3)
	{
		returnarr[i] = arr[j];
		j++;
		i++;
	}
	*len = *len + 3;
	free(mergeSize);
	return (returnarr);
}

int	merge(int size, t_sortinfo *sortinfo, int *len, t_stacks *stacks)
{
	int	arr[3];

	arr[0] = size / 3;
	arr[1] = (size - arr[0]) / 2;
	arr[2] = size - arr[0] - arr[1];
	if (arr[0] > 5)
		merge(arr[0], sortinfo, len, stacks);
	if (arr[0] > 5 && arr[1] > 5)
		merge(arr[1], sortinfo, len, stacks);
	if (arr[0] > 5 && arr[1] > 5 && arr[2] > 5)
		merge(arr[2], sortinfo, len, stacks);
	if (arr[0] <= 5 || arr[1] <= 5 || arr[2] <= 5)
	{
		sortinfo->mergesize = make_mergesize_arr(sortinfo->mergesize, arr, len);
		if (!sortinfo->mergesize)
			free_all(stacks, sortinfo, 0);
	}
	return (1);
}

int	mergesize_and_trishape(int size, t_sortinfo *sortinfo, t_stacks *stacks)
{
	int	len;
	int	trilen;

	len = 0;
	trilen = 0;
	merge(size, sortinfo, &len, stacks);
	sortinfo->len = len;
	while (trilen != len)
	{
		make_trishape(trilen, sortinfo, stacks);
		if (trilen == 0)
			trilen = 3;
		else
			trilen *= 3;
	}
	return (0);
}
