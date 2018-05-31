#include <iostream>
#define N 5
using namespace std;

/*
 *https://www.jianshu.com/p/70952b51f0c8
 *深度优先搜索在搜索过程中访问某个顶点后，需要递归地访问此顶点的所有未访问过的相邻顶点。
初始条件下所有节点为白色，选择一个作为起始顶点，按照如下步骤遍历：
a. 选择起始顶点涂成灰色，表示还未访问
b. 从该顶点的邻接顶点中选择一个，继续这个过程（即再寻找邻接结点的邻接结点），一直深入下去，直到一个顶点没有邻接结点了，涂黑它，表示访问过了
c. 回溯到这个涂黑顶点的上一层顶点，再找这个上一层顶点的其余邻接结点，继续如上操作，如果所有邻接结点往下都访问过了，就把自己涂黑，再回溯到更上一层。
d. 上一层继续做如上操作，知道所有顶点都访问过。

从顶点1开始做深度搜索：
初始状态，从顶点1开始
依次访问过顶点1,2,3后，终止于顶点3
从顶点3回溯到顶点2，继续访问顶点5，并且终止于顶点5
从顶点5回溯到顶点2，并且终止于顶点2
从顶点2回溯到顶点1，并终止于顶点1
从顶点4开始访问，并终止于顶点4

 */

int maze[N][N] =
{
    {0,1,1,0,0},
    {0,0,1,0,1},
    {0,0,1,0,0},
    {1,1,0,0,1},
    {0,0,1,0,0}
};

int visited[N+1] = {0};

void DFS(int start)
{
    visited[start] = 1;
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i] && maze[start -1][i - 1] == 1)
            DFS(i);
    }
    cout << start << " ";
}

int main()
{
    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == 1)
            continue;
        DFS(i);
    }
    return 0;
}




