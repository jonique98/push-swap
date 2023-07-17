#include <stdlib.h>
#include <stdio.h>
#include "pushswap.h"



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

int check(char **av, stack *a){
    int i;
    char *arr;
    int *num;

    i = 1;
    arr = 0;
    while(av[i]){
        arr = ft_strjoin(arr, av[i], 0, 0);
        if(!arr)
            return (ft_free(arr, num));
        i++;
    }
    if(!num_check(arr))
        return (ft_free(arr, 0));
    num = malloc(sizeof(int) * num_len(arr));
    if(!num)
        return (ft_free(arr, num));
    if(!duplicate_check(arr, num))
        return (ft_free(arr, num));
    i = -1;
    while(++i < num_len(arr))
        insertstack(num[i], a);
    ft_free(arr, num);
    return (1);
}

int ft_free(void *p1, void *p2)
{
    free(p1);
    free(p2);
    return 0;
}

int makeNum(char **arr)
{
    int n;

    n = 0;
    while(*(*arr) && isNum(*(*arr)))
        {
            n = n * 10 + *(*arr) - '0';
            (*arr)++;
        }
    return (n);
}

int duplicate_check(char *arr, int *num)
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

int ft_strlen(char *s){
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