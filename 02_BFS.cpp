/*
    This program implements the BFS algorithm and prints out the
    distances of each node/vertex from the source.
    This program follows the algorithm given in Cormen's book
*/
//Input:
//9 9
//1 2
//2 3
//3 4
//3 8
//8 9
//4 5
//5 7
//5 6
//1 7
//Output:
//Node 1 : 0
//Node 2 : 1
//Node 3 : 2
//Node 4 : 3
//Node 5 : 2
//Node 6 : 3
//Node 7 : 1
//Node 8 : 3
//Node 9 : 4
#include<bits/stdc++.h>
using namespace std;
int adjMatrix[100][100];
int dist[100]; // distance of each vertex
int color[100];
int s = 1; // source
int u; // number of edges
int v; // number of vertices
queue<int> Q;
void BFS()
{
    for(int i = 1; i <= v; i++)
    {
        color[i] = 0;
    }
    color[s] = 1;
    dist[s] = 0;
    Q.push(s);
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for(int i = 1; i <= v; i++)
        {
            if(adjMatrix[u][i] == 1)
            {
                if(color[i] == 0)
                {
                    color[i] = 1;
                    dist[i] = dist[u] + 1;
                    Q.push(i);
                }
            }
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
    BFS();
    for(int i = 1; i <= v; i++)
    {
        printf("Vertex %d : %d\n", i, dist[i]);
    }
    return 0;
}
