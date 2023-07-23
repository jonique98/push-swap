#include "pushswap.h"

void	move(sortinfo *sortinfo, stacks *stacks)
{
	int len;
	int size;
	int i;
	sortsize *ss;

	len = 0;
	if (stacks->a->size == 0)
		ss = init_sortsize(stacks, 1);
	else
		ss = init_sortsize(stacks, 2);
	int j = 0;
	while (!is_sorting(stacks->a))
	{
		i = -1;
		size = 0;
		len = sortinfo->len / 3;
		while (++i < len)
			size += sortinfo->mergeSize[sortinfo->len - i - 1];
		i = -1;
		while (++i < size)
			push(ss->src, ss->target, stacks);
		realsort(sortinfo, ss, stacks);
		sortinfo->triShape = resettrishape(sortinfo);
		sortinfo->mergeSize = resetmergesize(sortinfo);
		sortinfo->len = sortinfo->len / 3;
		switchsortsize(ss, stacks);
	}
}

int	*resetmergesize(sortinfo *si)
{
	int *arr;
	int i = 0;

	arr = malloc(sizeof(int) * si->len / 3);
	while (i < si->len / 3)
	{
		arr[i] = si->mergeSize[i] + si->mergeSize[si->len - (si->len / 3) - i - 1] + si->mergeSize[si->len - i - 1];
		i++;
	}
	free(si->mergeSize);
	return arr;
}

int	*resettrishape(sortinfo *si)
{
	int *arr;
	int i =0;
	int j = 0;

	arr = malloc(sizeof(int) * si->len / 3);
	while (i < si->len / 3)
	{
		arr[i] = si->triShape[i];
		i++;
	}
	free(si->triShape);
	return (arr);
}

sortsize	*init_sortsize(stacks *stacks, int a)
{
	sortsize *ss;

	ss = malloc(sizeof(sortsize));
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
	return ss;
}

void	switchsortsize(sortsize *ss, stacks *stacks)
{
	if (ss->target == stacks->a)
	{
		ss->target = stacks->b;
		ss->src = stacks->a;
	}
	else if(ss->target == stacks->b)
	{
		ss->target = stacks->a;
		ss->src = stacks->b;
	}
}
