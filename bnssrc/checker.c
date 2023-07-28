/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:40:49 by josumin           #+#    #+#             */
/*   Updated: 2023/07/28 23:44:17 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_op(char *op, t_stacks *st)
{
	if (op[0] == 'p' && op[1] == 'a')
		push_check(st->b, st->a, st);
	else if (op[0] == 'p' && op[1] == 'b')
		push_check(st->a, st->b, st);
	else if (op[0] == 's' && op[1] == 'a')
		swap_check(st->a);
	else if (op[0] == 's' && op[1] == 'b')
		swap_check(st->b);
	else if (op[0] == 'r' && op[1] == 'a')
		reverse_check(st->a);
	else if (op[0] == 'r' && op[1] == 'b')
		reverse_check(st->b);
	else if (op[0] == 'r' && op[1] == 'r' && op[2] == 'a')
		rreverse_check(st->a);
	else if (op[0] == 'r' && op[1] == 'r' && op[2] == 'b')
		rreverse_check(st->b);
	else
		free_all_error(st, 0, 0);
}

int	main(int ac, char **av)
{
	t_stacks		*st;
	char			*op;

	if (ac < 2)
		free_all_error(0, 0, 0);
	st = init_stacks();
	if (!check(av, st))
		free_all_error(st, 0, 0);
	while (1)
	{
		op = get_next_line(0);
		if (op == 0 || op[0] == '\n')
		{
			free(op);
			break ;
		}
		do_op(op, st);
		free(op);
	}
	if (is_sorting(st->a) && st->b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(st, 0, 0);
}
