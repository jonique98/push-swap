/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:40:49 by josumin           #+#    #+#             */
/*   Updated: 2023/07/28 22:41:50 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_stacks		*st;
	t_sortinfo		*si;

	if (ac < 2)
		free_all_error(0, 0, 0);
	st = init_stacks();
	si = init_sortinfo(st);
	if (!check(av, st))
		free_all_error(st, si, 0);
	if (!is_sorting(st->a))
	{
		if (st->a->size < 6)
			hardsorting(st, si);
		else
		{
			mergesize_and_trishape(st->a->size, si, st);
			make_tri(si, st);
			move(si, st);
		}
	}
	write(1, st->operations, ft_strlen(st->operations));
	free_all(st, si, 0);
}
