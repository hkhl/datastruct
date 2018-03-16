/*************************************************************************
	> File Name: hash_link.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 11时42分00秒
 ************************************************************************/
// 构建哈希函数 除留余数法
// 解决哈希冲突 连地址法 

#include<stdio.h>
#include<stdlib.h>
#define N 10

typedef int ElementType;
typedef struct node
{
    ElementType data;
    struct node *next;

}Node;

//创建空链表
Node *CreateEmptyList(Node **head)
{
    *head = (Node *)malloc(sizeof(Node));
    (*head)->next = NULL;
    return *head;
}

//某个节点后插入数据
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

//末尾创建一个节点
Node *CreateNode(Node **head)
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
        printf("--->%d", head->data);
        head = head->next;
    }
    putchar(10);
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

int hash(int n)
{
    return n%N;
}
int Insert(int num, Node **head)
{
    Node *p = *head;
    //始终在头节点后插入数据
    InsetElement(p, 0, num);
}

void Find(Node **list)
{
    int num = 0, key, n;
    printf("\n请输入要查询的数字:\n");
    scanf("%d", &num);
    key = hash(num);

    if( (n = GetPosition(list[key], num)) == 0)
    {
        printf("not find\n");
    }
    else
    {
        printf("%d层,第%d个为要查询的值!\n", key, n);
    }
}
int main()
{
    Node *list[N];
    int num = 0;

    for(int i = 0; i < N; i++)
    {
        CreateEmptyList(&list[i]);
    }

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        int key = hash(num);
        Insert(num, &list[key]);
    }

    printf("存储结果:\n");
    for(int i = 0; i < N; i++)
    {
        printf("head[%d]", i);
        PrintList(list[i]);
    }
    printf("\n");
    while(1)
    Find(list);
    return 0;
}
