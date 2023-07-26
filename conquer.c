#include "pushswap.h"

void	move(sortinfo *sortinfo, stacks *stacks)
{
	int			size;
	int			i;
	sortsize	*ss;

	ss = 0;
	if (stacks->a->size == 0)
		ss = init_sortsize(ss, stacks, sortinfo ,1);
	else
		ss = init_sortsize(ss, stacks, sortinfo, 2);
	while (!is_sorting(stacks->a))
	{
		i = -1;
		size = 0;
		while (++i < sortinfo->len / 3)
			size += sortinfo->mergeSize[sortinfo->len - i - 1];
		while (0 <= --size)
			push(ss, stacks, sortinfo);
		realsort(sortinfo, ss, stacks);
		sortinfo->triShape = resettrishape(stacks, sortinfo, ss);
		sortinfo->mergeSize = resetmergesize(stacks, sortinfo, ss);
		sortinfo->len = sortinfo->len / 3;
		switchsortsize(ss, stacks);
	}
	free(ss);
}

int	*resetmergesize(stacks *stacks, sortinfo *sortinfo, sortsize *ss)
{
	int *arr;
	int	i;
	int	len;

	len = sortinfo->len;
	arr = malloc(sizeof(int) * len / 3);
	if (!arr)
		free_all_error(stacks, sortinfo, ss);
	i = -1;
	while (++i < len / 3)
	{
		arr[i] = sortinfo->mergeSize[i]; 
		arr[i] += sortinfo->mergeSize[len - (len / 3) - i - 1];
		arr[i] += sortinfo->mergeSize[len - i - 1];
	}
	free(sortinfo->mergeSize);
	return (arr);
}

int	*resettrishape(stacks *stacks, sortinfo *sortinfo, sortsize *ss)
{
	int *arr;
	int i;

	i = 0;
	arr = malloc(sizeof(int) * sortinfo->len / 3);
	if (!arr)
		free_all_error(stacks, sortinfo, ss);
	while (i < sortinfo->len / 3)
	{
		arr[i] = sortinfo->triShape[i];
		i++;
	}
	free(sortinfo->triShape);
	return (arr);
}

sortsize	*init_sortsize(sortsize *p, stacks *stacks, sortinfo *sortinfo, int a)
{
	sortsize	*ss;

	ss = malloc(sizeof(sortsize));
	if (!ss)
		free_all_error(stacks, sortinfo, p);
	if (a == 1)
	{
		ss->target = stacks->a;
		ss->src = stacks->b;
	}
	else if (a == 2)
	{
		ss->target = stacks->b;
		ss->src = stacks->a;
	}
	free(p);
	return (ss);
}

void	switchsortsize(sortsize *ss, stacks *stacks)
{
	if (ss->target == stacks->a)
	{
		ss->target = stacks->b;
		ss->src = stacks->a;
	}
	else if (ss->target == stacks->b)
	{
		ss->target = stacks->a;
		ss->src = stacks->b;
	}
}
