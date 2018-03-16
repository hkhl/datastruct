/*************************************************************************
	> File Name: Queue1.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月11日 星期六 10时31分40秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int capacity;       
    int front;
    int rear;
    int size;
    int data[0];
}Queue;

Queue * Init(Queue *Q, int length);
int IsEmpty(Queue *Q);
int IsFull(Queue *Q);
int EnQueue(Queue *Q, int x);
int DeQueue(Queue *Q, int *x);
int FreeAll(Queue *Q);

int main()
{
    Queue *queue = NULL;
    queue = Init(queue, 5);
    if(IsEmpty(queue))
        printf("empty\n");

    EnQueue(queue, 1);
    EnQueue(queue, 2);
    EnQueue(queue, 3);
    EnQueue(queue, 4);

    printf("Q->front = %d  Q->rear  = %d   Q->size = %d\n", queue->front, queue->rear, queue->size);
    EnQueue(queue, 5);
    if(IsFull(queue))
        printf("full\n");

    int x = 0;
    DeQueue(queue, &x);
    printf("x = %d\n", x);
    DeQueue(queue, &x);
    printf("x = %d\n", x);
    printf("Q->front = %d  Q->rear  = %d   Q->size = %d\n", queue->front, queue->rear, queue->size);
    EnQueue(queue, 9);

    return 0;
}

Queue * Init(Queue *Q, int length)
{
    Q = (Queue *)malloc(sizeof(Queue) + length*sizeof(int));
    if(Q)
    {
        Q->capacity = length;
        Q->size = 0;
        Q->front = 0;
        Q->rear = 0;
        return Q;
    }
    else
        return NULL;
}

int IsEmpty(Queue *Q)
{
    if(Q->size)
        return 0;
    else
        return 1;
}

int IsFull(Queue *Q)
{
    if(Q->size == Q->capacity)
        return 1;
    else
        return 0;
}

int EnQueue(Queue *Q, int x)
{
    if(IsFull(Q))
        return 0;
    else
    {
        Q->data[Q->rear] = x;
        Q->rear++;
        if(Q->rear == Q->capacity)
            Q->rear = 0;
        Q->size++;
        return 1;
    }
}

int DeQueue(Queue *Q, int *x)
{
    if(IsEmpty(Q))
        return 0;
    else
    {
        *x = Q->data[Q->front];
        Q->front++;
        if(Q->front == Q->capacity)
            Q->front = 0;
        Q->size--;
        return 1;
    }
}

int FreeAll(Queue *Q)
{
    free(Q);
    Q = NULL;
    return 1;
}
