/*************************************************************************
	> File Name: graph.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月26日 星期日 11时12分11秒
 ************************************************************************/
//graph - dfs
//栈
/*
算法：
1 访问邻接未访问过的顶点，并将该顶点标记为已访问，且入栈；
2 如果没有邻接顶点可访问，则出栈；
3 重复1和2直到栈空*/

#include<stdio.h>
#include<stdlib.h>
#define N 5
typedef struct
{
    int top;
    int stack[N*N];
}Stack;

typedef struct
{
    int label;
    int visited;
}Vertex;

int edge[5][5];
Vertex *LstVertices[N];
//vertex count
int vertexCount = 0;

Stack s;



void push(int num)
{
    s.top++;
    s.stack[s.top] = num;
}

int pop()
{
    /*
    int num = s->stack[s->top];
    s->top--;
    return num;
    */

    return s.stack[s.top--];
}

int peek()
{
    return s.stack[s.top];
}
int IsStackEmpty()
{
    return s.top == -1;
}

void AddVertex(char name)
{
    Vertex *v = (Vertex *)malloc(sizeof(Vertex));
    v->label = name;
    v->visited = 0;
    LstVertices[vertexCount++] = v;
}

void AddEdge(int x, int y)
{
    edge[x][y] = 1;
    edge[y][x] = 1;
}

//dispaly the vertex
void DisplayVertex(int vertexIndex)
{
    printf("%c ", LstVertices[vertexIndex]->label);
}

//get the adjacent unvisited Vertex
int GetUnvisitedVertex(int vertexIndex)
{
    int i = 0;
    for(i = 0; i < vertexCount; i++)
    {
        if(edge[vertexIndex][i] == 1 && LstVertices[i]->visited == 0)
        {
            return i;
        }
    }
    return -1;
}

void DepthFirstSearch()
{
    int i;
    //从0(S) 开始深度优先遍历
    LstVertices[0]->visited = 1;
    DisplayVertex(0);
    push(0);

    while(!IsStackEmpty())
    {
        //get the unvisited vertex of vertex which is at top of the stack
        int unvisitedVertex = GetUnvisitedVertex(peek()); 

        if(unvisitedVertex == -1)
        {
            pop();
        }
        else
        {
            LstVertices[unvisitedVertex]->visited = 1;
            DisplayVertex(unvisitedVertex);
            push(unvisitedVertex);
        } 
    }

    //stack is empty, search is complete, reset the visited flag
    for(i = 0; i < vertexCount; i++)
    {
        LstVertices[i]->visited = 0;
    }
}

int main()
{
    for(int i = 0; i < N; i++)
        for(int i = 0; i < N; i++)
            edge[0][0] = 0;

    s.top = -1;
    AddVertex('S');
    AddVertex('A');
    AddVertex('B');
    AddVertex('C');
    AddVertex('D');

    AddEdge(0, 1);
    AddEdge(0, 2);
    AddEdge(0, 3);
    AddEdge(1, 4);
    AddEdge(2, 4);
    AddEdge(3, 4);

    printf("Depth First Search: ");
    DepthFirstSearch();
    return 0;
}
