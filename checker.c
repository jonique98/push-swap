
#include "pushswap.h"

void	error()
{
	printf("error\n");
	exit(0);
}

int main(int ac, char **av)
{
	stacks *st;
	sortinfo *si;

	si = init_sortinfo();
	st = init_stacks();
	if ((!st->a || !st->b) || ac < 2)
		exit(0);
	if (!check(av, st))
		error();
	if (!is_sorting(st->a))
	{
		mergeSize_and_triShape(st->a->size, si);
		make_tri(si, st);
		move(si, st);
	int len = st->a->size;
	for (int i = 0; i < len; i++)
		printf("%d\n", pop(st->a));
		printf("%d", st->cnt);
	}
}
