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
		if (isNum(arr[i]) || arr[i] == '+' || arr[i] == '-')
			flag = 1;
		while (arr[i] && (isNum(arr[i]) || arr[i] == '+' || arr[i] == '-'))
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
	long		*num;

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
	num = malloc(sizeof(long) * num_len(arr));
	if (!num || !duplicate_check(arr, num))
		return (ft_free(arr, num));
	if (!intsert_int_node(num, arr, stacks))
		return (ft_free(arr, num));
	ft_free(arr, num);
	return (1);
}

int intsert_int_node(long *num, char *arr, stacks *stacks)
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

long	makeNum(char **arr)
{
	long	n;

	n = 0;
	while (*(*arr) && isNum(*(*arr)))
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
		num[++i] = makeNum(&arr) * minus;
		if (num[i] > 2147483647 || num[i] < -2147483648)
			return (0);
		if (is_duplicate(num[i], num, i))
			return (0);
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