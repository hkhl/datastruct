/*************************************************************************
	> File Name: heapsort.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年03月28日 星期三 18时08分40秒
 ************************************************************************/
/*堆排序*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int parent(int);
int left(int);
int right(int);
void HeapAdjust(int[], int, int);
void BuildHeap(int [], int);
void print(int [], int);
void HeapSort(int [], int);

/* 返回父亲节点 */
int parent(int i)
{
    return  (int)floor((i-1) / 2);
}

/* 返回左孩子 */
int left(int i)
{
    return (2*i+1);
}


/* 返回右孩子 */
int right(int i)
{
    return (2*i+2);
}



/*传入某一节点,调整为大根堆(3个节点的堆)*/
void HeapAdjust(int a[], int i, int heap_size)
{
    int l = left(i);
    int r = right(i);
    int largest;
    int temp;

    if(l < heap_size && a[l] > a[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if(r < heap_size && a[r] > a[largest]) 
    {
        largest = r;
    }

    if(largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        HeapAdjust(a, largest, heap_size);
    }
}

/* 建立最大堆 */
void BuildHeap(int a[], int heap_size)
{
    for(int i = (heap_size-2)/2; i >= 0; i--)
    {
        HeapAdjust(a, i, heap_size);
    }
}

void print(int a[], int heap_size)
{
    for(int i = 0; i < heap_size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}


/* 堆排序 */

void HeapSort(int a[], int heap_size)
{
    BuildHeap(a, heap_size);
    int temp;
    for(int i = heap_size - 1; i >= 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        HeapAdjust(a, 0, i);
    }
    print(a, heap_size);
}

int main(int argc, char *argv[])
{
    int a[] = {19, 1, 10, 14, 16, 4, 7, 9, 3, 2, 8, 5, 11};
    int heap_size = sizeof(a) / sizeof(int);

    HeapSort(a, heap_size);

    return 0;
}
