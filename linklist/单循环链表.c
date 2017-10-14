/*************************************************************************
	> File Name: 单循环链表.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月11日 星期三 17时15分11秒
 ************************************************************************/

//单循环链表, 在单链表的基础上, 每创建一个节点,让其后继默认指向head
//最终保证最后一个节点的后继指向Head则构成单循环链表

//不带头节点判空: head == NULL
//带头节点判空:  head->next == head; 为空

//与单链表代码的区别: 每次循环的跳出条件改变,尾插发生改变 
//只要程序中插入节点是头节点, 则必须更新尾节点的指向
//删除头节点, 更新尾节点指向, 删除尾巴节点, 更新前一个节点的指向
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
typedef struct node
{
    int no;
    int age;
    char sex[5];
    char name[20];
    struct node *next;
}Node;

void Print(Node *head);     //打印
void CreateNode(Node *head, Node **p, int no, int age, char *sex, char *name);//创建节点
void Add(Node **head, int no, int age, char *sex, char *name);    //添加节点
Node *FindNode(Node *head, int no);         //根据学号找节点, 没有返回NULL
Node *PrvNode(Node *head, Node *find);      //找到前驱节点
void SerchNode(Node *head, int no);         //按学号查找信息
void Insert(Node **head);                   //按学号大小有序插入
void HeadInsert(Node **head, int sid);      //某个节点前插入(包括头插)
void BackInsert(Node **head, int sid);      //某个节点后插入(包括尾插)
void DeleteNode(Node **head, int no);       //删除学号为no的节点
void FreeAll(Node **head);                  //销毁链表
int GetToatalNode(Node *head);              //获取节点总数

int main()
{
    Node *head = NULL;

    Add(&head, 1002, 17, "男", "张2");
    Add(&head, 1001, 15, "男", "张1");
    Add(&head, 1003, 12, "男", "张3");
    Add(&head, 1004, 21, "男", "张4");
    Add(&head, 1005, 22, "女", "张5");
    Print(head);
    

    printf("删除学号为1005的的链表:\n");
    DeleteNode(&head, 1002);
    Print(head);

    printf("\n统计结点总数为: %d\n\n", GetToatalNode(head));

    printf("插入信息后的链表(指定节点插入):\n");
    printf("(前插)输入学号, 年龄, 性别, 姓名:\n");
    HeadInsert(&head, 1002);
    Print(head);
    printf("(后插)输入学号, 年龄, 性别, 姓名:\n");
    BackInsert(&head, 1004);
    Print(head);


    printf("插入信息后的链表(有序插入):\n");
    printf("输入学号, 年龄, 性别, 姓名:");
    Insert(&head);
    Print(head);

    printf("销毁后的链表:\n");
    FreeAll(&head);
    Print(head);

    return 0;
}

void Print(Node *head)
{
    Node *first = head;
    if(head != NULL)
    {
        printf("学号   年龄   性别   姓名    下一个指向\n");
        while(head != NULL)
        {
            printf("%d    %d     %s     %s   %p\n", head->no, head->age, head->sex, head->name, head->next);
            head = head->next;
            if(head == first)
            {
                //sleep(2); //注释break可以循环打印
                break ;
            }
        }
    }
    else
    {
        printf("空链表哦\n");
    }
}

void CreateNode(Node *head, Node **p, int no, int age, char *sex, char *name)
{
    *p = (Node *)malloc(sizeof(Node));
    if(*p != NULL)
    {
        (*p)->no = no;
        (*p)->age = age;
        strcpy((*p)->sex, sex);
        strcpy((*p)->name, name);
        (*p)->next = head;
    }
    else
    {
        printf("创建节点失败\n");
    }
}

//为空创建添加节点,, 不为空尾部插入...
void Add(Node **head, int no, int age, char *sex, char *name)
{
    Node *h = *head;
    Node *p;
    if(*head == NULL)
    {
        CreateNode(*head, &p, no, age, sex, name);
        *head = p;           //只有第一次赋值,将头指针的内容更改
        p->next = *head;     //第一个节点创建的时候, CreareNode创建节点p的p->next 等于head ,但是此时head是NULL, 所以这里要再次赋值 .不然运行到A会报错
    }
    else
    {
        CreateNode(*head, &p, no, age, sex, name);
        while(h->next != *head)   //while循环条件是(*->next)都将发生改变
        {
            h = h->next;     //A, 如果head是NULL, 那么这里访问非法内存
        }
        h->next = p;
    }
}

//根据学号找到其节点
//没找到返回NULL
Node *FindNode(Node *head, int no)
{
    int flag = 0;
    Node *first = head;
    while(head)
    {
        if(head->no == no)
        {
            flag = 1;
            break;
        }
        head = head->next;
        if(head == first)
        {
            break;
        }
    }
    if(flag == 0)
    {
        return NULL;
    }
    return head;
}

//找到前驱节点
Node *PrvNode(Node *head, Node *find)
{
    Node *first = head;
    while(head)
    {
        if(find == head)    //如果找头节点前一个节点 返回头节点
        {
            break;
        }
        if(head->next == find)
        {
            break;
        }
        head = head->next;
        if(head == first)
        {
            break;
        }
    }
    return head;
}

//有序插入  按学号由小到大
void Insert(Node **head)
{
    Node *first = *head;
    printf("请输入要插入的信息:\n");
    int no;
    float age;
    char sex[5];
    char name[10];
    scanf("%d%f%s%s", &no, &age, sex, name);
    Node *q;
    CreateNode(*head, &q, no, age, sex, name);
    
    Node *p1 = *head;
    Node *p2;

    int flag = 0; 
    while(p1->no <= no) //先判断是否为NULL
    {
        p2 = p1;
        p1 = p1->next;
        if(p1 == *head)
        {
            flag = 1; 
            break;
        }
    }
    
    if(p1 == *head && flag != 1)              //头部插入
    {
        q->next = p1;
        *(head) = q;

        //尾节点要重新指向新的头节点
        for(; p1->next != first; p1 = p1->next);
        p1->next = *head;
    }
    else if(p1 == *head && flag == 1)         //尾部插入 
    {
        p2->next = q;   
        q->next = *head;
    }
    else                                      //中间插入
    {
        q->next = p2->next;
        p2->next = q;
    }
}

void HeadInsert(Node **head, int sid)      //某个节点前插入(包括头插)
{
    Node *first = *head;
    printf("请输入要插入的信息:\n");
    int no;
    float age;
    char sex[5];
    char name[10];
    scanf("%d%f%s%s", &no, &age, sex, name);
    Node *q;
    CreateNode(*head, &q, no, age, sex, name);
    
    Node *p1 = FindNode(*head, sid);
    Node *p2 = PrvNode(*head, p1);

    if(p1 == *head)             //头部插入
    {
        q->next = p1;
        *(head) = q;

        //尾节点要重新指向新的头节点
        for(; p1->next != first; p1 = p1->next);
        p1->next = *head;
    }
    else                        //中间插入
    {
        q->next = p2->next;
        p2->next = q;
    }
}

void BackInsert(Node **head, int sid)       //某个节点后插入(包括尾插)
{
    printf("请输入要插入的信息:\n");
    int no;
    float age;
    char sex[5];
    char name[10];
    scanf("%d%f%s%s", &no, &age, sex, name);
    Node *q;
    CreateNode(*head, &q, no, age, sex, name);
    
    Node *p1 = FindNode(*head, sid);
    Node *p2 = p1->next;

    if(p1->next == *head)        //尾部插入
    {
        p1->next = q;
        q->next = *head;
    }
    else                         //中间插入
    {
        q->next = p1->next;
        p1->next = q;
    }
}

//学号为no的成员删除
void DeleteNode(Node **head, int no)
{
    Node *first = *head;
    Node *p1, *p2;
    p1 = p2 = NULL;

    p1 = *head;
    while(p1)   //遍历节点 找到节点
    {
        if(p1->no == no)
        {
            break;
            //如果删除的是最后一个, 此时p1跳出, p1并不是NULL
            //所以删除不用判断尾节点
        }
        p2 = p1;
        p1 = p1->next;
        if(p1 == *head)
        {
            break;
        }
    }

    if(p1 == *head)          //删除头节点
    {
        (*head) = p1->next;  //跳过头节点

        //尾节点要重新指向新的头节点
        Node *p = p1;
        for(; p->next != first; p = p->next);
        p->next = *head;

        free(p1);            //释放头节点
    }
    else                     //删除其他节点
    {
        p2->next = p1->next;
        free(p1);
    }
}

void SerchNode(Node *head, int no)            //按学号查找信息
{
    Node *sr = FindNode(head, no);
    if(sr != NULL)
    {
        printf("%d    %d     %s     %s   %p\n", sr->no, sr->age, sr->sex, sr->name, sr->next);
    }
    else
    {
        printf("查无此人\n");
    }
}

//删除所有节点
//最后删除头节点
void FreeAll(Node **head)
{
    Node *p1 = *head;
    Node *p2 = NULL;
    Node *q = NULL;
    while(p1->next == *head)
    {
        p2 = p1->next;
        p1->next = p2->next;
        free(p2);
    }
    free(*head);
    *head = NULL;
}

int GetToatalNode(Node *head)              //获取节点总数
{
    int num = 0;
    Node *first = head;
    if(head != NULL)
    {
        while(head != NULL)
        {
            num++;
            head = head->next;
            if(head == first)
            {
                break;
            }
        }
    }
    return num;
}

