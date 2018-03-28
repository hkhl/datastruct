/*************************************************************************
	> File Name: mergesort.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年03月28日 星期三 21时08分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>


void MergeArray(int a[], int first, int mid, int last)
{
    int *temp = (int *)malloc(sizeof(int) * (last - first + 1));
    int i = first, j = mid+1;
    int m = mid, n = last;
    int k = 0;

    while(i <= m && j <= n)
    {
        if(a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= m)
        temp[k++] = a[i++];
    while(j <= n)
        temp[k++] = a[j++];
    for(i = 0; i < k; i++)
    {
        a[first+i] = temp[i];
    }
    free(temp);
}

void MergeSort(int a[], int first, int last)
{
    if(first < last)
    {
        int mid = (first + last) / 2;
        MergeSort(a, first, mid);
        MergeSort(a, mid+1, last);
        MergeArray(a, first, mid, last);
    }
}


int main()
{
    int nums[] = {4,3,2,5,1,6,7,9,3,43,2,1};
    //int nums[] = {4,1,2,3};
    int size = sizeof(nums) / sizeof(int);

    MergeSort(nums, 0, size-1);

    for(int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
