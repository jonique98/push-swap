/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputcheck2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:59:23 by josumin           #+#    #+#             */
/*   Updated: 2023/07/28 16:31:26 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	makenum(char **arr)
{
	long	n;

	n = 0;
	while (*(*arr) && isnum(*(*arr)))
	{
		n = n * 10 + *(*arr) - '0';
		(*arr)++;
	}
	return (n);
}

int	is_duplicate(int n, long *num, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (n == num[j])
			return (1);
		j++;
	}
	return (0);
}

int	duplicate_check(char *arr, long *num)
{
	int	i;
	int	minus;

	i = -1;
	while (*arr)
	{
		minus = 1;
		while (*arr && (*arr == ' ' || *arr == '+' || *arr == '-'))
		{
			if (*arr == '-')
				minus = -1;
			arr++;
		}
		if (*arr == '\0')
			return (1);
		num[++i] = makenum(&arr) * minus;
		if (num[i] > 2147483647 || num[i] < -2147483648)
			return (0);
		if (is_duplicate(num[i], num, i))
			return (0);
	}
	return (1);
}
