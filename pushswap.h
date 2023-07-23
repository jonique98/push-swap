#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
	int		cnt;
}stacks;

typedef struct _sortnode{
	int		size1;
	int		size2;
	int		size3;
	stack	*target;
	stack	*src;
	int		shape;
}sortsize;

void    swap(stack *s, stacks *stacks);
void	push(stack *a, stack *b, stacks *stacks);
void	reverse(stack *a, stacks *stacks);
void	rreverse(stack *a, stacks *stacks);
void	rr(stack *a, stack *b, stacks *stacks);
void	rrr(stack *a, stack *b, stacks *stacks);
int     peek(node *a);

node *max(node *a, node *b, node *c);
node *min(node *a, node *b, node *c);
void sort2(sortsize *ss, int shape, stacks *stacks);
void sort3(sortsize *ss, int shape, stacks *stacks);
void sort4(sortsize *ss, int shape, stacks *stacks);
void sort5(sortsize *ss, int shape, stacks *stacks);

int			*resetmergesize(sortinfo *si);
int			*resettrishape(sortinfo *si);
sortsize	*init_sortsize(stacks *stacks, int a);
void		switchsortsize(sortsize *ss, stacks *stacks);

void realsort(sortinfo *sortinfo, sortsize *ss, stacks *stacks);
void realuppersort(sortsize *ss, stacks *stacks, stack *target, stack *src);
void reallowersort(sortsize *ss, stacks *stacks, stack *target, stack *src);

void sorting(int size, int shape, stacks *stacks, sortsize *ss);
void move(sortinfo *sortinfo, stacks *stacks);
void make_tri(sortinfo *sortinfo, stacks *stacks);

void	insertFirst(int a, stack *s);
void    insert(int a, stack *s);
int     pop(stack *s);

stacks		*init_stacks(void);
void		init_node(int value, node *node);
sortinfo	*init_sortinfo(void);

int     num_len(char *arr);
int     check(char **av, stacks *stacks);
int     duplicate_check(char *arr, long long *num);
int     num_check(char *arr);
int     is_sorting(stack *a);

int     isNum(char av);
int     ft_free(void *p1, void *p2);
int     ft_strlen(char *s);
char    *ft_strjoin(char *s1, char *s2, int i, int j);

void    merge(int size, sortinfo *sortinfo, int *len);
int     *make_mergesize_arr(int *mergeSize, int *arr, int *len);
int     mergeSize_and_triShape(int size, sortinfo *sortinfo);

int     *init_trishape();
int     *make_trishape_arr(int *triShape, int len, int *one, int *zero);
void    make_triShape(int len, sortinfo *sortinfo);

#endif
