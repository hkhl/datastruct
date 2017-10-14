/*************************************************************************
	> File Name: 069学生链表.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月28日 星期四 22时47分41秒
 ************************************************************************/
/*
*建立一个链表每个结点包括学号、姓名、性别、年龄。
*包括增删改查,排序 交换 反转等功能
* */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int no;
    int age;
    char sex[5];
    char name[20];
    struct node *next;
}Node;

void Print(Node *head);     //打印
void CreateNode(Node **p, int no, int age, char *sex, char *name);//创建节点
void Add(Node **head, int no, int age, char *sex, char *name);    //添加节点
Node *FindNode(Node *head, int no);         //根据学号找节点, 没有返回NULL
Node *PrvNode(Node *head, Node *find);      //找到前驱节点
void SerchNode(Node *head, int no);         //按学号查找信息
void Insert(Node **head);                   //按学号大小有序插入
void HeadInsert(Node **head, int sid);      //某个节点前插入(包括头插)
void BackInsert(Node **head, int sid);      //某个节点后插入(包括尾插)
void DeleteNode(Node **head, int no);       //删除学号为no的节点
void FreeAll(Node **head);                  //销毁链表
void Swap(Node **head, int no1, int no2);   //交换两个节点的顺序 
void SwapSort(Node **head, Node *p1, Node *p2);  //专门用来排序的交换函数 - -
void Sort(Node **head);                     //链表排序
void LinkRev(Node **head);                  //链表的反转
int GetToatalNode(Node *head);              //获取节点总数


int main()
{
    Node *head = NULL;
    Add(&head, 1002, 17, "男", "张2");
    Add(&head, 1001, 15, "男", "张1");
    Add(&head, 1004, 23, "女", "张4");
    Add(&head, 1003, 19, "男", "张3");
    Add(&head, 1005, 22, "女", "张5");
    Print(head);
    
    printf("交换后的链表:\n");
    Swap(&head, 1001, 1003);
    Print(head);
   
    printf("排序后的链表:\n");
    Sort(&head);
    Print(head);

    printf("删除学号为1005的的链表:\n");
    DeleteNode(&head, 1005);
    Print(head);

    printf("\n统计结点总数为: %d\n\n", GetToatalNode(head));


    printf("插入信息后的链表(指定节点插入):\n");
    printf("(前插)输入学号, 年龄, 性别, 姓名:\n");
    HeadInsert(&head, 1004);
    Print(head);
    printf("(后插)输入学号, 年龄, 性别, 姓名:\n");
    BackInsert(&head, 1004);
    Print(head);


    printf("插入信息后的链表(有序插入):\n");
    printf("输入学号, 年龄, 性别, 姓名:");
    Insert(&head);
    Print(head);

    printf("反转后的链表:\n");
    LinkRev(&head);
    Print(head);

    printf("销毁后的链表:\n");
    FreeAll(&head);
    Print(head);

    return 0;
}

void Print(Node *head)
{
    if(head != NULL)
    {
        printf("学号   年龄   性别   姓名    下一个指向\n");
        while(head != NULL)
        {
            printf("%d    %d     %s     %s   %p\n", head->no, head->age, head->sex, head->name, head->next);
            head = head->next;
        }
    }
    else
    {
        printf("空链表哦\n");
    }
}

void CreateNode(Node **p, int no, int age, char *sex, char *name)
{
    *p = (Node *)malloc(sizeof(Node));
    if(*p != NULL)
    {
        (*p)->no = no;
        (*p)->age = age;
        strcpy((*p)->sex, sex);
        strcpy((*p)->name, name);
        (*p)->next = NULL;
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
        CreateNode(&p, no, age, sex, name);
        *head = p;           //只有第一次赋值,将头指针的内容更改
    }
    else
    {
        while(h->next)
        {
            h = h->next;
        }
        CreateNode(&p, no, age, sex, name);
        h->next = p;
    }
}

//根据学号找到其节点
//没找到返回NULL
Node *FindNode(Node *head, int no)
{
    int flag = 0;
    while(head)
    {
        if(head->no == no)
        {
            flag = 1;
            break;
        }
        head = head->next;
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
    }
    return head;
}

//有序插入  按学号由小到大
void Insert(Node **head)
{
    printf("请输入要插入的信息:\n");
    int no;
    float age;
    char sex[5];
    char name[10];
    scanf("%d%f%s%s", &no, &age, sex, name);
    Node *q;
    CreateNode(&q, no, age, sex, name);
    
    Node *p1 = *head;
    Node *p2;

    while(p1 != NULL && p1->no <= no) //先判断是否为NULL
    {
        p2 = p1;
        p1 = p1->next;
    }
    
    if(p1 == *head)             //头部插入
    {
        q->next = p1;
        *(head) = q;
    }
    else if(p1 == NULL)         //尾部插入
    {
        p2->next = q;   
    }
    else                        //中间插入
    {
        q->next = p2->next;
        p2->next = q;
    }
}

void HeadInsert(Node **head, int sid)      //某个节点前插入(包括头插)
{
    printf("请输入要插入的信息:\n");
    int no;
    float age;
    char sex[5];
    char name[10];
    scanf("%d%f%s%s", &no, &age, sex, name);
    Node *q;
    CreateNode(&q, no, age, sex, name);
    
    Node *p1 = FindNode(*head, sid);
    Node *p2 = PrvNode(*head, p1);

    if(p1 == *head)             //头部插入
    {
        q->next = p1;
        *(head) = q;
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
    CreateNode(&q, no, age, sex, name);
    
    Node *p1 = FindNode(*head, sid);
    Node *p2 = p1->next;

    if(p1->next == NULL)        //尾部插入
    {
        p1->next = p2;
        p2->next = NULL;
    }
    else                        //中间插入
    {
        q->next = p1->next;
        p1->next = q;
    }
}

//学号为no的成员删除
void DeleteNode(Node **head, int no)
{
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
    }

    if(p1 == *head)          //删除头节点
    {
        (*head) = p1->next;  //跳过头节点
        free(p1);            //释放头节点
    }
    else                     //删除其他节点
    {
        p2->next = p1->next;
        free(p1);
    }
   /* 或者这样
    * if(head!= NULL)
    {
        Node *p1 = *head;
        Node *p2 = p1->next;
        //如果删除的是首元素
        if((*head)->age == age)
        {
            *head = (*head)->next;
            free(p1);
            return;
        }
        else   //删除的不是首元素
        {
            while(p2 != NULL)
            {
                if(p2->age == age)
                {
                    p1->next = p2->next;
                    free(p2);
                    return;
                }
                p1 = p2;
                p2 = p1->next;
            }
        }
    }
    else
    {
        printf("空链表\n");
    }*/
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
    while(p1->next)
    {
        p2 = p1->next;
        p1->next = p2->next;
        free(p2);
    }
    free(*head);
    *head = NULL;
}

//交换链表中两个节点的顺序
//头节点的, 尾节点,  中间相邻节点, 不相邻节点等特殊节点的交换处理
void Swap(Node **head, int no1, int no2)
{
    Node *p1, *p2;
    Node *p11, *p22;  //指向p1 p2的前一个节点
    p1 = p2 = *head;

    //找到no1和no2所在节点
    p1 = FindNode(*head, no1);
    p2 = FindNode(*head, no2);

    //也可以交换节点间的连接
    if(p1 != NULL && p2 != NULL)
    {
        p11 = PrvNode(*head, p1);
        p22 = PrvNode(*head, p2);
        if(p1 == *head)     //带有头节点的交换
        {
            *head = p2;
            p22->next = p1;
        }
        else if(p2 == *head)
        {
            *head = p1;
            p11->next = p2;
        }
        else                //不带头节点的交换
        {
            p11->next = p2;
            p22->next = p1;
        }
        Node *q = p1->next;
        p1->next = p2->next;
        p2->next = q;
    }
    else
    {
        printf("交换节点为空\n");
    }
}

//用来排序的交换函数
void SwapSort(Node **head, Node *p1, Node *p2)
{
    int temp;
    temp = p1->no;
    p1->no = p2->no;
    p2->no = temp;

    temp = p1->age;
    p1->age = p2->age;
    p2->age = temp;

    char str[10];
    strcpy(str, p1->name);
    strcpy(p1->name, p2->name);
    strcpy(p2->name, str);

    strcpy(str, p1->sex);
    strcpy(p1->sex, p2->sex);
    strcpy(p2->sex, str);
}

//链表排序
void Sort(Node **head)
{
    Node *p1,*p2;
    p1 = *head;
    while(p1)
    {
        p2 = p1->next;
        while(p2)
        {
            if(p1->no > p2->no)
            {
                SwapSort(head, p1, p2);
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
}

//链表的逆转
void LinkRev(Node **head)
{
    if(*head == NULL || (*head)->next == NULL)
    {
        return ;
    }
    Node *p1, *p2, *p3;
    p1 = p2 = p3 = NULL;

    p1 = *head;
    p2 = p1->next;
    while(p2)
    {
        p3 = p2->next;

        p2->next = p1;  //指向前一个元素

        p1 = p2;
        p2 = p3;
    }
    (*head)->next = NULL;    //不加这条语句, 将会在1,2节点之间来回跳
    *head = p1;        //指向最后一个节点
}

int GetToatalNode(Node *head)              //获取节点总数
{
    int num = 0;
    if(head != NULL)
    {
        while(head != NULL)
        {
            num++;
            head = head->next;
        }
    }
    return num;
}

