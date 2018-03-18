/*************************************************************************
	> File Name: skiplist.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 15时18分14秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_LEVEL 5

typedef struct node
{
    int data;
    struct node *nexts[0];
}Node;

int RandomLevel()
{
    time_t ts;
    srand((signed int)time(&ts));
    return rand()%MAX_LEVEL;
}
void FreeAll(Node *p)
{
    free(p);
}
Node *Create()
{
    Node *p = (Node *)malloc(sizeof(Node) + MAX_LEVEL*sizeof(Node *));
    return p;
}

void Print(Node *head)
{
    for(int i = MAX_LEVEL-1; i >= 0; i--)
    {
        Node *temp = head->nexts[i];
        printf("第%d层: ", i);
        while(NULL != temp)
        {
            printf("%d--->", temp->data);
            temp = temp->nexts[i];
        }
        printf("\n");
    }
}


void DeleteNode(Node *head)
{
    int num, flag = 0;
    Node *p = head;
    Node *q = NULL;
    Node *temp;

    printf("请输入要删除的节点:\n");
    scanf("%d", &num);

    for(int i = 0; i < MAX_LEVEL; i++)
    {
        q = head;
        p = head->nexts[i];
        flag = 0;
        while(p != NULL)
        {
            if(p->data == num)
            {
                flag = 1; 
                break;
            }
            q = p;    //q所记录的是p的前一个节点
            p = p->nexts[i];
        }
        if(p == NULL)
        {
            printf("%d层没有要删除的数据%d!\n", i, num);
            continue;
        }
        if(flag == 1) 
        {
            q->nexts[i] = p->nexts[i];
        }
    }
}

void Insert(Node *head, Node *node, int num)
{
    int level = RandomLevel();
    Node *p1 = head;
    Node *p2;

    for(int i = 0; i <= level; i++)
    {
        p1 = head;
        while(p1 != NULL && p1->data <= num) //先判断是否为NULL
        {
            p2 = p1;
            p1 = p1->nexts[i];
        }
        if(p1 == head)              //头部插入
        {
            node->nexts[i] = head->nexts[i];
            head->nexts[i] = node;
        }
        else if(p1 == NULL)         //尾部插入
        {
            p2->nexts[i] = node;
            node->nexts[i] = NULL;
        }
        else                        //中间插入
        {
            node->nexts[i] = p2->nexts[i];
            p2->nexts[i] = node;
        }
    }
}

void Find(Node *head)
{
    int num, count;
    Node *p = head;
    printf("请输入要查找的数字:\n");
    scanf("%d", &num);
    
    for(int i = 0; i < MAX_LEVEL; i++)
    {
        count = 1;
        p = head->nexts[i];
        while(p != NULL && p->data != num)
        {
            count++;
            p = p->nexts[i];
        }
        if(p == NULL)
        {
            printf("%d层没有要查找的数据%d!\n", i, num);
            continue;
        }
        if(p->data == num)
        {
            printf("%d层第%d个数据是您要查找的数据!\n", i, count);    
        }
    }
}

void BSearch(Node *head)
{
    int num, count, flag;
    Node *q, *p = head;
    printf("请输入要查找的数字:\n");
    scanf("%d", &num);
    
    int i = MAX_LEVEL-1; //顶层
    
    p = head->nexts[i];
    while(i >= 0)
    {
        count = 0;
        while(p != NULL && p->data < num )
        {
            count++;
            q = p;
            p = p->nexts[i];
        }
        if(p == NULL || p->data > num)
        {
            p = q;
        }
        else if(p->data == num)
        {
            printf("\n%d层有该数字%d\n", i,  num);
            break;
        }
        if(i == 0)
        {
            printf("没有该数据!\n");
        }
        i--;
    }
}


int main()
{
    Node *head = Create();
    int num;

    printf("请输入要添加的节点(0结束):\n");
    while(1)
    {
        scanf("%d", &num);
        if(num == 0)
            break;
        Node *node = Create();
        node->data = num;

        Insert(head, node, num);
    }

    Print(head);
    DeleteNode(head);
    Print(head);

    //Find(head);
    while(1)
    BSearch(head);

    FreeAll(head);
    return 1;
}
