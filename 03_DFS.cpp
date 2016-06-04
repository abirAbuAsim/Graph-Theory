/*
Input matrix:
5
5
1 4
2 4
4 5
2 5
3 5
Output:
Order of discovering the vertices:
3
5
2
4
1
Vertex 1: Starting Time: 1 || Finishing Time: 10
Vertex 2: Starting Time: 3 || Finishing Time: 8
Vertex 3: Starting Time: 5 || Finishing Time: 6
Vertex 4: Starting Time: 2 || Finishing Time: 9
Vertex 5: Starting Time: 4 || Finishing Time: 7
*/
#include<bits/stdc++.h>
using namespace std;
int adjMatrix[100][100];
int color[100];
int vertex[100];
int d[100]; // discovery time
int f[100]; // finishing time
int pi[100];
int u; // number of edges
int v; // number of vertices
int timer;

void DFS_visit(int u)
{
    timer = timer + 1;
    d[u] = timer;
    color[u] = 1;
    for(int i = 1; i <= v; i++)
    {
        if(adjMatrix[u][i] == 1)
        {
            if(color[i] == 0)
            {
                pi[i] = u;
                DFS_visit(i);
            }
        }
    }
    color[u] = 2;
    timer = timer + 1;
    f[u] = timer;
    printf("%d\n", u);
}

void DFS()
{
    for(int i = 1; i <= v; i++)
    {
        color[i] = 0;
    }
    timer = 0;
    for (int i = 1; i <= v; i++)
    {
        if(color[i] == 0)
        {
            DFS_visit(i);
        }
    }
}

int main()
{
    int v1, v2;
    printf("Edge: ");
    scanf("%d", &u);
    printf("Vertex: ");
    scanf("%d", &v);
    for(int i = 1; i <= v; i++)
    {
        scanf("%d%d", &v1, &v2);
        adjMatrix[v1][v2] = 1;
        adjMatrix[v2][v1] = 1;
    }
    printf("\nOrder of discovering the vertices:\n\n");
    DFS();
    for(int i = 1; i <= v; i++)
    {
        printf("Vertex %d: Starting Time: %d || Finishing Time: %d\n", i, d[i], f[i]);
    }
    return 0;
}
