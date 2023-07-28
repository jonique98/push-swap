/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:34:24 by josumin           #+#    #+#             */
/*   Updated: 2023/07/28 16:34:57 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorting(t_stack *a)
{
	int		i;
	t_node	*n;
	long	value;

	if (a->size == 0)
		return (0);
	i = 0;
	value = -2147483649;
	n = a->t;
	while (i < a->size)
	{
		if (n->v > value)
		{
			value = n->v;
			n = n->prev;
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_op(char *s1, char *s2, int i, int j)
{
	char		*arr;

	if (s1 == 0 && s2 == 0)
		return (0);
	arr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
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
	arr[i] = '\0';
	free(s1);
	return (arr);
}
