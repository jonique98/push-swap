/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 03:33:49 by josumin           #+#    #+#             */
/*   Updated: 2023/07/28 23:47:51 by sumjo            ###   ########.fr       */
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

//checker
void		free_all_error(t_stacks *st, t_sortinfo *si, t_sortsize *sortsize);
void		free_all(t_stacks *st, t_sortinfo *si, t_sortsize *ss);
void		free_stacks(t_stacks *stacks);

//conquer
int			*resetmergesize(t_stacks *st, t_sortinfo *si, t_sortsize *ss);
int			*resettrishape(t_stacks *st, t_sortinfo *si, t_sortsize *ss);
void		move(t_sortinfo *sortinfo, t_stacks *stacks);
void		switchsortsize(t_sortsize *ss, t_stacks *stacks);

//inputcheck
int			num_len(char *arr);
int			check(char **av, t_stacks *stacks);
int			intsert_int_node(long *num, char *arr, t_stacks *stacks);
long		makenum(char **arr);
int			duplicate_check(char *arr, long *num);
int			ft_strlen(char *s);

//maketri
void		make_tri(t_sortinfo *sortinfo, t_stacks *stacks);
void		sorting(t_stacks *stacks, t_sortsize *ss, t_sortinfo *sortinfo);

//merge
int			*make_mergesize_arr(int *mergeSize, int *arr, int *len);
int			merge(int size, t_sortinfo *sortinfo, int *len, t_stacks *stacks);
int			mergesize_and_trishape(int size, t_sortinfo *si, t_stacks *st);

//nodeutil
void		init_node(int value, t_node *node);
int			insertfirst(int a, t_stack *s);
int			insert(int a, t_stack *s);
void		pop(t_stack *s);

//operators
void		swap(t_stack *s, t_stacks *stacks);
void		push(t_sortsize *ss, t_stacks *stacks, t_sortinfo *sortinfo);
void		reverse(t_stack *a, t_stacks *stacks);
void		rreverse(t_stack *a, t_stacks *stacks);
void		rr(t_stack *a, t_stack *b, t_stacks *stacks);
void		rrr(t_stack *a, t_stack *b, t_stacks *stacks);
int			peek(t_node *a);

//realsort
void		realsort(t_sortinfo *sortinfo, t_sortsize *ss, t_stacks *stacks);
void		reallowersort(t_sortsize *ss, t_stacks *st, t_sortinfo *si);
void		realuppersort(t_sortsize *ss, t_stacks *st, t_sortinfo *si);

//sort
t_node		*max(t_node *a, t_node *b, t_node *c);
t_node		*min(t_node *a, t_node *b, t_node *c);
void		sort6(t_sortsize *ss, t_stacks *stacks, t_sortinfo *sortinfo);
void		sort3(t_sortsize *ss, t_stacks *stacks, t_sortinfo *sortinfo);
void		sort4(t_sortsize *ss, t_stacks *stacks, t_sortinfo *sortinfo);
void		sort5(t_sortsize *ss, t_stacks *stacks, t_sortinfo *sortinfo);
void		sort2(t_sortsize *ss, t_stacks *st, t_sortinfo *si, int a);
void		re(void (*f)(t_stack *s, t_stacks *st), t_stack *s, t_stacks *st);

//trishape
int			*make_trishape_arr(int *triShape, int len, int *one, int *zero);
int			*init_trishape(void);
void		make_trishape(int len, t_sortinfo *sortinfo, t_stacks *stacks);
int			*inside_trishape(int *trishape, int len, int *one, int *zero);

//util
int			is_sorting(t_stack *a);
int			ft_free(void *p1, void *p2);
char		*ft_strjoin_op(char *s1, char *s2, int i, int j);
char		*ft_strjoin(char *s1, char *s2, int i, int j);
int			isnum(char av);
int			num_check(char *arr);

//hardsort
void		hardsort3(t_stacks *stacks, t_node *node);
void		hardsort4(t_sortsize *ss, t_stacks *stacks, t_sortinfo *sortinfo);
void		hardsort5(t_sortsize *ss, t_stacks *stacks, t_sortinfo *sortinfo);
void		hardsorting(t_stacks *stacks, t_sortinfo *sortinfo);

//sortutil
void		rreverse_target_s1(t_sortsize *ss, t_stacks *stacks);
void		push_s2(t_sortsize *ss, t_stacks *stacks, t_sortinfo *sortinfo);
void		rreverse_src_push_s3(t_sortsize *ss, t_stacks *st, t_sortinfo *si);
void		sort2bottom(t_sortsize *ss, t_stacks *st);

char		*get_next_line(int fd);

#endif
