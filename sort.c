#include "pushswap.h"

int make_tri(sortinfo *sortinfo, stacks *stacks)
{
    int i;
    int size;
    int shape;

    i = 0;
    while(i < sortinfo->len)
    {
        size = sortinfo->mergeSize[i];
        shape = sortinfo->triShape[i];
        sorting(size, shape, stacks);
        i++;
    }
    return 0;
}

node *max(node *a, node *b, node *c)
{
    node *max;

    if(a->value > b->value)
        max = a;
    else
        max = b;
    if(max->value < c->value)
        return c;
    else
        return max;
}

node *min(node *a, node *b, node *c)
{
    node *min;

    if(a->value < b->value)
        min = a;
    else
        min = b;
    if(min->value > c->value)
        return c;
    else
        return min;
}

void sort_atop_abottom(node *at, node *ab, stacks *stacks, int shape)
{
    if(shape == 1)
    {
        if(at->value > ab->value)
        {
            pb(stacks->a, stacks->b);
            rra(stacks->a);
            pb(stacks->a, stacks->b);
        }
        else{
            rra(stacks->a);
            pb(stacks->a, stacks->b);
            pb(stacks->a, stacks->b);
        }
    }
    else
    {
        if(at->value < ab->value)
        {
            pb(stacks->a, stacks->b);
            rra(stacks->a);
            pb(stacks->a, stacks->b);
        }
        else{
            rra(stacks->a);
            pb(stacks->a, stacks->b);
            pb(stacks->a, stacks->b);
        }
    }

}
void sort_atop_bbottom(node *at, node *bb, stacks *stacks, int shape)
{
    if(shape == 1)
    {
        if(at->value > bb->value)
        {
            pb(stacks->a, stacks->b);
            rrb(stacks->b);
        }
        else{
            rrb(stacks->b);
            pb(stacks->a, stacks->b);
            pb(stacks->a, stacks->b);
        }
    }
    else
    {
        if(at->value < bb->value)
        {
            pb(stacks->a, stacks->b);
            rrb(stacks->b);
        }
        else{
            rrb(stacks->b);
            pb(stacks->a, stacks->b);
            pb(stacks->a, stacks->b);
        }
    }
}
void sort_abottom_bbottom(node *ab, node *bb, stacks *stacks, int shape)
{
    if(shape == 1)
    {
        if(ab->value > bb->value)
        {
            rra(stacks->a);
            pb(stacks->a, stacks->b);
            rrb(stacks->b);
        }
        else{
            rrb(stacks->b);
            rra(stacks->a);
            pb(stacks->a, stacks->b);
        }
    }
    else
    {
        if(ab->value < bb->value)
        {
            rra(stacks->a);
            pb(stacks->a, stacks->b);
            rrb(stacks->b);
        }
        else{
            rrb(stacks->b);
            rra(stacks->a);
            pb(stacks->a, stacks->b);
        }
    }
}

void upperSort(node *at, node *bb, node *ab, stacks *stacks)
{
    if(max(at, bb, ab) == at){
        pb(stacks->a, stacks->b);
        sort_abottom_bbottom(ab, bb, stacks, 1);
    }
    else if (max(at, bb, ab) == ab){
        rra(stacks->a);
        pb(stacks->a,stacks->b);
        sort_atop_bbottom(at, bb, stacks, 1);
    }
    else if (max(at, bb, ab)== bb)
    {
        rrb(stacks->b);
        sort_atop_abottom(at, ab, stacks, 1);
    }
}

void lowerSort(node *at, node *bb, node *ab, stacks *stacks)
{
    if(min(at, bb, ab) == at){
        pb(stacks->a,stacks->b);
        sort_abottom_bbottom(ab, bb, stacks, 0);
    }
    else if (min(at, bb, ab) == ab){
        rra(stacks->a);
        pb(stacks->a,stacks->b);
        sort_atop_bbottom(at, bb, stacks, 0);
    }
    else if (min(at, bb, ab) == bb)
    {
        rrb(stacks->b);
        sort_atop_abottom(at, ab, stacks, 0);
    }
}

void sort3(stacks *stacks, int shape)
{
    node *at;
    node *bb;
    node *ab;

    pb(stacks->a, stacks->b);
    rb(stacks->b);

    at = stacks->a->top;
    bb = stacks->b->bottom;
    ab = stacks->a->bottom;
    if (shape == 1){
        upperSort(at, bb, ab, stacks);
    }
    else if (shape == 0){
        lowerSort(at,bb,ab,stacks);
    }
}

void sorting(int size, int shape, stacks *stacks)
{
    int     i;

    i = 0;
    if (size == 3)
        sort3(stacks, shape);
    // else if (size >= 4 && size <= 5)
    //     sort4to5(stacks, shape);
    // else if (size == 6)
    //     sort6(stacks, shape);
}
