/*************************************************************************
	> File Name: parent_chile.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月08日 星期日 20时14分34秒
 ************************************************************************/

/*双亲孩子表示法*/
//结合笔记 看图 理解
#include <stdio.h>
#define MAX_SIZE 1024

//由小到大顺序定义
typedef char ElemType;

//定义节点
typedef struct CTNode
{
    int child;               //孩子结点下标
    struct CTNode *next;     //指向下一个孩子节点的指针
}*ChildPtr;

//定义表头结构
typedef struct
{
    ElemType data;            //存放在树中节点的数据
    int parent;               //存放双亲的下标
    ChildPtr fistchild;       //指向第一个孩子的指针
}CTBox;

//定义树结构
typedef struct 
{
    CTBox nodes[MAX_SIZE];  //结点数组    
    int r;    //根的位置 
    int n;    //节点数目
}PTree;

