/*************************************************************************
	> File Name: linklist.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月23日 星期六 14时40分12秒
 ************************************************************************/
//链表
#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct node
{
    ElementType data;
    struct node *next;
}Node;

typedef Node *List;

//创建空链表
List MakeEmpty(Node **L)
{
    (*L) = (Node *)malloc(sizeof(Node));   //申请结点空间 
    if(*L == NULL)                       
    {
        printf("申请内存空间失败\n");
        return NULL;
    }
    (*L)->next = NULL;                     //将next设置为NULL,初始长度为0的单链表 
    (*L)->data = 0;
    printf("创建链表成功\n");
    return *L;
}


//打印函数
List PrintList(Node *L)
{
    while(L != NULL)
    {
        printf("%d \n", L->data);
        L = L->next;
    }
    return L;
}

//头插法
List InsertHead(Node **L, ElementType x)
{
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->next = *L;
    
    *L = p;

    return p;
}

//尾插法
List InsertTail(Node **L,ElementType x)
{

    Node *pl = *L;

    while(pl->next != NULL)
    {
        pl = pl->next;
    }
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    p->data = x;
    pl->next = p;
    return *L;
/*
    while((*L)->next != NULL)
    {
        *L = (*L)->next;
    }
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    p->data = x;
    (*L)->next = p;
    return *L;
  */  
}

List InsertMid(Node *L, ElementType n, ElementType x)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = x;
    while(n-1)
    {
        L = L->next;
        n--;
    }
    p->next = L->next;
    L->next = p;
    return L;
}
List Delete(Node *L, ElementType n)
{
    while(n-2)
    {
        L = L->next;
        n--;
    }
    L->next = L->next->next;
}

int main()
{
    List list; 
    MakeEmpty(&list);
    printf("%p\n", list);
    InsertTail(&list, 10);
    printf("%p\n", list);
    InsertTail(&list, 10);
    printf("%p\n", list);
    InsertTail(&list, 10);
    printf("%p\n", list);

    InsertHead(&list, -10);   //-10 0 10 10
    printf("%p\n", list);
    InsertMid(list, 3, 111); 
    Delete(list, 2);

    PrintList(list);

    return 0;
}
