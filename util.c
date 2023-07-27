#include "pushswap.h"

int is_sorting(stack *a)
{
	int		i;
	node	*n;
	long	value;

	if (a->size == 0)
		return (0);

	i = 0;
	value = -2147483649;
	n = a->top;
	while (i < a->size)
	{
		if (n->value > value){
			value = n->value;
			n = n->prev;
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int ft_free(void *p1, void *p2)
{
	free(p1);
	free(p2);
	return 0;
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

int	isNum(char av)
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
		if (!isNum(arr[i]) && arr[i] != ' ' && arr[i] != '-' && arr[i] != '+')
			return (0);
		if (arr[i] == '-' || arr[i] == '+')
		{
			if (!isNum(arr[i + 1]))
				return (0);
		}
		i++;
	}
	return (1);
}
