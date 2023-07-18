#include "pushswap.h"

int *make_mergesize_arr(int *mergeSize, int *arr, int *len)
{
    int *returnArr;
    int i;
    int j;

    i = 0;
    j = 0;
    returnArr = malloc (sizeof(int) * (*len + 3));
    while (i < (*len))
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

int *make_trishape_arr(int *triShape, int *trilen, int *one, int *zero)
{
    int i;
    int j;
    int k;
    int *returnArr;

    i = 0;
    j = 0;
    returnArr = malloc(sizeof(int)*(*trilen * 3));
    while(i < *trilen)
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
    *trilen *= 3;
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

void make_triShape(int **triShape, int *trilen)
{
    int one[3];
    int zero[3];
    
    one[0] = 1;
    one[1] = 0;
    one[2] = 0;
    zero[0] = 1;
    zero[1] = 1;
    zero[2] = 0;
    if (!(*triShape)){
       *triShape = init_trishape();
       *trilen = 3;
        return ;
    }
    *triShape = make_trishape_arr(*triShape, trilen, one, zero);
}

void merge(int size, int **mergeSize, int *len)
{
    int i;
    int arr[3];

    i = 0;
    arr[0] = size / 3;
    arr[1] = (size - arr[0]) / 2;
    arr[2] = size - arr[0] - arr[1];

    if(arr[0] > 5)
        merge(arr[0], mergeSize, len);
    if(arr[0] > 5 && arr[1] > 5)
        merge(arr[1], mergeSize, len);
    if(arr[0] > 5 && arr[1] > 5 && arr[2] > 5)
        merge(arr[2], mergeSize, len);
    if(arr[0] <=5 || arr[1] <= 5 || arr[2] <= 5)
        *mergeSize = make_mergesize_arr(*mergeSize, arr, len);
    return ;
}



int mergeSize_and_triShape(int **mergeSize, int **triShape, int *len, int size){
    int triLen;

    triLen = 0;
    *mergeSize = 0;
    *triShape = 0;

    merge(316, mergeSize ,len);
    while(triLen != *len)
        make_triShape(triShape, &triLen);
    return (0);
}