/*************************************************************************
	> File Name: 双循环链表.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月12日 星期四 19时41分57秒
 ************************************************************************/

/*双循环链表的实现*/
//基于双链表实现, 大体区别是尾节点后继指向头节点, 头节点的前驱指向尾节点
//主要区别还是打印, 插入节点(首 中 尾)前插 后插. 删除节点(首 尾) 需要特别注意

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Dblink
{
    int data;              //数据域
    struct Dblink *prv;      //指向前驱节点
    struct Dblink *next;     //指向后继节点
}Node;

int Empty(Node *head);                      //判空
void Print(Node *head);                     //打印
void TransPrint(Node *head);                //反向打印
void CreateNode(Node *head, Node **p, int data);        //创建节点
void Add(Node **head, int data);            //向链表尾部添加节点
Node *FindPosNode(Node *head, int pos);     //根据位置找节点
Node *FindDataNode(Node *head, int data);   //根据data找第一个节点, 没有返回NULL
void Insert(Node **head, int data);         //某个节点前插入(包括头插)
int GetToatalNode(Node *head);              //获取节点总数
void DeleteNode(Node **head, int data);     //删除内容为data的节点
void FreeAll(Node **head);                  //销毁链表


int main()
{
    Node *head = NULL;

    Add(&head, 1);
    Add(&head, 2);
    Add(&head, 3);
    Add(&head, 4);
    Add(&head, 5);
    printf("正向打印:\n");
    Print(head);

    printf("反向打印:\n");
    TransPrint(head);

    Node *q = FindPosNode(head, 2); //从第二个节点开始打印
    Print(q);
    
    q = FindDataNode(head, 1);      //从数据为1的节点开始打印
    Print(q);

    printf("删除节点后:\n");
    DeleteNode(&head, 3);
    Print(head);

    Insert(&head, 1);   //在数据1的位置前插或者后入 测试首部
    printf("正向打印:\n");
    Print(head);
    printf("反向打印:\n");
    TransPrint(head);

    Insert(&head, 5);   //同上  测试尾部
    Print(head);

    Insert(&head, 3);   //同上  测试中间数据
    Print(head);

    return 0;
}

int EmptyLink(Node *head)
{
    if(head->next == NULL || head->prv == NULL)
    {
        printf("链表为空\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

void Print(Node *head)
{
    if(!EmptyLink(head))
    {
        Node *first = head;
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
            if(head == first)
                break;
        }
        printf("\n");
    }
}

void TransPrint(Node *head)
{
    Node *first = head;
    if(!EmptyLink(head))
    {
        while(head->next != first)
        {
            head = head->next;
        }

        while(head != NULL)
        {
            printf("%d ", head->data);
            if(head == first)
                break;
            head = head->prv;
        }
        printf("\n");

    }
}

//新创建的节点前后指向都为head
void CreateNode(Node *head, Node **p, int data)
{
    *p = (Node *)malloc(sizeof(Node));
    if(*p != NULL)
    {
        (*p)->data = data;
        (*p)->next = head;
        (*p)->prv = head;
    }
    else
    {
        printf("创建节点失败\n");
        exit(EXIT_FAILURE);
    }
}

//添加在链表的尾部
//为空创建添加节点,, 不为空尾部插入...
void Add(Node **head, int data)
{
    Node *h = *head;
    Node *p;
    if(*head == NULL)
    {
        CreateNode(*head, &p, data);
        *head = p;           //只有第一次赋值,将头指针的内容更改
        p->next = *head;
    }
    else                     //链表尾部添加节点
    {
        while(h->next != *head)
        {
            h = h->next;
        }
        CreateNode(*head, &p, data);
        h->next = p;
        p->prv = h;
        (*head)->prv = p;
    }
}

int GetToatalNode(Node *head)           //获取节点总数
{
    Node *first = head;
    int num = 0;
    if(head != NULL)
    {
        while(head != NULL)
        {
            num++;
            head = head->next;
            if(head == first)
            break;
        }
    }
    return num;
}

Node *FindPosNode(Node *head, int pos)         //根据位置找节点, 没有返回NULL
{
    int total = GetToatalNode(head);
    if(pos <= 0 || pos > total)
    {
        return NULL;
    }

    while(pos-1)
    {
        head = head->next;
        pos--;
    }
    return head;
}

Node *FindDataNode(Node *head, int data)        //根据data找第一个节点, 没有返回NULL
{
    printf("first head %p\n", head);
    Node *first = head;
    int flag = 0;
    while(head)
    {
        if(head->data == data)
        {
            flag = 1;
            break;
        }
        head = head->next;
        if(head == first)
        break;
    }
    if(flag == 0)
    {
        return NULL;
    }
    printf("finddatanode head %p\n", head);
    return head;
}

void Insert(Node **head, int data)      //某个节点前插入或者后插入
{
    Node *find = FindDataNode(*head, data);
    if(find == NULL)
    {
        printf("没有此节点, 插入失败\n");
        return ; 
    }
    printf("head %p", (*head));
    printf("\nfind %p", find);
    
    int newdata;
    printf("请输入插入节点的数据:");
    scanf("%d", &newdata);
    Node *create = NULL;
    CreateNode(*head, &create, newdata);


    int judge = 0;
    printf(":) 前插请敲0,后入请敲1 : ");
    scanf("%d", &judge);
    if(judge == 0)
    {
        //前插
        create->prv = find->prv;
        create->next = find;
        find->prv->next = create;
        find->prv = create;
        //以上代码在插入头节点之前,默认插入到尾节点后面,
        if(find == *head)
        {
            //因为是循环的, 相当于没有首尾,将头指针设置为新插入的节点的地址就ok
            *head = create;
        }
    }
    else
    {
        //后入
        //是尾节点 或者不是尾节点,代码通用
        create->prv = find;
        create->next = find->next;
        find->next->prv = create;
        find->next = create;
    }
}

void DeleteNode(Node **head, int data)       //删除数据为data的节点
{

    Node *p1 = *head;

    int flag = 0;
    while(p1)   //遍历节点 找到节点
    {
        if(p1->data == data)
        {
            break;
            //如果删除的是最后一个, 此时p1跳出, p1并不是NULL
        }
        p1 = p1->next;
        if(p1 == *head)
        {
            flag = 1;
            break;
        }
    }
    if(p1 == *head && flag == 1)
    {
        printf("没找到要删除的数据!\n");
        return ;
    }

    if(p1 == *head && flag != 1)   //删除头节点
    {
        Node *tail = p1;
        for(; tail->next != *head; tail = tail->next); //找到尾节点
        (*head) = p1->next;  //跳过头节点
        tail->next = *head;
        (*head)->prv = tail;

        free(p1);            //释放头节点
    }
    else                     //删除其他节点
    {
        p1->prv->next = p1->next;
        if(p1->next != NULL)   //以此判断最后一个节点
        {
            p1->next->prv = p1->prv;
        }
        free(p1);
    }
}

void FreeAll(Node **head)                  //销毁链表
{
    Node *p1 = *head;
    Node *p2 = NULL;
    Node *q = NULL;
    while(p1->next)
    {
        p2 = p1->next;
        p1->next = p2->next;
        free(p2);
    }
    free(*head);
    *head = NULL;
}

