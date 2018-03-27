/*************************************************************************
	> File Name: insertsort.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年03月27日 星期二 17时52分02秒
 ************************************************************************/

/*插入排序*/
#include <stdio.h>

void InsertSort(int a[], int size)
{

    for(int i = 1; i < size; i++)
    {
        int j = i-1;
        int temp = a[i];
        for(;j>= 0 && a[j] > temp; j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = temp;
    }
}

int main()
{
    int nums[] = {4,3,2,5,1,6,7,9,0,43,2,1};
    int size = sizeof(nums) / sizeof(int);

    InsertSort(nums, size);

    for(int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
