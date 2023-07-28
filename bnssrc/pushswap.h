/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 03:33:49 by josumin           #+#    #+#             */
/*   Updated: 2023/07/28 23:37:46 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct _stack{
	int				v;
	struct _stack	*next;
	struct _stack	*prev;
}t_node;

typedef struct _headTail{
	int		size;
	t_node	*t;
	t_node	*b;
}t_stack;

typedef struct _sortinfo{
	int		*mergesize;
	int		*trishape;
	int		len;
}t_sortinfo;

typedef struct _stacks{
	t_stack	*a;
	t_stack	*b;
	char	*operations;
}t_stacks;

typedef struct _sortnode{
	int		s1;
	int		s2;
	int		s3;
	t_stack	*target;
	t_stack	*src;
	int		shape;
	int		size;
}t_sortsize;

//initstruct
t_sortsize	*init_sortsize(t_sortsize *p, t_stacks *st, t_sortinfo *si, int a);
t_sortinfo	*init_sortinfo(t_stacks *stacks);
t_stack		*init_stack(void);
t_stacks	*init_stacks(void);

//freeanderro
void		free_all_error(t_stacks *st, t_sortinfo *si, t_sortsize *sortsize);
void		free_all(t_stacks *st, t_sortinfo *si, t_sortsize *ss);
void		free_stacks(t_stacks *stacks);
void		error(void *p1, void *p2, void *p3);
void		leak(void);

//inputcheck
int			num_len(char *arr);
int			check(char **av, t_stacks *stacks);
int			intsert_int_node(long *num, char *arr, t_stacks *stacks);
long		makenum(char **arr);
int			duplicate_check(char *arr, long *num);
int			ft_strlen_check(char *s);

//nodeutil
void		init_node(int value, t_node *node);
int			insertfirst(int a, t_stack *s);
int			insert(int a, t_stack *s);
void		pop(t_stack *s);

//util
int			is_sorting(t_stack *a);
int			ft_free(void *p1, void *p2);
char		*ft_strjoin_op(char *s1, char *s2, int i, int j);
char		*ft_strjoin_check(char *s1, char *s2, int i, int j);
int			isnum(char av);
int			num_check(char *arr);

char		*get_next_line(int fd);
void		push_check(t_stack *src, t_stack *target, t_stacks *stacks);
void		swap_check(t_stack *s);
void		reverse_check(t_stack *a);
void		rreverse_check(t_stack *a);

#endif
