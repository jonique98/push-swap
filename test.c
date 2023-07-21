#include "pushswap.h"

#include "pushswap.h"

void swap(stack *s)
{
    if (s->size < 2)
        return;
    node *top = s->top;
    node *second = s->top->prev;

    top->prev = second->prev;
    second->prev->next = top;

    second->next = top->next;
    top->next->prev = second;

    top->next = second;
    second->prev = top;

    s->top = second;

    // 스택의 맨 아래 노드인 경우, bottom도 변경
    if (s->size == 2)
        s->bottom = top;
}

void	push(stack *a, stack *b)
{
	int	value;

	value = pop(a);
	if (value == -1)
		return ;
	insert(value, b);
}

void	reverse(stack *a)
{
	if (a->size == 0)
		return ;
	a->top = a->top->prev;
	a->bottom = a->bottom->prev;
}


void	rreverse(stack *a)
{
	if (a->size == 0)
		return ;
	a->top = a->top->next;
	a->bottom = a->bottom->next;
}

void	rr(stack *a, stack *b)
{
	ra(a);
	rb(b);
}

void	rrr(stack *a, stack *b)
{
	rra(a);
	rrb(b);
}


int *resetmergeSize(sortinfo *si){
    int *arr;
    int i = 0;
    int j = 0;

    arr = malloc(sizeof(int) * si->len / 3);
    while (i < si->len)
    {
        arr[j] = si->mergeSize[i] + si->mergeSize[i + si->len / 3] + si->mergeSize[si->len - i - 1];
        j++;
        i+=3;
    }
    return arr;
}

int *resettriShape(sortinfo *si){
    int *arr;
    int i =0;
    int j = 0;

    arr = malloc(sizeof(int) * si->len / 3);

    while (i < si->len)
    {
        if(si->triShape[i] == 1 && (si->triShape[i+1] == 0) && (si->triShape[i+2] == 0))
        {
            arr[j] = 1;
            j++;
        }
        else if (si->triShape[i] == 1 && (si->triShape[i+1] == 1) && (si->triShape[i+2] == 0))
        {
            arr[j] = 1;
            j++;
        }
        i+=3;
    }
}

void move(sortinfo *sortinfo, stacks *stacks)
{
    int len;
    int size;
    int i;

    i = -1;
    size = 0;
    len = 0;

    while (is_sorting(stacks->a))
    {
        len = sortinfo->len / 3;
        while (++i < len)
            size += sortinfo->mergeSize[i];
        i = -1;
        if(stacks->a->size == 0)
        {
            while (++i < size)
                pa(stacks->b, stacks->a);
        }
        else
            pa(stacks->b, stacks->a);
        }
        realsort3(stacks, sortinfo);
        sortinfo->triShape = resettriShape(sortinfo);
        sortinfo->mergeSize = resetmergeSize(sortinfo);
        sortinfo->len = sortinfo->len / 3;
    }
}

void realsort3(stacks *stacks, sortinfo *sortinfo)
{
    sortsize *ss;
    int i;

    ss = malloc(sizeof(sortsize));

    i = -1;
    while(++i < sortinfo->len / 3)
    {
        ss->size1 = sortinfo->mergeSize[sortinfo->len - i - 1];
        ss->size2 = sortinfo->mergeSize[sortinfo->len - (sortinfo->len / 3 + i)];
        ss->size3 = sortinfo->mergeSize[i];
        ss->shape = sortinfo->triShape[i];
        if(ss->shape == 1)
            realupperSort(stacks, ss);
        // else if(ss->shape == 0)
            // reallowerSort(stacks, ss);
    }
}

void moveMaxvalue(stacks *stacks, sortsize *ss)
{
    if (max(stacks->a->bottom, stacks->b->top, stacks->b->bottom) == stacks->a->bottom)
    {
        rra(stacks->a);
        ss->size1--;
    }
    else if (max(stacks->a->bottom, stacks->b->top, stacks->b->bottom) == stacks->b->top)
    {
        pa(stacks->b, stacks->a);
        ss->size2--;
    }
    else if (max(stacks->a->bottom, stacks->b->top, stacks->b->bottom) == stacks->b->bottom)
    {
        rrb(stacks->b);
        pa(stacks->b, stacks->a);
        ss->size3--;
    }
}

void moveMinvalue(stacks *stacks, sortsize *ss)
{
    if (min(stacks->a->bottom, stacks->b->top, stacks->b->bottom) == stacks->a->bottom)
    {
        rra(stacks->a);
        ss->size1--;
    }
    else if (min(stacks->a->bottom, stacks->b->top, stacks->b->bottom) == stacks->b->top)
    {
        pa(stacks->b, stacks->a);
        ss->size2--;
    }
    else if (min(stacks->a->bottom, stacks->b->top, stacks->b->bottom) == stacks->b->bottom)
    {
        rrb(stacks->b);
        pa(stacks->b, stacks->a);
        ss->size3--;
    }
}

void moveupper23(stacks *stacks, sortsize *ss)
{
    while (ss->size2 > 0 && ss->size3 > 0)
        {
            if(max(0, stacks->b->top, stacks->b->bottom) == stacks->b->top)
                {
                    pa(stacks->b, stacks->a);
                    ss->size2--;
                }
            else if (max(0, stacks->b->top, stacks->b->bottom) == stacks->b->bottom)
                {
                    rrb(stacks->b);
                    pa(stacks->b, stacks->a);
                    ss->size3--;
                }
        }
        if(ss->size2 == 0)
        {
            while(ss->size3 >0)
            {
                rrb(stacks->b);
                pa(stacks->b, stacks->a);
                ss->size3--;
            }
        }
        else if(ss->size3 == 0)
        {
            while(ss->size2 >0)
            {
                pa(stacks->b, stacks->a);
                ss->size2--;
            }
        }
}

void movelower23(stacks *stacks, sortsize *ss)
{
    while (ss->size2 > 0 && ss->size3 > 0)
        {
            if(min(0, stacks->b->top, stacks->b->bottom) == stacks->b->top)
                {
                    pa(stacks->b, stacks->a);
                    ss->size2--;
                }
            else if (min(0, stacks->b->top, stacks->b->bottom) == stacks->b->bottom)
                {
                    rrb(stacks->b);
                    pa(stacks->b, stacks->a);
                    ss->size3--;
                }
        }
        if(ss->size2 == 0)
        {
            while(ss->size3 > 0)
            {
                rrb(stacks->b);
                pa(stacks->b, stacks->a);
                ss->size3--;
            }
        }
        else if(ss->size3 == 0)
        {
            while(ss->size2 >0)
            {
                pa(stacks->b, stacks->a);
                ss->size2--;
            }
        }
}

void moveupper13(stacks *stacks, sortsize *ss)
{
    while (ss->size1 > 0 && ss->size3 > 0)
    {
            if (max(0, stacks->a->bottom, stacks->b->bottom) == stacks->a->bottom)
            {
                rra(stacks->a);
                ss->size1--;
            }
            else if (max(0, stacks->a->bottom, stacks->b->bottom) == stacks->b->bottom)
            {
                rrb(stacks->b);
                pa(stacks->b, stacks->a);
                ss->size3--;
            }
    }
    if(ss->size1 == 0)
        {
            while(ss->size3 >0)
            {
                rrb(stacks->b);
                pa(stacks->b, stacks->a);
                ss->size3--;
            }
        }
        else if(ss->size3 == 0)
        {
            while(ss->size1 >0)
            {
                rra(stacks->a);
                ss->size1--;
            }
        }
}

void movelower13(stacks *stacks, sortsize *ss)
{
    while (ss->size1 != 0 && ss->size3 != 0)
        {
            if(min(0, stacks->a->bottom, stacks->b->bottom) == stacks->a->bottom)
                {
                    rra(stacks->a);
                    ss->size1--;
                }
            else if (min(0, stacks->a->bottom, stacks->b->bottom) == stacks->b->bottom)
                {
                    rrb(stacks->b);
                    pa(stacks->b, stacks->a);
                    ss->size3--;
                }
        }
        if(ss->size1 == 0)
        {
            while(ss->size3 !=0)
            {
                rrb(stacks->b);
                pa(stacks->b, stacks->a);
                ss->size3--;
            }
        }
        else if(ss->size3 == 0)
        {
            while(ss->size1 !=0)
            {
                pa(stacks->b, stacks->a);
                ss->size1--;
            }
        }
}

void moveupper12(stacks *stacks, sortsize *ss)
{
    while (ss->size1 > 0 && ss->size2 > 0)
        {
            if(max(0, stacks->a->bottom, stacks->b->top) == stacks->a->bottom)
                {
                    rra(stacks->a);
                    ss->size1--;
                }
            else if (max(0, stacks->a->bottom, stacks->b->top) == stacks->b->top)
                {
                    pa(stacks->b, stacks->a);
                    ss->size2--;
                }
        }
    if(ss->size1 == 0)
        {
            while(ss->size2  > 0)
            {
                pa(stacks->b, stacks->a);
                ss->size2--;
            }
        }
    else if(ss->size2 == 0)
        {
            while(ss->size1 > 0)
            {
                rra(stacks->a);
                ss->size1--;
            }
        }
}

void movelower12(stacks *stacks, sortsize *ss)
{
    while (ss->size1 != 0 && ss->size2 != 0)
        {
            if(min(0, stacks->a->bottom, stacks->b->top) == stacks->a->bottom)
                {
                    rra(stacks->a);
                    ss->size1--;
                }
            else if (min(0, stacks->a->bottom, stacks->b->top) == stacks->b->top)
                {
                    pa(stacks->b, stacks->a);
                    ss->size2--;
                }
        }
        if(ss->size1 == 0)
        {
            while(ss->size2 !=0)
            {
                pa(stacks->b, stacks->a);
                ss->size2--;
            }
        }
        else if(ss->size2 == 0)
        {
            while(ss->size1 !=0)
            {
                rra(stacks->a);
                ss->size1--;
            }
        }
}

void reallowerSort(stacks *stacks, sortsize *ss)
{
    while(ss->size1 != 0 && ss->size2 != 0 && ss->size3 != 0)
            moveMinvalue(stacks, ss);
    if(ss->size1 == 0)
            movelower23(stacks, ss);
    else if(ss->size2 == 0)
            movelower13(stacks, ss);
    else if(ss->size3 == 0)
            movelower12(stacks, ss);
}

void realupperSort(stacks *stacks, sortsize *ss)
{
    while(ss->size1 != 0 && ss->size2 != 0 && ss->size3 != 0)
            moveMaxvalue(stacks, ss);
    if(ss->size1 == 0)
            moveupper23(stacks, ss);
    else if(ss->size2 == 0)
            moveupper13(stacks, ss);
    else if(ss->size3 == 0)
            moveupper12(stacks, ss);
}