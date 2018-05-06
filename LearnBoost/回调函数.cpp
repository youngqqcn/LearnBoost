#if 0
#define _CRT_SECURE_NO_WARNINGS  

/**
 *Date: 2017/11/19 11:53
 *Author:yqq
 *Descriptions:none
 */

#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

int Comp(const void *a, const void *b)
{
	return *(int*)a - *(int *)b;
}


int main(void)  
{  

	int arr[5] = { 5, 2, 8, -1, 11 };
	qsort((void *)arr, 5, sizeof(arr[0]), Comp);

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		printf("%d\t", arr[i]);
	}
  
    printf("\n");  
    system("pause");  
    return 0;  
}  
#endif