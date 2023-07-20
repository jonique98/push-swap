#include "pushswap.h"

void move(sortinfo *sortinfo, stacks *stacks)
{
    int len;
    int size;
    int i;

    i = 0;
    size = 0;
    len = 0;

    len = sortinfo->len / 3;
    printf("%d", len);
    while (i < len)
    {
        size += sortinfo->mergeSize[i];
        i++;
    }
    i = 0;
    while (i < size)
    {
        pa(stacks->b, stacks->a);
        i++;
    }
}

void realsort3(stacks *stacks, int shape)
{
    node *ab;
    node *bb;
    node *bt;

    ab = stacks->a->bottom;
    bb = stacks->b->bottom;
    bt = stacks->b->top;
    realupperSort(ab, bb, bt, stacks);
    // lowerSort(at,bb,ab,stacks);
}

realupperSort(node *ab, node *bb, node *bt, stacks *stacks)
{
    
}