/*************************************************************************
	> File Name: main.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月16日 星期一 20时56分20秒
 ************************************************************************/
#include "bst.h"

int main()
{

    BTree t = NULL;   //必须初始化


    //可以循环输入
    InsertBST(&t, 5);
    InsertBST(&t, 3);
    InsertBST(&t, 1);
    InsertBST(&t, 4);
    InsertBST(&t, 6);
    InsertBST(&t, 2);
    InsertBST(&t, 7);


    printf("先序遍历:");
    PrintBST(t, "first");
    printf("\n");

    printf("中序遍历:");
    PrintBST(t, "middle");
    printf("\n");
    
    printf("后序遍历:");
    PrintBST(t, "last");
    printf("\n");



    printf("删除节点后:");
    DeleteBST(&t, 3);
    printf("\n");

    printf("先序遍历:");
    PrintBST(t, "first");
    printf("\n");

    printf("中序遍历:");
    PrintBST(t, "middle");
    printf("\n");
    
    printf("后序遍历:");
    PrintBST(t, "last");
    printf("\n");
    return 0;
}
