/*************************************************************************
	> File Name: bfs_graph.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月26日 星期日 11时12分11秒
 ************************************************************************/
//graph - bfs
//队列
/*
算法：
1 访问邻接未访问过的顶点，并将该顶点标记为已访问，且入队列；
2 如果没有邻接顶点可访问，则出队列；
3 重复1和2直到栈空
*/
#include<stdio.h>
#include<stdlib.h>
#define N 5
typedef struct
{
    int front;
    int rear;
    int queue[N*N];
}Queue;

typedef struct
{
    int label;
    int visited;
}Vertex;

int edge[5][5];
Vertex *LstVertices[N];
//vertex count
int vertexCount = 0;

Queue q;

//EnQueue
void EnQueue(int vertexIndex)
{
    q.queue[q.rear] = vertexIndex;
    q.rear++;
}

//DeQueue
int DeQueue()
{
    return q.queue[q.front++];
}

//IsQueueEmpty
int IsQueueEmpty()
{
    return (q.rear == q.front && q.rear != 0);
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

void BreadthFirstSearch()
{
    int i;
    //从0(S) 开始广度优先遍历
    LstVertices[0]->visited = 1;
    DisplayVertex(0);
    EnQueue(0);

    while(!IsQueueEmpty())
    {
        //get the unvisited vertex of vertex which is at top of the stack
        int tempVertex = DeQueue();

        int unvisitedVertex = GetUnvisitedVertex(tempVertex); 

        //当tempVetex的邻接点unvvisitedVertex不是-1时候一直遍历入对列
        while( (unvisitedVertex = GetUnvisitedVertex(tempVertex)) != -1)
        {
            LstVertices[unvisitedVertex]->visited = 1;
            DisplayVertex(unvisitedVertex);
            EnQueue(unvisitedVertex);
        }
    }

    //queue is empty, search is complete, reset the visited flag
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

    q.front = 0;
    q.rear = 0;

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

    printf("Breadth First Search: ");
    BreadthFirstSearch();
    return 0;
}
