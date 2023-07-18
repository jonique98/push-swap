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

int ft_strlen(char *s);
int isNum(char av);
int num_len(char *arr);
int check(char **av, stack *a);
int duplicate_check(char *arr, long long *num);
int num_check(char *arr);
int ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2, int i, int j);
void	insertstack(int a, stack *s);
int ft_free(void *p1, void *p2);
void	insertFirst(int a, stack *s);


#endif