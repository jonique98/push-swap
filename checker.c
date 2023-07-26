#include "pushswap.h"

void free_all_error(stacks *stacks, sortinfo *sortinfo, sortsize *sortsize)
{
	if (sortinfo != 0)
	{
		free(sortinfo->mergeSize);
		free(sortinfo->triShape);
		free(sortinfo);
	}
	if (sortsize != 0)
		free(sortsize);
	free_stacks(stacks);
}

void free_all(stacks *stacks, sortinfo *sortinfo, sortsize *sortsize)
{
	if (sortinfo != 0)
	{
		free(sortinfo->mergeSize);
		free(sortinfo->triShape);
		free(sortinfo);
	}
	if (sortsize != 0)
		free(sortsize);
	free_stacks(stacks);
}

void free_stacks(stacks *stacks)
{
	node	*temp;
	node	*freenode;
	int		i;

	i = -1;
	temp = stacks->a->top;
	while (++i < stacks->a->size)
	{
		freenode = temp;
		temp = temp->prev;
		free(freenode);
	}
	i = -1;
	temp = stacks->b->top;
	while (++i < stacks->b->size)
	{
		freenode = temp;
		temp = temp->prev;
		free(freenode);
	}
	free(stacks->a);
	free(stacks->b);
	free(stacks->operations);
	free(stacks);
}

void leak()
{
	system("leaks a.out");
}

void	error(void *p1, void *p2, void *p3)
{
	free(p1);
	free(p2);
	free(p3);
	printf("error\n");
	// exit(0);
}

int	main(int ac, char **av)
{
	stacks		*st;
	sortinfo	*si;

	if (ac < 2)
		error(0, 0, 0);
	st = init_stacks();
	si = init_sortinfo(st);
	if (!check(av, st))
		free_all_error(st, si, 0);
	if (!is_sorting(st->a))
	{
		mergeSize_and_triShape(st->a->size, si, st);
		make_tri(si, st);
		move(si, st);
	}
	printf("%s", st->operations);
	// int len = st->a->size;
	// for(int i = 0; i < len; i++)
		// printf("%d\n", pop(st->a));
	free_all(st, si, 0);
	// system("leaks push_swap");
}
