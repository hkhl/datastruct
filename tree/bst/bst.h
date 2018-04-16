/*************************************************************************
	> File Name: bst.h
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月16日 星期一 20时56分34秒
 ************************************************************************/

#ifndef _BST_H
#define _BST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int ElemType;
typedef struct BNode
{
    ElemType data;
    struct BNode *lchild, *rchild;
}BNode, *BTree;


_Bool SearchBST(BTree T, int key, BTree f, BTree *p);
_Bool InsertBST(BTree *T, int key);
void PrintBST(BTree T, char *str);

//删除节点
_Bool Delete(BTree *p);
_Bool DeleteBST(BTree *T, int key);

#endif
