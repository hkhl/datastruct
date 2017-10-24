/*************************************************************************
	> File Name: stacklinknode.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月24日 星期二 17时14分09秒
 ************************************************************************/
//链式栈
#include<stdio.h>
#include<stdlib.h>

typedef int datatype;
typedef struct Stacknode
{
    datatype data;
    struct Stacknode *pNext;

}StackNode;

int IsEmpty(StackNode *phead);                          //判空
void PrintAll(StackNode *phead);                        //打印
StackNode * Init(StackNode *phead);                     //初始化
StackNode * Push(StackNode *phead, datatype data);      //入栈
StackNode * Pop(StackNode *phead, datatype *data);      //出栈
StackNode * FreeAll(StackNode *phead);                  //销毁

int main()
{
    StackNode *phead = NULL;
    phead = Init(phead);

    for(int i = 0; i < 5; i++)
    {
        phead = Push(phead, i);
    }
    PrintAll(phead);

    printf("\n出栈:\n");
    datatype x = 0;
    while(phead != NULL)
    {
        phead = Pop(phead, &x);
        printf("%d \n", x);
    }
    phead = FreeAll(phead);
    PrintAll(phead);

    return 0;
}

int IsEmpty(StackNode *phead)  //为空返回1 不为空返回0
{
    if(phead == NULL)
    {
        return 1; 
    }
    else
    {
        return 0;
    }
}

StackNode * Init(StackNode *phead)
{
    return phead = NULL;    
}

StackNode * Push(StackNode *phead, datatype data)
{
    StackNode *newnode= (StackNode *)malloc(sizeof(StackNode));
    if(newnode == NULL)
    {
        printf("节点申请失败\n");
        return NULL;
    }
    else
    {
        newnode->data = data;
        newnode->pNext = NULL;
        if(phead == NULL)
        {
            phead = newnode;
        }
        else
        {
            StackNode *p = phead;
            while(p->pNext != NULL)
            {
                p = p->pNext;
            }
            p->pNext = newnode;
        }
        return phead;
    }
}

StackNode * Pop(StackNode *phead, datatype *data)
{
    if(!IsEmpty(phead))
    {
        if(phead->pNext == NULL)   //弹出第一个栈底元素
        {
            *data = phead->data;
            free(phead);
            phead = NULL;
        }
        else                       //弹出其余元素
        {
            StackNode *p = phead;
            while(p->pNext->pNext != NULL)
            {
                p = p->pNext;
            }
            *data = p->pNext->data;
            free(p->pNext);
            p->pNext = NULL;
        }
        return phead;
    }
    else
    {
        printf("栈空\n");
        return NULL;
    }
}

void PrintAll(StackNode *phead)
{
    if(!IsEmpty(phead))
    {
        while(phead)
        {
            printf("%d ", phead->data);
            phead = phead->pNext;
        }
        printf("\n");
    }
    else
    {
        printf("栈空\n");
    }
}

StackNode * FreeAll(StackNode *phead)
{
    if(phead == NULL)
    {
        return NULL;
    }
    else
    {
        StackNode *p = phead;
        StackNode *q = NULL;

        while(p->pNext != NULL)
        {
            q = p->pNext;
            p->pNext = q->pNext; 
            free(q);
        }
        free(phead);
        phead = NULL;
        return phead;
    }
}

