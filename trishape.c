#include "pushswap.h"

int	*make_trishape_arr(int *triShape, int len, int *one, int *zero)
{
	int	i;
	int	j;
	int	k;
	int	*returnArr;

	i = 0;
	j = 0;
	returnArr = malloc(sizeof(int)*(len * 3));
	while (i < len)
	{
		k = 0;
		if (triShape[i] == 1)
		{
			while (k < 3)
				returnArr[j++] = one[k++];
		}
		else if (triShape[i] == 0)
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
	return (arr);
}

void	make_triShape(int len, sortinfo *sortinfo)
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