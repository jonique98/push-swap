/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:49:13 by josumin           #+#    #+#             */
/*   Updated: 2023/07/28 16:34:55 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_free(void *p1, void *p2)
{
	free(p1);
	free(p2);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, int i, int j)
{
	char		*arr;

	if (s1 == 0 && s2 == 0)
		return (0);
	arr = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!arr)
	{
		free(s1);
		return (0);
	}
	while (s1 != 0 && s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	while (s2 != 0 && s2[j])
		arr[i++] = s2[j++];
	arr[i++] = ' ';
	arr[i] = '\0';
	free(s1);
	return (arr);
}

int	isnum(char av)
{
	if (av >= '0' && av <= '9')
		return (1);
	return (0);
}

int	num_check(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (!isnum(arr[i]) && arr[i] != ' ' && arr[i] != '-' && arr[i] != '+')
			return (0);
		if (arr[i] == '-' || arr[i] == '+')
		{
			if (!isnum(arr[i + 1]))
				return (0);
		}
		i++;
	}
	return (1);
}
