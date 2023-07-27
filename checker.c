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
	error(0,0,0);
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
	exit(0);
}

void leak()
{
	system("leaks push_swap");
}

void	error(void *p1, void *p2, void *p3)
{
	free(p1);
	free(p2);
	free(p3);
	write(1, "error\n", 6);
	exit(0);
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
	// for (int i = 0; i < st->a->size; i++)
	// {
	// 	printf("%d", st->a->top->value);
	// 	st->a->top = st->a->top->prev;
	// }
	if (!is_sorting(st->a))
	{
		if (st->a->size < 6)
			hardsorting(st, si);
		else
		{
			mergeSize_and_triShape(st->a->size, si, st);
			make_tri(si, st);
			move(si, st);
		}
	}
	write(1, st->operations, ft_strlen(st->operations));
	free_all(st, si, 0);
}
