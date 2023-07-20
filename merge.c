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