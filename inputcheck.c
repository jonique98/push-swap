#include "pushswap.h"

int num_len(char *arr)
{
	int i;
	int cnt;
	int flag;

	i = 0;
	cnt = 0;
	while (arr[i])
	{
		while (arr[i] && arr[i] == ' ')
			i++;
		if (isNum(arr[i]))
			flag = 1;
		while (arr[i] && isNum(arr[i]))
			i++;
		if (flag == 1)
		{
			cnt++;
			flag = 0;
		}
	}
	return (cnt);
}

int	check(char **av, stacks *stacks)
{
	int			i;
	char		*arr;
	long long	*num;

	num = 0;
	i = 0;
	arr = 0;
	while (av[++i])
	{
		arr = ft_strjoin(arr, av[i], 0, 0);
		if (!arr)
			return (ft_free(arr, 0));
	}
	if (!num_check(arr))
		return (ft_free(arr, 0));
	num = malloc(sizeof(long long) * num_len(arr));
	if (!num || !duplicate_check(arr, num))
		return (ft_free(arr, num));
	if (!intsert_int_node(num, arr, stacks))
		return (ft_free(arr, num));
	ft_free(arr, num);
	return (1);
}

int intsert_int_node(long long *num, char *arr, stacks *stacks)
{
	int i;

	i = -1;
	while (++i < num_len(arr))
	{
		if (insertFirst(num[i], stacks->a) == 0)
			free_all_error(stacks, 0, 0);
	}
	return (1);
}

long makeNum(char **arr)
{
	long long n;

	n = 0;
	while (*(*arr) && isNum(*(*arr)))
	{
		n = n * 10 + *(*arr) - '0';
		(*arr)++;
	}
	return (n);
}

int duplicate_check(char *arr, long long *num)
{
	int i;
	int j;

	i = -1;
	while (*arr)
	{
		j = -1;
		while (*arr && *arr == ' ')
			arr++;
		if (*arr == '\0')
			return (1);
		num[++i] = makeNum(&arr);
		if (num[i] > 2147483647)
			return (0);
		while (++j < i)
		{
			if (num[j] == num[i])
				return (0);
		}
	}
	return (1);
}

int ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}