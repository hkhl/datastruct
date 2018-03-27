/*************************************************************************
	> File Name: quicksort.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年03月27日 星期二 17时58分45秒
 ************************************************************************/
/*qsort*/
#include <stdio.h>



/*未优化 版本1*/
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void QuickSort(int a[], int left, int right)
{
    int i, j, key;
    if(left  < right)
    {
        i = left;
        key = a[left];

        for(int j = i+1; j <= right; j++ )
        {
            if(a[j] <= key)
            {
                i++;
                Swap(&a[i],& a[j]);
            }
        }
        Swap(&a[i],& a[left]);
        QuickSort(a, left, i-1);
        QuickSort(a, i+1, right);
    }
}
   //版本2
void QuickSort1(int a[], int left, int right)
{
int i, j, temp;
    if(left < right)
    {
        i = left;
        j = right;
        temp = a[left];

        do
        {
            while(a[j] >= temp && i < j)
            j--;
            if(i < j)
            {
                a[i] = a[j];
                i++;
            }

            while(a[i] <= temp && i < j)
                i++;
            if(i < j)
            {
                a[j] = a[i];
                j--;
            }
        }while(i != j);
        //当跳出时 i == j 指向的位置放temp

        a[i] = temp;
        QuickSort1(a, left, i-1);
        QuickSort1(a, i+1, right);
    }
}

int main()
{
    int nums[] = {4,3,2,5,1,6,7,9,0,43,2,1};
    int size = sizeof(nums) / sizeof(int);

    QuickSort(nums, 0, size-1);

    for(int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}
