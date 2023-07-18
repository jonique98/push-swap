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

int *hi(int *triShape, int *trilen)
{
    
}

void make_trishape_arr(int size, int **triShape, int *trilen)
{
    int arr[3];

    arr[0] = size / 3;
    arr[1] = (size - arr[0]) / 2;
    arr[2] = size - arr[0] - arr[1];

    if(arr[0] > 5)
    {
        *trilen = *trilen + 3;
        merge(arr[0], triShape, trilen);
    }
    if(arr[1] > 5)
    {
        *trilen = *trilen + 3;
        merge(arr[1], triShape, trilen);
    }
    if(arr[2] > 5)
    {
        *trilen = *trilen + 3;
        merge(arr[2], triShape, trilen);
    }

    return ;
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
    if(arr[1] > 5)
        merge(arr[1], mergeSize, len);
    if(arr[2] > 5)
        merge(arr[2], mergeSize, len);
    if(arr[0] <=5 && arr[1] <=5 && arr[2] <= 5)
        *mergeSize = make_mergesize_arr(*mergeSize, arr, len);
    return ;
}



int main(){
    int *a;
    int b[3];
    int len;
    len = 0;
    int triLen;
    triLen = 0;
    a = 0;
    b[0] = 1;
    b[1] = 0;
    b[2] = 0;

    merge(34, &a ,&len);
    make_trishape_arr(34, &b, &triLen);
    printf("%d\n", len);
    for(int i = 0; i < len; i++)
        printf("%d ", a[i]);
}