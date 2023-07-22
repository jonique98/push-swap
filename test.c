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

int     peek(node *a)
{
    return a->value;
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
    free(si->mergeSize);
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
    free(si->triShape);
    return arr;
}

sortsize *init_sortsize(stacks *stacks, int a)
{
    sortsize *ss;

    ss = malloc(sizeof(sortsize));
    if(a == 1)
    {
        ss->target = stacks->a;
        ss->src = stacks->b;
    }
    else if (a == 2)
    {
        ss->target = stacks->b;
        ss->src = stacks->a;
    }
    return ss;
}

void switchsortsize(sortsize *ss, stacks *stacks)
{
    if(ss->target == stacks->a)
    {
        ss->target = stacks->b;
        ss->src = stacks->a;
    }
    else if(ss->target == stacks->b)
    {
        ss->target = stacks->a;
        ss->src = stacks->b;
    }
}

void move(sortinfo *sortinfo, stacks *stacks, int a)
{
    int len;
    int size;
    int i;
    sortsize *ss;

    i = -1;
    size = 0;
    len = 0;
    ss = init_sortsize(stacks, a);

    while (is_sorting(stacks->a))
    {
        len = sortinfo->len / 3;
        while (++i < len)
            size += sortinfo->mergeSize[i];
        i = -1;
        while (++i < size)
            move(ss->src, ss->target);
        realsort(stacks, sortinfo);
        sortinfo->triShape = resettriShape(sortinfo);
        sortinfo->mergeSize = resetmergeSize(sortinfo);
        sortinfo->len = sortinfo->len / 3;
        switchsortsize(ss, stacks);
    }
    return ;
}

void realsort(sortinfo *sortinfo, sortsize *ss)
{
    int i;

    i = -1;
    while(++i < sortinfo->len / 3)
    {
        ss->size1 = sortinfo->mergeSize[sortinfo->len - i - 1];
        ss->size2 = sortinfo->mergeSize[sortinfo->len - (sortinfo->len / 3 + i)];
        ss->size3 = sortinfo->mergeSize[i];
        ss->shape = sortinfo->triShape[i];
        if(ss->shape == 1)
            realupperSort(ss);
        else if(ss->shape == 0)
            reallowerSort(ss);
    }
}

void reallopwerSort(sortsize *ss)
{
    node *tb;
    node *st;
    node *sb;

    tb = ss->target->bottom; 
    st = ss->src->top;
    sb = ss->src->bottom;
    while(ss->size1 != 0 && ss->size2 != 0 && ss->size3 != 0)
    {
        if(ss->size1 != 0 && ((min(tb, st, sb) == tb) || (ss->size3 != 0 && ss->size2 == 0 && tb->value < sb->value) || (ss->size2 != 0 && ss->size3 == 0 && tb->value < st->value) || (ss->size2 == 0 && ss->size3 == 0)))
        {
            rra(ss->target);
            ss->size1--;
        }
        else if(ss->size2 != 0 && ((min(tb, st, sb) == st) || (ss->size1 != 0 && ss->size3 == 0 && st->value < tb->value) || (ss->size3 != 0 && ss->size1 == 0 && st->value < sb->value) || (ss->size1 == 0 && ss->size3 == 0)))
        {
            pa(ss->src, ss->target);
            ss->size2--;
        }
        else if(ss->size3 != 0 && ((min(tb, st, sb) == sb) || (ss->size2 != 0 && ss->size1 == 0 && sb->value < st->value) || (ss->size1 != 0 && ss->size2 == 0 && sb->value < tb->value) || (ss->size1 == 0 && ss->size2 == 0)))
        {
            rra(ss->src);
            pa(ss->src, ss->target);
            ss->size3--;
        }
    }
}

void realupperSort(sortsize *ss)
{
    node *tb;
    node *st;
    node *sb;

    tb = ss->target->bottom; 
    st = ss->src->top;
    sb = ss->src->bottom;
    while(ss->size1 != 0 && ss->size2 != 0 && ss->size3 != 0)
    {
        if(ss->size1 != 0 && ((max(tb, st, sb) == tb) || (ss->size3 != 0 && ss->size2 == 0 && tb->value > sb->value) || (ss->size2 != 0 && ss->size3 == 0 && tb->value > st->value) || (ss->size2 == 0 && ss->size3 == 0)))
        {
            rra(ss->target);
            ss->size1--;
        }
        else if(ss->size2 != 0 && ((max(tb, st, sb) == st) || (ss->size1 != 0 && ss->size3 == 0 && st->value > tb->value) || (ss->size3 != 0 && ss->size1 == 0 && st->value > sb->value) || (ss->size1 == 0 && ss->size3 == 0)))
        {
            pa(ss->src, ss->target);
            ss->size2--;
        }
        else if(ss->size3 != 0 && ((max(tb, st, sb) == sb) || (ss->size2 != 0 && ss->size1 == 0 && sb->value > st->value) || (ss->size1 != 0 && ss->size2 == 0 && sb->value > tb->value) || (ss->size1 == 0 && ss->size2 == 0)))
        {
            rra(ss->src);
            pa(ss->src, ss->target);
            ss->size3--;
        }
    }
}


// void realupperSort(stacks *stacks, sortsize *ss)
// {
//     while(ss->size1 != 0 && ss->size2 != 0 && ss->size3 != 0)
//             moveMaxvalue(stacks, ss);
//     if(ss->size1 == 0)
//             moveupper23(stacks, ss);
//     else if(ss->size2 == 0)
//             moveupper13(stacks, ss);
//     else if(ss->size3 == 0)
//             moveupper12(stacks, ss);
// }
// void reallowerSort(stacks *stacks, sortsize *ss)
// {
//     while(ss->size1 != 0 && ss->size2 != 0 && ss->size3 != 0)
//             moveMinvalue(stacks, ss);
//     if(ss->size1 == 0)
//             movelower23(stacks, ss);
//     else if(ss->size2 == 0)
//             movelower13(stacks, ss);
//     else if(ss->size3 == 0)
//             movelower12(stacks, ss);
// }