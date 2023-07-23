#include "pushswap.h"

void	make_tri(sortinfo *sortinfo, stacks *stacks)
{
	int i;
	int len;
	int size;
	int shape;
	sortsize *ss;

	len = stacks->a->size;
	i = -1;
	if (sortinfo->len == 9 || sortinfo->len == 81)
	{
		ss = init_sortsize(stacks, 1);
		while (++i < len)
			push(stacks->a, stacks->b, stacks);
	}
	else
		ss = init_sortsize(stacks, 2);
	i = 0;
	while (i < sortinfo->len)
	{   
		size = sortinfo->mergeSize[i];
		shape = sortinfo->triShape[i];
		sorting(size, shape, stacks, ss);
		i++;
	}
}

void	sorting(int size, int shape, stacks *stacks, sortsize *ss)
{
	int	i;

	i = 0;
	if (size < 3)
		sort2(ss, shape, stacks);
	else if (size == 3)
		sort3(ss, shape, stacks);
	else if (size == 4)
		sort4(ss, shape, stacks);
	else if (size == 5)
		sort5(ss, shape, stacks);
	// else if (size == 6)
	//     sort6(stacks, shape);
}
