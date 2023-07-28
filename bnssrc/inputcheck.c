/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:57:25 by josumin           #+#    #+#             */
/*   Updated: 2023/07/28 21:58:36 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	num_len(char *arr)
{
	int	i;
	int	cnt;
	int	flag;

	i = 0;
	cnt = 0;
	while (arr[i])
	{
		while (arr[i] && arr[i] == ' ')
			i++;
		if (isnum(arr[i]) || arr[i] == '+' || arr[i] == '-')
			flag = 1;
		while (arr[i] && (isnum(arr[i]) || arr[i] == '+' || arr[i] == '-'))
			i++;
		if (flag == 1)
		{
			cnt++;
			flag = 0;
		}
	}
	return (cnt);
}

int	check(char **av, t_stacks *stacks)
{
	int			i;
	char		*arr;
	long		*num;

	num = 0;
	i = 0;
	arr = 0;
	while (av[++i])
	{
		arr = ft_strjoin_check(arr, av[i], 0, 0);
		if (!arr)
			return (ft_free(arr, 0));
	}
	if (!num_check(arr))
		return (ft_free(arr, 0));
	num = malloc(sizeof(long) * num_len(arr));
	if (!num || !duplicate_check(arr, num))
		return (ft_free(arr, num));
	if (!intsert_int_node(num, arr, stacks))
		return (ft_free(arr, num));
	ft_free(arr, num);
	return (1);
}

int	intsert_int_node(long *num, char *arr, t_stacks *stacks)
{
	int	i;

	i = -1;
	while (++i < num_len(arr))
	{
		if (insertfirst(num[i], stacks->a) == 0)
			free_all_error(stacks, 0, 0);
	}
	return (1);
}
