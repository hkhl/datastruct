/*************************************************************************
	> File Name: head_linklist.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月23日 星期六 19时35分50秒
 ************************************************************************/
//带头节点的链表
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef int ElementType;
typedef struct node
{
    ElementType data;
    struct node *next;

}Node;

//创建空链表
Node *CreateEmptyList(Node **head)
{
    //头节点创建方式不正确- -
    *head = (Node *)malloc(sizeof(Node));
    (*head)->next = NULL;
    return *head;
}

//末尾创建一个节点
Node *CreadNode(Node **head)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if(node == NULL)
    {
        printf("创建节点失败\n");
    }
    node->next = NULL;

    Node *p = *head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->data = 0;
    p->next = node;
    return *head;
}

//返回链表头
Node *GetHead(Node *head)
{
    return head;
}

//返回列表第一个节点
Node *GetFirstNode(Node *head)
{
    return  head->next;
}

//前进到下一节点
void NextNod(Node **head)
{
     (*head) = (*head)->next;
}

//返回节点p的元素  //例如节点3  第3个节点 num = 3
ElementType GetElem(Node *head, int num)
{
    while(num)     
    {  
        head = head->next;
        num--;
    }
    return head->data;
}

//打印链表
void PrintList(Node *head)
{
    if(head == NULL)
    {
        printf("链表为空\n");
        return ;
    }
    head = head->next;
    while(head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    putchar(10);
}

//判断链表是否为空
//空返回0 非空返回1 错误-1
int JudgeEmpty(Node *head)
{
    if(head->next)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    return -1;
}

//该节点是否为链表最后一个节点
//是返回1  不是返回0 错误-1(表空)
int IsLastNode(Node *head, int num)
{
    if(!JudgeEmpty(head))
    {
        return -1;
    }
    
    head = head->next;

    while(num)
    {
        head = head->next;
        if(head->next == NULL)
        {
            break;
        }
        num--;
    }
    if(num != 0)
    {
        return 0;
    }
    else
    {
       if(head->next == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

//找出元素在列表中的位置
//返回第一次出现的节点位置
//没找到返回0
int GetPosition(Node *head ,ElementType x)
{
    int num = 0;
    while(1)
    {
        head = head->next;
        num++;
        if(head->data == x)
        {
            return num;
        }
        if(head->next == NULL)
        {
            break;
        }
    }
    return 0;
}

//找出元素在列表中的位置
//返回第一次出现的节点位置减1
//没找到返回-1
int GetProPosition(Node *head ,ElementType x)
{
    int num = 0;
    while(1)
    {
        head = head->next;
        num++;
        if(head->data == x)
        {
            return num-1;
        }
        if(head->next == NULL)
        {
            break;
            num = 0;
        }
    }
    return num-1;
}

//删除链表中的某个元素 E
void DeleteElement(Node *head, ElementType E)
{
    int flag = 0;
    while(head)
    {
        if(head->next->data == E)
        {
            Node *p = head;
            flag = 1;
            Node *del = head->next;
            head->next = head->next->next; 
            free(del);
            break;
        }


        head = head->next;
    }
    if(flag == 0)
    {
        printf("删除失败, 没有此值\n");
        return; 
    }
}

//删除整个链表
void DeleteList(Node **head)
{
    Node *p1,*p2;
    p1 = p2 = NULL;
    p1 = *head;
    //删除头节点后的其他节点
    while(p1->next != NULL)
    {
        p2 = p1->next;
        p1->next = p2->next;
        free(p2);
        p2 = NULL;
        printf("\n\n");
        PrintList(*head);
    }
    //删除头节点
    free(*head);
    *head = NULL;
}

//在链表某个节点之后插入元素E
//第n和节点之后插入元素
void InsetElement(Node *head, int n, ElementType E)
{
    while(n)
    {
        head = head->next;
        n--;
    }
    
    Node *node = (Node *)malloc(sizeof(Node)); 
    node->next = NULL;
    node->data = E;

    node->next = head->next;
    head->next = node;
}


//实现链表的逆转
void transrev(Node **head)
{
    //head第一个是头指针
    //从第二个头节点(p2)开始, 每一个节点都指向前一个位置
    Node *p1, *p2, *p3;
    if(*head == NULL || (*head)->next == NULL)
    {
        printf("链表为空,或者无需反转\n");
        return ;
    }
    p1 = (*head)->next;
    p2 = p1->next;
    while(p2)
    {
        p3 = p2->next;
        p2->next = p1; 
        
        //依次向前移动
        p1 = p2;
        p2 = p3;
    }
    //p2指向空  p1指向最后一个节点
    (*head)->next->next = NULL; //头节点的下一个指向为空 
    (*head)->next = p1;         //让头节点指向最后一个节点
}

int main()
{
    Node *list;
    Node a;
    CreateEmptyList(&list);
    Node *p = list;
    CreadNode(&list);
    CreadNode(&list);
    CreadNode(&list);
    printf("添加三个尾节点后:");
    PrintList(p);

    InsetElement(p, 2, 13);  //第二个位置写入13
    InsetElement(p, 2, 13);  //第二个位置写入13
    InsetElement(p, 3, 15);  //第二个位置写入13
    printf("插入数值后:");
    PrintList(p);

    int n = GetPosition(p, 13);
    printf("获取插入数值13的位置:");
    printf("%d\n", n);

    transrev(&list);
    printf("反转后:");
    PrintList(list);
    DeleteElement(p, 0);
    printf("删除数值0后:");
    PrintList(p);

    DeleteElement(p, 13);
    printf("删除数值13后:");
    PrintList(p);

    printf("删除链表后:");
    DeleteList(&list);
    PrintList(list);

    return 0;
}
