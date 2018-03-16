/*************************************************************************
	> File Name: queue.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月25日 星期三 19时19分19秒
 ************************************************************************/

//循环队列的简单实现
//队尾插数据 队头删数据

//队空: front == rear
//队满: 保留一个元素为空 使得 (rear+1)%QueueSize == front

#include<stdio.h>
#define MAXSIZE 6

typedef int ElemType;

typedef struct
{
    int front;                  //头指针
    int rear;                   //尾指针,若队列不空,指向尾元素的下一个元素
    ElemType data[MAXSIZE];     //队列中的数据
}SqQueue;

void InitQueue(SqQueue *Q);                 //初始化队列
int IsEmpty(SqQueue *Q);                    //判空 队空返回1 非空返回0
int IsFull(SqQueue *Q);                     //判满 队满返回1 非满返回0(保留一个空元素)
int EnQueue(SqQueue *Q, ElemType data);     //入队 成功返回1 失败返回0
int DeQueue(SqQueue *Q, ElemType *data);    //出队 成功返回1 失败返回0 出队元素赋值给*data
int QueueLength(SqQueue *Q);                //队长 返回队列元素个数
ElemType GetHead(SqQueue *Q);               //获取队首元素

int main()
{
    SqQueue myqueue;
    InitQueue(&myqueue);
    for(int i = 0; i < 3; i++)
    {
        EnQueue(&myqueue, i+1);
    }

    printf("队长: %d\n", QueueLength(&myqueue));
    ElemType data = 0;
    DeQueue(&myqueue, &data);
    printf("出队元素: %d\n", data);
    printf("队长: %d\n", QueueLength(&myqueue));
    data = GetHead(&myqueue);
    printf("目前对首元素是: %d\n", data);

    return 0;
}

void InitQueue(SqQueue *Q)
{
    Q->front = Q->rear = 0;
}

int IsEmpty(SqQueue *Q)
{
    if(Q->rear == Q->front)
    {
        return 1;
    }
    return 0;
}

int IsFull(SqQueue *Q)
{
    if((Q->rear+1)%MAXSIZE == Q->front)
    {
        return 1;
    }
    return 0;
}

ElemType GetHead(SqQueue *Q)
{
    return Q->data[Q->front];
}

int EnQueue(SqQueue *Q, ElemType data)
{
    if(!IsFull(Q))
    {
        Q->data[Q->rear] = data;
        Q->rear = (Q->rear + 1)%MAXSIZE;  //rear指针后移动
        return 1;
    }
    return 0;
}

int DeQueue(SqQueue *Q, ElemType *data)
{
    if(!IsEmpty(Q))
    {
        *data = Q->data[Q->front];
        Q->front = (Q->front + 1)%MAXSIZE;
        return 1;
    }
    return 0;
}

int QueueLength(SqQueue *Q)
{
    return  (Q->rear-Q->front+MAXSIZE)%MAXSIZE;
}

