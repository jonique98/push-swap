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
    int     cnt;
}stacks;

typedef struct _sortnode{
    int size1;
    int size2;
    int size3;
    stack *target;
    stack *src;
    int shape;
}sortsize;

void sort3(sortsize *ss, int shape, stacks *stacks);
void sort4(sortsize *ss, int shape, stacks *stacks);
void sort5(sortsize *ss, int shape, stacks *stacks);

void    swap(stack *s, stacks *stacks);
void	push(stack *a, stack *b, stacks *stacks);
void	reverse(stack *a, stacks *stacks);
void	rreverse(stack *a, stacks *stacks);
void	rr(stack *a, stack *b, stacks *stacks);
void	rrr(stack *a, stack *b, stacks *stacks);
int     peek(node *a);

int *resetmergeSize(sortinfo *si);
int *resettriShape(sortinfo *si);

sortsize *init_sortsize(stacks *stacks, int a);
int is_sorting(stack *a);
void switchsortsize(sortsize *ss, stacks *stacks);

void move(sortinfo *sortinfo, stacks *stacks, int a);
void realsort(sortinfo *sortinfo, sortsize *ss, stacks *stacks);
void reallowerSort(sortsize *ss, stacks *stacks);
void realupperSort(sortsize *ss, stacks *stacks);

node *max(node *a, node *b, node *c);
node *min(node *a, node *b, node *c);
void make_tri(sortinfo *sortinfo, stacks *stacks);
void sorting(int size, int shape, stacks *stacks, sortsize *ss);

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
