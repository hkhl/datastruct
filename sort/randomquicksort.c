/*************************************************************************
	> File Name: randomquicksort.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年03月27日 星期二 17时58分45秒
 ************************************************************************/
/*qsort*/
#include <stdio.h>
#include <stdlib.h>

/*优化*/

void Swap(int *num1, int *num2)
{
    if(num1 == num2)
        return;
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int Rand(int low, int high)
{
    int num = rand()%(high-low+1);

    return num+low;
    
}
int RandomPatition(int a[], int left, int right)
{
    //Swap(&a[Rand(left, right)], &a[left]);
    int key = a[left];

    int i = left;
    for(int j = i+1; j <= right; j++)
    {
        if(a[j] < key)   //有没有等号都可以
        {
            i++;
            Swap(&a[i], &a[j]);
        }
    }
    Swap(&a[left], &a[i]);

    return i;
}

void QuickSort(int a[], int left, int right)
{
    
    int k = 0;
    if(left < right)
    {
        k = RandomPatition(a, left, right);
        QuickSort(a, left, k-1);
        QuickSort(a, k+1, right);
    }
}


int main()
{
    //int nums[] = {3,2,6,3,4,3,1,5,6,3};
    int nums[] = {3,2,6,3,4,5};
    int size = sizeof(nums) / sizeof(int);

    QuickSort(nums, 0, size-1);

    for(int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
