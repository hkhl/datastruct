/*************************************************************************
	> File Name: searchBst.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月14日 星期六 12时08分46秒
 ************************************************************************/

#include "bst.h"

//递归查找二叉树T中是否存在key
//指针f指向T的双亲, 初始值为NULL
//查找成功,指针p指向该元素节点并返回true
//查找失败, p指向查找路径上访问的最后一个节点, 返回false

_Bool SearchBST(BTree T, int key, BTree f, BTree *p)
{
    if(NULL == T)
    {
        *p = f;
        return false;
    }
    else if(key == T->data)
    {
        *p = T;
        return true;
    }
    else if(key < T->data)
    {
        return SearchBST(T->lchild, key, T, p);
    }
    else
    {
        return SearchBST(T->rchild, key, T, p);
    }
}



