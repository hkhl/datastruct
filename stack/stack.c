/*************************************************************************
	> File Name: 栈.c
	> Author: 
	> Mail: 
	> Created Time: 2017年10月24日 星期二 16时19分55秒
 ************************************************************************/
//栈的简单实现
#include<stdio.h>
#include<stdlib.h>
#define N 100

typedef struct Stack
{
    int top;        //栈顶
    int data[N];    //存放数据
}Stack;

int IsEmpty(Stack *mystack);         //判定栈空
int SetEmpty(Stack *mystack);        //设置栈空
int Push(Stack *mystack, int data);  //入栈
int Pop(Stack *mystack);             //出栈
int FreeAll(Stack *mystack);         //销毁

int main()
{
    Stack mystack = {-1, {0}};
    for(int i = 0; i < 10; i++)
    {
        Push(&mystack, i);
    }
    while(!IsEmpty(&mystack))
    {
        printf("%d ", Pop(&mystack));
    }
    return 0;
}

int IsEmpty(Stack *mystack)
{
    if(mystack->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int SetEmpty(Stack *mystack)
{
    mystack->top = -1;
}

int Push(Stack *mystack, int data)
{
    if(mystack->top + 1 <= N-1)  //没有溢出
    {
        mystack->data[mystack->top+1] = data;
        mystack->top++;
        return 1;
    }
    else
    {
        printf("stack is overflow!\n");
        return 0;
    }
}

int Pop(Stack *mystack)
{
    if(!IsEmpty(mystack))   //栈不为空
    {
        mystack->top -= 1;
        return mystack->data[mystack->top+1]; 
    }
    else
    {
        printf("stack is empty!\n");
        return -1;          //为空返回-1;
    }

}
