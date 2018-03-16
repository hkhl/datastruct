/*************************************************************************
	> File Name: bst.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月27日 星期一 19时51分22秒
 ************************************************************************/

/*二分查找树*/
/*先中后序遍历*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}Node;

Node *root = NULL;

Node* search(int e)
{
    Node *current = root;
    if(current == NULL)
        return NULL;

    while(current != NULL && current->data != e)
    {
        printf("visiting element:%d\n", current->data);
        if(current->data > e)
        {
            current = current->lchild;
        }
        else
        {
            current = current->rchild;
        }
    }

    return current;
}

void insert(int e)
{
    Node *temp_node = (Node *)malloc(sizeof(Node));
    temp_node->data = e;
    temp_node->lchild = NULL;
    temp_node->rchild = NULL;

    if(root == NULL)
    {
        root = temp_node;
    }
    else
    {
        Node *current = root;
        Node *parent = NULL;
        while(1)
        {
            parent = current;
            if(current->data > e)
            {
                current = current->lchild;
                if(current == NULL)
                {
                    parent->lchild = temp_node;
                    return ;
                }
            }
            else
            {
                current = current->rchild;
                if(current == NULL)
                {
                    parent->rchild = temp_node;
                    return ;
                }
            }
        }
    }
}

void pre_order_traversal(Node *root)
{
    if(root != NULL)
    {
        printf("%d\n", root->data);
        pre_order_traversal(root->lchild);
        pre_order_traversal(root->rchild);
    }
}

void in_order_traversal(Node *root)
{
    if(root != NULL)
    {
        in_order_traversal(root->lchild);
        printf("%d\n", root->data);
        in_order_traversal(root->rchild);
    }
}

void post_order_traversal(Node *root)
{
    if(root != NULL)
    {
        post_order_traversal(root->lchild);
        post_order_traversal(root->rchild);
        printf("%d\n", root->data);
    }
}


int main()
{
    int i;
    int array[7] = {27, 14, 35, 10, 19, 31, 42};

    for (i = 0; i < 7; i++)
        insert(array[i]);

    i = 31;
    Node *temp = search(i);
    if(temp == NULL)
    {
        printf("element %d not found!\n", i);
    }
    else
    {
        printf("element %d found!\n", temp->data);
    }

    i = 15;
    temp = search(i);
    if(temp == NULL)
    {
        printf("element %d not found!\n", i);
    }
    else
    {
        printf("element %d found!\n", temp->data);
    }
    printf("pre_order_traversal:");
    pre_order_traversal(root);

    printf("\nin_order_traversal:");
    in_order_traversal(root);

    printf("\npost_order_traversal:");
    post_order_traversal(root);
    
    return 0;
}
