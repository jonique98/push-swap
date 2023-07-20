#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct _stack{
    int value;
    struct _stack *next;
    struct _stack *prev;
}node;

typedef struct _headTail{
    int size;
    node *top;
    node *bottom;
}stack;

typedef struct _sortinfo{
    int     len;
    int		*mergeSize;
	int		*triShape;
}sortinfo;

typedef struct _stacks{
    stack *a;
    stack *b;
}stacks;

void    sa(stack *s);
void    sb(stack *s);
void	pa(stack *b, stack *a);
void	pb(stack *a, stack *b);
void	ra(stack *a);
void	rb(stack *b);
void	rra(stack *a);
void	rrb(stack *b);
void	rr(stack *a, stack *b);
void	rrr(stack *a, stack *b);

node *max(node *a, node *b, node *c);
node *min(node *a, node *b, node *c);
int make_tri(sortinfo *sortinfo, stacks *stacks);
void sort_atop_abottom(node *at, node *ab, stacks *stacks, int shape);
void sort_atop_bbottom(node *at, node *bb, stacks *stacks, int shape);
void sort_abottom_bbottom(node *ab, node *bb, stacks *stacks, int shape);
void upperSort(node *at, node *bb, node *ab, stacks *stacks);
void lowerSort(node *at, node *bb, node *ab, stacks *stacks);
void sort3(stacks *stacks, int shape);
void sorting(int size, int shape, stacks *stacks);


void move(sortinfo *sortinfo, stacks *stacks);

void	insert(int a, stack *s);
int	pop(stack *s);
int	peekTop(node *n);
stacks *init_stacks();
int ft_strlen(char *s);
int isNum(char av);
int num_len(char *arr);
int check(char **av, stacks *stacks);
int duplicate_check(char *arr, long long *num);
int num_check(char *arr);
int ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2, int i, int j);
void	insertstack(int a, stack *s);
int ft_free(void *p1, void *p2);
void	insertFirst(int a, stack *s);
void merge(int size, sortinfo *sortinfo, int *len);
int *make_mergesize_arr(int *mergeSize, int *arr, int *len);
int *make_trishape_arr(int *triShape, int len, int *one, int *zero);
void make_triShape(int len, sortinfo *sortinfo);
int *init_trishape();
int mergeSize_and_triShape(int size, sortinfo *sortinfo);

#endif