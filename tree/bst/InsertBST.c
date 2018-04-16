/*************************************************************************
	> File Name: InsertBST.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月16日 星期一 20时36分58秒
 ************************************************************************/

#include "bst.h"
//当二叉排序树T中不存在关键字等于key的数据元素时 
//进行插入操作 并返回true,  否则返回false

_Bool InsertBST(BTree *T, int key)
{
    BTree p, s;
    if(!SearchBST(*T, key, NULL, &p))
    {
        s = (BTree)malloc(sizeof(BNode));
        s->data = key;
        s->lchild = s->rchild = NULL;

        //p=NULL 说明T是根节点
        if(p == NULL)
        {
            *T = s;   //T 二级指针的原因
        }
        else if(key < p->data)
        {
            p->lchild = s;
        }
        else
        {
            p->rchild = s;
        }
        return true;
    }
    else
    {
        return false;
    }
}
