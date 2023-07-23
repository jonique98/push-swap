#include"pushswap.h"

void swap(stack *s, stacks *stacks)
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

    if (s->size == 2)
        s->bottom = top;
    stacks->cnt++;
}

void	push(stack *a, stack *b, stacks *stacks)
{
	int	value;

	value = pop(a);
	if (value == -1)
		return ;
	insert(value, b);
    stacks->cnt++;
}

void	reverse(stack *a, stacks *stacks)
{
	if (a->size < 2)
		return ;
	a->top = a->top->prev;
	a->bottom = a->bottom->prev;
    stacks->cnt++;
}

void	rreverse(stack *a, stacks *stacks)
{
	if (a->size < 2)
		return ;
	a->top = a->top->next;
	a->bottom = a->bottom->next;
    stacks->cnt++;
}

void	rr(stack *a, stack *b, stacks *stacks)
{
	reverse(a, stacks);
	reverse(b, stacks);
    stacks->cnt++;
}

void	rrr(stack *a, stack *b, stacks *stacks)
{
	rreverse(a, stacks);
    rreverse(b, stacks);
    stacks->cnt++;
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
    while (i < si->len / 3)
    {
        arr[j] = si->mergeSize[i] + si->mergeSize[si->len - (si->len / 3) - i - 1] + si->mergeSize[si->len - i - 1];
        j++;
        i++;
    }
    free(si->mergeSize);
    return arr;
}

int *resettriShape(sortinfo *si){
    int *arr;
    int i =0;
    int j = 0;

    arr = malloc(sizeof(int) * si->len / 3);

    while (i < si->len / 3)
    {
        arr[i] = si->triShape[i];
        i++;
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

int is_sorting(stack *a)
{
    int i;
    node *n;
    int value;

    if(a->size == 0)
        return 0;

    i = 0;
    value = -1;
    n = a->top;
    while (i < a->size)
    {
        if(n->value > value){
            value = n->value;
            n = n->prev;
        }
        else
            return 0;
        i++;
    }
    return 1;
}

void move(sortinfo *sortinfo, stacks *stacks)
{
    int len;
    int size;
    int i;
    sortsize *ss;

    len = 0;
    if(stacks->a->size == 0)
        ss = init_sortsize(stacks, 1);
    else
        ss = init_sortsize(stacks, 2);
    int j = 0;
    while(!is_sorting(stacks->a))
    {
        i = -1;
        size = 0;
        len = sortinfo->len / 3;
        while (++i < len)
            size += sortinfo->mergeSize[sortinfo->len - i - 1];
        i = -1;
        while(++i < size)
            push(ss->src, ss->target, stacks);
        realsort(sortinfo, ss, stacks);
        sortinfo->triShape = resettriShape(sortinfo);
        sortinfo->mergeSize = resetmergeSize(sortinfo);
        sortinfo->len = sortinfo->len / 3;
        switchsortsize(ss, stacks);
    }
}

void realsort(sortinfo *sortinfo, sortsize *ss, stacks *stacks)
{
    int i;

    i = -1;
    while(++i < sortinfo->len / 3)
    {
        ss->size1 = sortinfo->mergeSize[sortinfo->len - i - 1];
        ss->size2 = sortinfo->mergeSize[sortinfo->len - ((sortinfo->len / 3) + i + 1)];
        ss->size3 = sortinfo->mergeSize[i];
        ss->shape = sortinfo->triShape[i];
        if(ss->shape == 1)
            realupperSort(ss, stacks);
        else if(ss->shape == 0)
            reallowerSort(ss, stacks);
    }
}

void reallowerSort(sortsize *ss, stacks *stacks)
{
    stack *target;
    stack *src;


    target = ss->target; 
    src = ss->src;
    while(ss->size1 != 0 || ss->size2 != 0 || ss->size3 != 0)
    {
        if(ss->size1 != 0 && ((ss->size2 !=0 && ss->size3 != 0 && min(target->bottom, src->top, src->bottom) == target->bottom) 
        || (ss->size3 != 0 && ss->size2 == 0 && target->bottom->value < src->bottom->value) 
        || (ss->size2 != 0 && ss->size3 == 0 && target->bottom->value < src->top->value) || (ss->size2 == 0 && ss->size3 == 0)))
        {
            rreverse(ss->target, stacks);
            ss->size1--;
        }
        else if(ss->size2 != 0 && ((ss->size1 !=0 && ss->size3 != 0 && min(target->bottom, src->top, src->bottom) == src->top) 
        || (ss->size1 != 0 && ss->size3 == 0 && src->top->value < target->bottom->value)
         || (ss->size3 != 0 && ss->size1 == 0 && src->top->value < src->bottom->value) || (ss->size1 == 0 && ss->size3 == 0)))
        {
            push(ss->src, ss->target, stacks);
            ss->size2--;
        }
        else if(ss->size3 != 0 && ((ss->size1 !=0 && ss->size2 != 0 && min(target->bottom, src->top, src->bottom) == src->bottom) 
        || (ss->size2 != 0 && ss->size1 == 0 && src->bottom->value < src->top->value) 
        || (ss->size1 != 0 && ss->size2 == 0 && src->bottom->value < target->bottom->value) || (ss->size1 == 0 && ss->size2 == 0)))
        {
            rreverse(ss->src, stacks);
            push(ss->src, ss->target, stacks);
            ss->size3--;
        }
    }
}

void realupperSort(sortsize *ss, stacks *stacks)
{
    stack *target;
    stack *src;

    while(ss->size1 != 0 || ss->size2 != 0 || ss->size3 != 0)
    {
        target = ss->target; 
        src = ss->src;
        if(ss->size1 != 0 && ((ss->size2 !=0 && ss->size3 != 0 && max(target->bottom, src->top, src->bottom) == target->bottom) 
        || (ss->size3 != 0 && ss->size2 == 0 && target->bottom->value > src->bottom->value) 
        || (ss->size2 != 0 && ss->size3 == 0 && target->bottom->value > src->top->value) || (ss->size2 == 0 && ss->size3 == 0)))
        {
            rreverse(ss->target, stacks);
            ss->size1--;
        }
        else if(ss->size2 != 0 && ((ss->size1 !=0 && ss->size3 != 0 && max(target->bottom, src->top, src->bottom) == src->top) 
        || (ss->size1 != 0 && ss->size3 == 0 && src->top->value > target->bottom->value)
         || (ss->size3 != 0 && ss->size1 == 0 && src->top->value > src->bottom->value) || (ss->size1 == 0 && ss->size3 == 0)))
        {
            push(ss->src, ss->target, stacks);
            ss->size2--;
        }
        else if(ss->size3 != 0 && ((ss->size1 !=0 && ss->size2 != 0 && max(target->bottom, src->top, src->bottom) == src->bottom) 
        || (ss->size2 != 0 && ss->size1 == 0 && src->bottom->value > src->top->value) 
        || (ss->size1 != 0 && ss->size2 == 0 && src->bottom->value > target->bottom->value) || (ss->size1 == 0 && ss->size2 == 0)))
        {
            rreverse(ss->src, stacks);
            push(ss->src, ss->target, stacks);
            ss->size3--;
        }
    }
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

void sort3(sortsize *ss, int shape, stacks *stacks)
{

    push(ss->src, ss->target, stacks);
    reverse(ss->target, stacks);

    ss->size1 = 1;
    ss->size2 = 1;
    ss->size3 = 1;
    if (shape == 1)
        realupperSort(ss, stacks);
    else if (shape == 0)
        reallowerSort(ss, stacks);
}

void make_tri(sortinfo *sortinfo, stacks *stacks)
{
    int i;
    int len;
    int size;
    int shape;
    sortsize *ss;

    len = stacks->a->size;
    i = -1;
    if (sortinfo->len == 9 || sortinfo->len == 81 || sortinfo->len == 729)
    {
        ss = init_sortsize(stacks, 1);
        while(++i < len)
            push(stacks->a, stacks->b, stacks);
    }
    else
        ss = init_sortsize(stacks, 2);
    i = 0;
    while(i < sortinfo->len)
    {   
        size = sortinfo->mergeSize[i];
        shape = sortinfo->triShape[i];
        sorting(size, shape, stacks, ss);
        i++;
    }
}

void sort4(sortsize *ss, int shape, stacks *stacks)
{   
    push(ss->src, ss->target, stacks);
    reverse(ss->target, stacks);

    ss->size1 = 1;
    ss->size2 = 2;
    ss->size3 = 1;
    if(shape == 1)
    {
        if(peek(ss->src->top) < peek(ss->src->top->prev))
            swap(ss->src, stacks);
        realupperSort(ss, stacks);
    }
    else if (shape == 0)
    {
        if(peek(ss->src->top) > peek(ss->src->top->prev))
            swap(ss->src, stacks);
        reallowerSort(ss, stacks);
    }
}

void sort5(sortsize *ss, int shape, stacks *stacks)
{   
    ss->size1 = 2;
    ss->size2 = 2;
    ss->size3 = 1;
    if(shape == 1)
    {
        if(peek(ss->src->top) < peek(ss->src->top->prev))
            swap(ss->src, stacks);
        push(ss->src, ss->target, stacks);
        push(ss->src, ss->target, stacks);
        reverse(ss->target, stacks);
        reverse(ss->target, stacks);
        if (peek(ss->src->top) < peek(ss->src->top->prev))
            swap(ss->src, stacks);
        realupperSort(ss, stacks);
    }
    else if (shape == 0)
    {
        if(peek(ss->src->top) > peek(ss->src->top->prev))
            swap(ss->src, stacks);
        push(ss->src, ss->target, stacks);
        push(ss->src, ss->target, stacks);
        reverse(ss->target, stacks);
        reverse(ss->target, stacks);
        if (peek(ss->src->top) > peek(ss->src->top->prev))
            swap(ss->src, stacks);
        reallowerSort(ss, stacks);
    }
}

void sort2(sortsize *ss, int shape, stacks *stacks)
{
    if(shape == 1)
    {
        if(ss->src->top->value < ss->src->top->prev->value)
            swap(ss->src, stacks);
    }
    else if(shape == 0)
    {
        if(ss->src->top->value > ss->src->top->prev->value)
            swap(ss->src, stacks);
    }
    push(ss->src, ss->target, stacks);
    push(ss->src, ss->target, stacks);
}

void sorting(int size, int shape, stacks *stacks, sortsize *ss)
{
    int     i;

    i = 0;
    if (size < 3)
        sort2(ss, shape, stacks);
    else if (size == 3)
        sort3(ss, shape, stacks);
    else if (size == 4)
        sort4(ss, shape, stacks);
    else if (size == 5)
        sort5(ss, shape, stacks);
    // else if (size == 6)
    //     sort6(stacks, shape);
}

#include "pushswap.h"

int *make_trishape_arr(int *triShape, int len, int *one, int *zero)
{
    int i;
    int j;
    int k;
    int *returnArr;

    i = 0;
    j = 0;
    returnArr = malloc(sizeof(int)*(len * 3));
    while(i < len)
    {
        k = 0;
        if(triShape[i] == 1)
        {
            while (k < 3)
                returnArr[j++] = one[k++];
        }
        else if(triShape[i] == 0)
        {
             while (k < 3)
                returnArr[j++] = zero[k++];
        }
        i++;
    }

    return returnArr;
}

int *init_trishape()
{
    int *arr;
    arr = malloc(sizeof(int) * 3);
    arr[0] = 1;
    arr[1] = 0;
    arr[2] = 0;

    return arr;
}

void make_triShape(int len, sortinfo *sortinfo)
{
    int one[3];
    int zero[3];
    
    one[0] = 1;
    one[1] = 0;
    one[2] = 0;
    zero[0] = 1;
    zero[1] = 1;
    zero[2] = 0;
    if (len == 0){
        sortinfo->triShape = init_trishape();
       return ;
    }
    sortinfo->triShape = make_trishape_arr(sortinfo->triShape, len, one, zero);
}

int *make_mergesize_arr(int *mergeSize, int *arr, int *len)
{
    int *returnArr;
    int i;
    int j;

    i = 0;
    j = 0;
    returnArr = malloc (sizeof(int) * (*len + 3));
    while (i < *len)
    {
        returnArr[i] = mergeSize[i];
        i++;
    }
    while (j < 3)
    {
        returnArr[i] = arr[j];
        j++;
        i++;
    }
    *len = *len + 3;
    free(mergeSize);
    return returnArr;
}

void merge(int size, sortinfo *sortinfo, int *len)
{
    int i;
    int arr[3];

    i = 0;
    arr[0] = size / 3;
    arr[1] = (size - arr[0]) / 2;
    arr[2] = size - arr[0] - arr[1];

    if(arr[0] > 5)
        merge(arr[0], sortinfo, len);
    if(arr[0] > 5 && arr[1] > 5)
        merge(arr[1], sortinfo, len);
    if(arr[0] > 5 && arr[1] > 5 && arr[2] > 5)
        merge(arr[2], sortinfo, len);
    if(arr[0] <=5 || arr[1] <= 5 || arr[2] <= 5)
        sortinfo->mergeSize = make_mergesize_arr(sortinfo->mergeSize, arr, len);
    return ;
}


int mergeSize_and_triShape(int size, sortinfo *sortinfo){
    int len;
    int triLen;

    len = 0;
    triLen = 0;

    merge(size, sortinfo, &len);
    sortinfo->len = len;
    while(triLen != len){
        make_triShape(triLen, sortinfo);
        if (triLen == 0)
            triLen = 3;
        else
            triLen *= 3;
    }
    return (0);
}


char	*ft_strjoin(char *s1, char *s2, int i, int j);
int ft_atoi(char *av);
int isNum(char av);
int num_len(char *arr);
int checkInput(char *av);
int ft_strlen(char *s);

int isNum(char av)
{
    if(av >= '0' && av <= '9')
        return (1);
    return (0);
}

int num_len(char *arr)
{
    int i;
    int cnt;
    int flag;

    i = 0;
    cnt = 0;
    while(arr[i])
    {
        while (arr[i] && arr[i] == ' ')
            i++;
        if(isNum(arr[i]))
            flag = 1;
        while(arr[i] && isNum(arr[i]))
            i++;
        if(flag == 1)
        {
            cnt++;
            flag = 0;
        }
    }
    return (cnt);
}

int check(char **av, stacks *stacks){
    int i;
    char *arr;
    long long *num;

    num = 0;
    i = 1;
    arr = 0;
    while(av[i])
    {
        arr = ft_strjoin(arr, av[i], 0, 0);
        if(!arr)
            return (ft_free(arr, num));
        i++;
    }
    if(!num_check(arr))
        return (ft_free(arr, 0));
    num = malloc(sizeof(long long) * num_len(arr));
    if(!num)
        return (ft_free(arr, num));
    if(!duplicate_check(arr, num))
        return (ft_free(arr, num));
    i = -1;
    while(++i < num_len(arr))
        insertFirst(num[i], stacks->a);
    ft_free(arr, num);
    return (1);
}

int ft_free(void *p1, void *p2)
{
    free(p1);
    free(p2);
    return 0;
}

long makeNum(char **arr)
{
    long long n;

    n = 0;
    while (*(*arr) && isNum(*(*arr)))
    {
        n = n * 10 + *(*arr) - '0';
        (*arr)++;
    }
    return (n);
}

int duplicate_check(char *arr, long long *num)
{
    int i;
    int j;

    i = -1;
    while (*arr)
    {
        j = -1;
        while(*arr && *arr == ' ')
            arr++;
        if(*arr == '\0')
            return(1);
        num[++i] = makeNum(&arr);
        if(num[i] > 2147483647)
            return (0);
        while(++j < i)
        {
            if (num[j] == num[i])
                return (0);
        }
    }
    return (1);
}

int num_check(char *arr)
{
    int i;

    i = 0;
    while(arr[i])
    {
        if(!isNum(arr[i]) && arr[i] != ' ')
            return (0);
        i++;
    }
    return (1);
}

int ft_strlen(char *s)
{
    int i;

    i = 0;
    if(!s)
        return (0);
    while(s[i])
        i++;
    return(i);
}

char	*ft_strjoin(char *s1, char *s2, int i, int j)
{
	char		*arr;

	if (s1 == 0 && s2 == 0)
		return (0);
	arr = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!arr)
	{
		free(s1);
		return (0);
	}
	while (s1 != 0 && s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	while (s2 != 0 && s2[j])
		arr[i++] = s2[j++];
    arr[i++] = ' ';
	arr[i] = '\0';
	free(s1);
	return (arr);
}

stack *init_stack()
{
	stack	*s;

	s = malloc(sizeof(stack));
	if (!s)
		return (0);
	s->size = 0;
	s->top = 0;
	s->bottom = 0;
	return (s);
}	

stacks *init_stacks()
{
    stacks *st;

    st = malloc(sizeof(stacks));
	st->a = init_stack();
	st->b = init_stack();
    st->cnt = 0;

    return st;
}

sortinfo *init_sortinfo()
{
    sortinfo *si;

    si = malloc(sizeof(sortinfo));
	si->len = 0;
	si->mergeSize = 0;
	si->triShape = 0;

    return si;
}


void	init_node(int value, node *node)
{
	node->value = value;
	node->next = 0;
	node->prev = 0;
}

void	insertFirst(int a, stack *s)
{
	node	*n;

	n = malloc(sizeof(node));
	if (!n)
		return ;
	init_node(a, n);
	if (s->size == 0)
	{
		s->top = n;
		s->bottom = n;
		s->size++;
	}
	else
	{
		s->bottom->prev = n;
		n->next = s->bottom;
		n->prev = s->top;
		s->top->next = n;
		s->bottom = n;
		s->size++;
	}
}

void	insert(int a, stack *s)
{
	node	*n;

	n = malloc(sizeof(node));
	if (!n)
		return ;
	init_node(a, n);
	if (s->size == 0)
	{
		s->top = n;
		s->bottom = n;
		s->size++;
	}
	else
	{
		s->top->next = n;
		n->prev = s->top;
		n->next = s->bottom;
		s->bottom->prev = n;
		s->top = n;
		s->size++;
	}
}

int	pop(stack *s)
{
	int		value;
	node	*temp;

	if(s->size == 0)
		return (-1);
	temp = s->top;
	value = temp->value;
	s->size--;
	if(s->size == 1)
	{
		temp->prev->prev = temp->prev;
		temp->prev->next = temp->next;
	}
	else if (s->size > 1)
	{
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
	}
	s->top = temp->prev;
	free(temp);
	return (value);
}

void error()
{
    printf("error\n");
    exit(0);
}

int main(int ac, char **av)
{
	stacks *st;
	sortinfo *si;

	si = init_sortinfo();
	st = init_stacks();

	if ((!st->a || !st->b) || ac < 2)
		exit(0);
	if(!check(av, st))
        error();
    if(!is_sorting(st->a))
    {
	    mergeSize_and_triShape(st->a->size, si);
	    make_tri(si, st);
	    move(si, st);
    int len = st->a->size;
    for(int i = 0; i < len; i++)
        printf("%d\n", pop(st->a));
        printf("%d", st->cnt);
    }
}
