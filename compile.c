// #include "pushswap.h"

// void sa(stack *s)
// {
//     if (s->size < 2)
//         return;
//     node *top = s->top;
//     node *second = s->top->prev;

//     top->prev = second->prev;
//     second->prev->next = top;

//     second->next = top->next;
//     top->next->prev = second;

//     top->next = second;
//     second->prev = top;

//     s->top = second;

//     // 스택의 맨 아래 노드인 경우, bottom도 변경
//     if (s->size == 2)
//         s->bottom = top;
// }

// void sb(stack *s)
// {
//     if (s->size < 2)
//         return;

//     node *top = s->top;
//     node *second = s->top->prev;

//     top->prev = second->prev;
//     second->prev->next = top;

//     second->next = top->next;
//     top->next->prev = second;

//     top->next = second;
//     second->prev = top;

//     s->top = second;

//     // 스택의 맨 아래 노드인 경우, bottom도 변경
//     if (s->size == 2)
//         s->bottom = top;
// }

// void	pa(stack *b, stack *a)
// {
// 	int	value;

// 	value = pop(b);
// 	if (value == -1)
// 		return ;
// 	insert(value, a);
// }

// void	pb(stack *a, stack *b)
// {
// 	int	value;

// 	value = pop(a);
// 	if (value == -1)
// 		return ;
// 	insert(value, b);
// }

// void	ra(stack *a)
// {
// 	if (a->size == 0)
// 		return ;
// 	a->top = a->top->prev;
// 	a->bottom = a->bottom->prev;
// }

// void	rb(stack *b)
// {
// 	if (b->size == 0)
// 		return ;
// 	b->top = b->top->prev;
// 	b->bottom = b->bottom->prev;
// }

// void	rra(stack *a)
// {
// 	if (a->size == 0)
// 		return ;
// 	a->top = a->top->next;
// 	a->bottom = a->bottom->next;
// }

// void	rrb(stack *b)
// {
// 	if (b->size == 0)
// 		return ;
// 	b->top = b->top->next;
// 	b->bottom = b->bottom->next;
// }

// void	rr(stack *a, stack *b)
// {
// 	ra(a);
// 	rb(b);
// }

// void	rrr(stack *a, stack *b)
// {
// 	rra(a);
// 	rrb(b);
// }

// #include "pushswap.h"

// int make_tri(sortinfo *sortinfo, stacks *stacks)
// {
//     int i;
//     int size;
//     int shape;

//     i = 0;
//     while(i < sortinfo->len)
//     {
//         size = sortinfo->mergeSize[i];
//         shape = sortinfo->triShape[i];
//         sorting(size, shape, stacks);
//         i++;
//     }
//     return 0;
// }

// node *max(node *a, node *b, node *c)
// {
//     node *max;

//     if(a->value > b->value)
//         max = a;
//     else
//         max = b;
//     if(max->value < c->value)
//         return c;
//     else
//         return max;
// }

// node *min(node *a, node *b, node *c)
// {
//     node *min;

//     if(a->value < b->value)
//         min = a;
//     else
//         min = b;
//     if(min->value > c->value)
//         return c;
//     else
//         return min;
// }

// void sort_atop_abottom(node *at, node *ab, stacks *stacks, int shape)
// {
//     if(shape == 1)
//     {
//         if(at->value > ab->value)
//         {
//             pb(stacks->a, stacks->b);
//             rra(stacks->a);
//             pb(stacks->a, stacks->b);
//         }
//         else{
//             rra(stacks->a);
//             pb(stacks->a, stacks->b);
//             pb(stacks->a, stacks->b);
//         }
//     }
//     else
//     {
//         if(at->value < ab->value)
//         {
//             pb(stacks->a, stacks->b);
//             rra(stacks->a);
//             pb(stacks->a, stacks->b);
//         }
//         else{
//             rra(stacks->a);
//             pb(stacks->a, stacks->b);
//             pb(stacks->a, stacks->b);
//         }
//     }

// }
// void sort_atop_bbottom(node *at, node *bb, stacks *stacks, int shape)
// {
//     if(shape == 1)
//     {
//         if(at->value > bb->value)
//         {
//             pb(stacks->a, stacks->b);
//             rrb(stacks->b);
//         }
//         else{
//             rrb(stacks->b);
//             pb(stacks->a, stacks->b);
//             pb(stacks->a, stacks->b);
//         }
//     }
//     else
//     {
//         if(at->value < bb->value)
//         {
//             pb(stacks->a, stacks->b);
//             rrb(stacks->b);
//         }
//         else{
//             rrb(stacks->b);
//             pb(stacks->a, stacks->b);
//             pb(stacks->a, stacks->b);
//         }
//     }
// }
// void sort_abottom_bbottom(node *ab, node *bb, stacks *stacks, int shape)
// {
//     if(shape == 1)
//     {
//         if(ab->value > bb->value)
//         {
//             rra(stacks->a);
//             pb(stacks->a, stacks->b);
//             rrb(stacks->b);
//         }
//         else{
//             rrb(stacks->b);
//             rra(stacks->a);
//             pb(stacks->a, stacks->b);
//         }
//     }
//     else
//     {
//         if(ab->value < bb->value)
//         {
//             rra(stacks->a);
//             pb(stacks->a, stacks->b);
//             rrb(stacks->b);
//         }
//         else{
//             rrb(stacks->b);
//             rra(stacks->a);
//             pb(stacks->a, stacks->b);
//         }
//     }
// }

// void upperSort(node *at, node *bb, node *ab, stacks *stacks)
// {
//     if(max(at, bb, ab) == at){
//         pb(stacks->a,stacks->b);
//         sort_abottom_bbottom(ab, bb, stacks, 1);
//     }
//     else if (max(at, bb, ab) == ab){
//         rra(stacks->a);
//         pb(stacks->a,stacks->b);
//         sort_atop_bbottom(at, bb, stacks, 1);
//     }
//     else if (max(at, bb, ab)== bb)
//     {
//         rrb(stacks->b);
//         sort_atop_abottom(at, ab, stacks, 1);
//     }
// }

// void lowerSort(node *at, node *bb, node *ab, stacks *stacks)
// {
//     if(min(at, bb, ab) == at){
//         pb(stacks->a,stacks->b);
//         sort_abottom_bbottom(ab, bb, stacks, 0);
//     }
//     else if (min(at, bb, ab) == ab){
//         rra(stacks->a);
//         pb(stacks->a,stacks->b);
//         sort_atop_bbottom(at, bb, stacks, 0);
//     }
//     else if (min(at, bb, ab) == bb)
//     {
//         rrb(stacks->b);
//         sort_atop_abottom(at, ab, stacks, 0);
//     }
// }

// void sort3(stacks *stacks, int shape)
// {
//     node *at;
//     node *bb;
//     node *ab;
//     pb(stacks->a, stacks->b);
//     rb(stacks->b);

//     at = stacks->a->top;
//     bb = stacks->b->bottom;
//     ab = stacks->a->bottom;
//     if (shape == 1)
//         upperSort(at, bb, ab, stacks);
//     else if (shape == 0)
//         lowerSort(at,bb,ab,stacks);
// }

// void sorting(int size, int shape, stacks *stacks)
// {
//     int     i;

//     i = 0;
//     if (size == 3)
//         sort3(stacks, shape);
//     // else if (size >= 4 && size <= 5)
//     //     sort4to5(stacks, shape);
//     // else if (size == 6)
//     //     sort6(stacks, shape);
// }

// #include "pushswap.h"

// int *make_trishape_arr(int *triShape, int len, int *one, int *zero)
// {
//     int i;
//     int j;
//     int k;
//     int *returnArr;

//     i = 0;
//     j = 0;
//     returnArr = malloc(sizeof(int)*(len * 3));
//     while(i < len)
//     {
//         k = 0;
//         if(triShape[i] == 1)
//         {
//             while (k < 3)
//                 returnArr[j++] = one[k++];
//         }
//         else if(triShape[i] == 0)
//         {
//              while (k < 3)
//                 returnArr[j++] = zero[k++];
//         }
//         i++;
//     }

//     return returnArr;
// }

// int *init_trishape()
// {
//     int *arr;
//     arr = malloc(sizeof(int) * 3);
//     arr[0] = 1;
//     arr[1] = 0;
//     arr[2] = 0;

//     return arr;
// }

// void make_triShape(int len, sortinfo *sortinfo)
// {
//     int one[3];
//     int zero[3];
    
//     one[0] = 1;
//     one[1] = 0;
//     one[2] = 0;
//     zero[0] = 1;
//     zero[1] = 1;
//     zero[2] = 0;
//     if (len == 0){
//         sortinfo->triShape = init_trishape();
//        return ;
//     }
//     sortinfo->triShape = make_trishape_arr(sortinfo->triShape, len, one, zero);
// }

// int *make_mergesize_arr(int *mergeSize, int *arr, int *len)
// {
//     int *returnArr;
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     returnArr = malloc (sizeof(int) * (*len + 3));
//     while (i < *len)
//     {
//         returnArr[i] = mergeSize[i];
//         i++;
//     }
//     while (j < 3)
//     {
//         returnArr[i] = arr[j];
//         j++;
//         i++;
//     }
//     *len = *len + 3;
//     free(mergeSize);
//     return returnArr;
// }

// void merge(int size, sortinfo *sortinfo, int *len)
// {
//     int i;
//     int arr[3];

//     i = 0;
//     arr[0] = size / 3;
//     arr[1] = (size - arr[0]) / 2;
//     arr[2] = size - arr[0] - arr[1];

//     if(arr[0] > 5)
//         merge(arr[0], sortinfo, len);
//     if(arr[0] > 5 && arr[1] > 5)
//         merge(arr[1], sortinfo, len);
//     if(arr[0] > 5 && arr[1] > 5 && arr[2] > 5)
//         merge(arr[2], sortinfo, len);
//     if(arr[0] <=5 || arr[1] <= 5 || arr[2] <= 5)
//         sortinfo->mergeSize = make_mergesize_arr(sortinfo->mergeSize, arr, len);
//     return ;
// }


// int mergeSize_and_triShape(int size, sortinfo *sortinfo, stacks *stacks){
//     int len;
//     int triLen;

//     len = 0;
//     triLen = 0;

//     merge(size, sortinfo, &len);
//     sortinfo->len = len;
//     char a = stacks->a->size + '0';
// 	write(1, &a, 1);
//     while(triLen != len){
//         make_triShape(triLen, sortinfo, stacks);
//         if (triLen == 0)
//             triLen = 3;
//         else
//             triLen *= 3;
//     }
//     return (0);
// }

// #include <stdlib.h>
// #include <stdio.h>
// #include "pushswap.h"

// char	*ft_strjoin(char *s1, char *s2, int i, int j);
// int ft_atoi(char *av);
// int isNum(char av);
// int num_len(char *arr);
// int checkInput(char *av);
// int ft_strlen(char *s);

// int isNum(char av)
// {
//     if(av >= '0' && av <= '9')
//         return (1);
//     return (0);
// }

// int num_len(char *arr)
// {
//     int i;
//     int cnt;
//     int flag;

//     i = 0;
//     cnt = 0;
//     while(arr[i])
//     {
//         while (arr[i] && arr[i] == ' ')
//             i++;
//         if(isNum(arr[i]))
//             flag = 1;
//         while(arr[i] && isNum(arr[i]))
//             i++;
//         if(flag == 1)
//         {
//             cnt++;
//             flag = 0;
//         }
//     }
//     return (cnt);
// }

// int check(char **av, stacks *stacks){
//     int i;
//     char *arr;
//     long long *num;

//     num = 0;
//     i = 1;
//     arr = 0;
//     while(av[i])
//     {
//         arr = ft_strjoin(arr, av[i], 0, 0);
//         if(!arr)
//             return (ft_free(arr, num));
//         i++;
//     }
//     if(!num_check(arr))
//         return (ft_free(arr, 0));
//     num = malloc(sizeof(long long) * num_len(arr));
//     if(!num)
//         return (ft_free(arr, num));
//     if(!duplicate_check(arr, num))
//         return (ft_free(arr, num));
//     i = -1;
//     while(++i < num_len(arr))
//         insertFirst(num[i], stacks->a);
//     ft_free(arr, num);
//     return (1);
// }

// int ft_free(void *p1, void *p2)
// {
//     free(p1);
//     free(p2);
//     return 0;
// }

// long makeNum(char **arr)
// {
//     long long n;

//     n = 0;
//     while (*(*arr) && isNum(*(*arr)))
//     {
//         n = n * 10 + *(*arr) - '0';
//         (*arr)++;
//     }
//     return (n);
// }

// int duplicate_check(char *arr, long long *num)
// {
//     int i;
//     int j;

//     i = -1;
//     while (*arr)
//     {
//         j = -1;
//         while(*arr && *arr == ' ')
//             arr++;
//         if(*arr == '\0')
//             return(1);
//         num[++i] = makeNum(&arr);
//         if(num[i] > 2147483647)
//             return (0);
//         while(++j < i)
//         {
//             if (num[j] == num[i])
//                 return (0);
//         }
//     }
//     return (1);
// }

// int num_check(char *arr)
// {
//     int i;

//     i = 0;
//     while(arr[i])
//     {
//         if(!isNum(arr[i]) && arr[i] != ' ')
//             return (0);
//         i++;
//     }
//     return (1);
// }

// int ft_strlen(char *s)
// {
//     int i;

//     i = 0;
//     if(!s)
//         return (0);
//     while(s[i])
//         i++;
//     return(i);
// }

// char	*ft_strjoin(char *s1, char *s2, int i, int j)
// {
// 	char		*arr;

// 	if (s1 == 0 && s2 == 0)
// 		return (0);
// 	arr = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
// 	if (!arr)
// 	{
// 		free(s1);
// 		return (0);
// 	}
// 	while (s1 != 0 && s1[i])
// 	{
// 		arr[i] = s1[i];
// 		i++;
// 	}
// 	while (s2 != 0 && s2[j])
// 		arr[i++] = s2[j++];
//     arr[i++] = ' ';
// 	arr[i] = '\0';
// 	free(s1);
// 	return (arr);
// }

// #include <stdio.h>
// #include "pushswap.h"

// stack *init_stack()
// {
// 	stack	*s;

// 	s = malloc(sizeof(stack));
// 	if (!s)
// 		return (0);
// 	s->size = 0;
// 	s->top = 0;
// 	s->bottom = 0;
// 	return (s);
// }	

// stacks *init_stacks()
// {
//     stacks *st;

//     st = malloc(sizeof(stacks));
// 	st->a = init_stack();
// 	st->b = init_stack();

//     return st;
// }

// sortinfo *init_sortinfo()
// {
//     sortinfo *si;

//     si = malloc(sizeof(sortinfo));
// 	si->len = 0;
// 	si->mergeSize = 0;
// 	si->triShape = 0;

//     return si;
// }


// void	init_node(int value, node *node)
// {
// 	node->value = value;
// 	node->next = 0;
// 	node->prev = 0;
// }


// void	insertFirst(int a, stack *s)
// {
// 	node	*n;

// 	n = malloc(sizeof(node));
// 	if (!n)
// 		return ;
// 	init_node(a, n);
// 	if (s->size == 0)
// 	{
// 		s->top = n;
// 		s->bottom = n;
// 		s->size++;
// 	}
// 	else
// 	{
// 		s->bottom->prev = n;
// 		n->next = s->bottom;
// 		n->prev = s->top;
// 		s->top->next = n;
// 		s->bottom = n;
// 		s->size++;
// 	}
// }

// void	insert(int a, stack *s)
// {
// 	node	*n;

// 	n = malloc(sizeof(node));
// 	if (!n)
// 		return ;
// 	init_node(a, n);
// 	if (s->size == 0)
// 	{
// 		s->top = n;
// 		s->bottom = n;
// 		s->size++;
// 	}
// 	else
// 	{
// 		s->top->next = n;
// 		n->prev = s->top;
// 		n->next = s->bottom;
// 		s->bottom->prev = n;
// 		s->top = n;
// 		s->size++;
// 	}
// }


// int	pop(stack *s)
// {
// 	int		value;
// 	node	*temp;

// 	if(s->size == 0)
// 		return (-1);
// 	temp = s->top;
// 	value = temp->value;
// 	s->size--;
// 	if(s->size == 1)
// 	{
// 		temp->prev->prev = 0;
// 		temp->prev->next = 0;
// 	}
// 	else if (s->size > 1)
// 	{
// 		temp->next->prev = temp->prev;
// 		temp->prev->next = temp->next;
// 	}
// 	s->top = temp->prev;
// 	free(temp);
// 	return (value);
// }

// int	peekTop(node *n)
// {
// 	int		value;

// 	if (!n)
// 		return (-1);
// 	value = n->value;
// 	return (value);
// }




// int main(int ac, char **av){

// 	stacks *st;
// 	sortinfo *si;

// 	si = init_sortinfo();
// 	st = init_stacks();

		
// 	if ((!st->a || !st->b) || ac < 2)
// 		exit(0);
// 	if(!check(av, st))
// 	{
// 		printf("error\n");
// 		exit(0);
// 	}
// 	mergeSize_and_triShape(st->a->size, si, st);
// 	// for(int i = 0; i < 6; i++){
// 	// 	int a = pop(stacks->a) + '0';
// 	// 	write(1, &a, 2);
// 	// }
// 	// make_tri(sortinfo, stacks);
// }



