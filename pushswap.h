/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 03:33:49 by josumin           #+#    #+#             */
/*   Updated: 2023/07/27 23:31:14 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
#define MINS1 min(t->bottom, s->top, s->bottom) == t->bottom
#define MINS2 min(t->bottom, s->top, s->bottom) == s->top
#define MINS3 min(t->bottom, s->top, s->bottom) == s->bottom
#define MAXS1 max(t->bottom, s->top, s->bottom) == t->bottom
#define MAXS2 max(t->bottom, s->top, s->bottom) == s->top
#define MAXS3 max(t->bottom, s->top, s->bottom) == s->bottom

typedef struct _stack{
	int		value;
	struct	_stack *next;
	struct	_stack *prev;
}node;

typedef struct _headTail{
	int		size;
	node	*top;
	node	*bottom;
}stack;

typedef struct _sortinfo{
	int     len;
	int		*mergeSize;
	int		*triShape;
}sortinfo;

typedef struct _stacks{
	stack	*a;
	stack	*b;
	char	*operations;
}stacks;

typedef struct _sortnode{
	int		s1;
	int		s2;
	int		s3;
	stack	*target;
	stack	*src;
	int		shape;
	int		size;
}sortsize;

//checker
void	free_all_error(stacks *stacks, sortinfo *sortinfo, sortsize *sortsize);
void	free_all(stacks *stacks, sortinfo *sortinfo, sortsize *sortsize);
void	free_stacks(stacks *stacks);
void	leak();
void	error(void *p1, void *p2, void *p3);

//conquer
int		*resetmergesize(stacks *stacks, sortinfo *sortinfo, sortsize *ss);
int		*resettrishape(stacks *stacks, sortinfo *sortinfo, sortsize *ss);
void	move(sortinfo *sortinfo, stacks *stacks);
void	switchsortsize(sortsize *ss, stacks *stacks);
sortsize	*init_sortsize(sortsize *p, stacks *stacks, sortinfo *sortinfo, int a);

//initstruct
stack	*init_stack(void);
stacks	*init_stacks(void);
sortinfo	*init_sortinfo(stacks *stacks);

//inputcheck
int		num_len(char *arr);
int		check(char **av, stacks *stacks);
int		intsert_int_node(long *num, char *arr, stacks *stacks);
long	makeNum(char **arr);
int	duplicate_check(char *arr, long *num);
int		ft_strlen(char *s);

//maketri
void	make_tri(sortinfo *sortinfo, stacks *stacks);
void	sorting(stacks *stacks, sortsize *ss, sortinfo *sortinfo);

//merge
int		*make_mergesize_arr(int *mergeSize, int *arr, int *len);
int		merge(int size, sortinfo *sortinfo, int *len, stacks *stacks);
int		mergeSize_and_triShape(int size, sortinfo *sortinfo, stacks *stacks);

//nodeutil
void	init_node(int value, node *node);
int		insertFirst(int a, stack *s);
int		insert(int a, stack *s);
void	pop(stack *s);

//operators
void	swap(stack *s, stacks *stacks);
void	push(sortsize *ss, stacks *stacks, sortinfo *sortinfo);
void	reverse(stack *a, stacks *stacks);
void	rreverse(stack *a, stacks *stacks);
void	rr(stack *a, stack *b, stacks *stacks);
void	rrr(stack *a, stack *b, stacks *stacks);
int		peek(node *a);

//realsort
void	realsort(sortinfo *sortinfo, sortsize *ss, stacks *stacks);
void	reallowersort(sortsize *ss, stacks *stacks, stack *target, stack *src, sortinfo *sortinfo);
void	realuppersort(sortsize *ss, stacks *stacks, stack *target, stack *src, sortinfo *sortinfo);

//sort
node	*max(node *a, node *b, node *c);
node	*min(node *a, node *b, node *c);
void	sort6(sortsize *ss, stacks *stacks, sortinfo *sortinfo);
void	sort3(sortsize *ss, stacks *stacks, sortinfo *sortinfo);
void	sort4(sortsize *ss, stacks *stacks, sortinfo *sortinfo);
void	sort5(sortsize *ss, stacks *stacks, sortinfo *sortinfo);
void	sort2(sortsize *ss, stacks *stacks, sortinfo *sortinfo, int a);

//trishape
int		*make_trishape_arr(int *triShape, int len, int *one, int *zero);
int		*init_trishape(void);
void	make_triShape(int len, sortinfo *sortinfo, stacks *stacks);

//util
int		is_sorting(stack *a);
int		ft_free(void *p1, void *p2);
char	*ft_strjoin_op(char *s1, char *s2, int i, int j);
char	*ft_strjoin(char *s1, char *s2, int i, int j);
int		isNum(char av);
int		num_check(char *arr);

//hardsort
void	hardsort3(stacks *stacks, node *node);
void	hardsort4(sortsize *ss, stacks *stacks, sortinfo *sortinfo);
void	hardsort5(sortsize *ss, stacks *stacks, sortinfo *sortinfo);
void	hardsorting(stacks *stacks, sortinfo *sortinfo);

#endif
