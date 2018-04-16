/*************************************************************************
	> File Name: DeleteBST.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月16日 星期一 21时47分15秒
 ************************************************************************/

#include "bst.h"

//叶子结点直接删除

_Bool Delete(BTree *p)
{
    BTree q, s;        //q是双亲节点, s是每一次迭代用到的节点

    //待删除节点右子树为空
    if( (*p)->rchild == NULL )
    {
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }
    //左子树为空
    else if( (*p)->lchild == NULL )
    {
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    else
    {
        //左子树不为空, 右子树也不为空

        //两种写法
        //一种是将删除节点的直接前驱放在自己的位置

        q = *p;
        s = (*p)->lchild;

        while(s->rchild)
        {
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data;

        //如果之前的s没有右子树,那么q等于*p
        if(q != *p)
        {
            q->rchild = s->lchild;
        }
        else
        {
            q->lchild = s->lchild;
        }
        free(s);
    }
    return true;
}

_Bool DeleteBST(BTree *T, int key)
{
    if(T == NULL)
    {
        return false;
    }
    else
    {
        if(key == (*T)->data)
        {
            return Delete(T);
        }
        else if(key < (*T)->data)
        {
            return DeleteBST(&(*T)->lchild, key);
        }
        else
        {
            return DeleteBST(&(*T)->rchild, key);
        }
    }
}

