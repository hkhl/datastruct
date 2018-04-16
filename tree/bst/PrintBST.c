/*************************************************************************
	> File Name: Print.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月16日 星期一 21时02分27秒
 ************************************************************************/

#include "bst.h"

void PrintBST(BTree T, char *order)
{
    if(T != NULL)
    {
        if(strcmp(order, "first") == 0)
        {
            printf("%d", T->data);
            PrintBST(T->lchild, order);
            PrintBST(T->rchild, order);

        }
        else if(strcmp(order, "middle") == 0)
        {
            PrintBST(T->lchild, order);
            printf("%d", T->data);
            PrintBST(T->rchild, order);
        }
        else if(strcmp(order, "last") == 0)
        {
            PrintBST(T->lchild, order);
            PrintBST(T->rchild, order);
            printf("%d", T->data);
        }
        else
        {
            printf("请输入 first, middle or last");
        }
    }
}
