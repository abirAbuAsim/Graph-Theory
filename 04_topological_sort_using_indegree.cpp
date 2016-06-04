/*
8
6
1 3
2 3
3 4
3 5
3 6
4 6
5 6
4 5
*/
#include<bits/stdc++.h>
using namespace std;
int adjMatrix[100][100];
int inDegree[100];
int vertex[100];
int s = 1; // source
int u; // number of edges
int v; // number of vertices


int main()
{
    int v1, v2;
    printf("Edge: ");
    scanf("%d", &u);
    printf("Vertex: ");
    scanf("%d", &v);
    for(int i = 1; i <= u; i++)
    {
        scanf("%d%d", &v1, &v2);
        adjMatrix[v1][v2] = 1;
    }
    printf("\nOrder of discovering the vertices:\n\n");

    for(int i = 1; i <= v; i++)
    {
        for(int j = 1; j <= v; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    for(int col = 1; col <= v; col++)
    {
        for(int row = 1; row <= v; row++)
        {
            inDegree[col] += adjMatrix[row][col];
        }
    }
    for(int i = 1; i <= v; i++)
    {
        printf("vertex %d : indegree %d\n", i, inDegree[i]);
    }

    for(int i = 1; i <= v; i++)
    {
        if(inDegree[i] == 0)
        {
            printf("%d ", i);
            if(i != v)
            {
                printf("-> ");
            }
            for(int j = 1; j <= v; j++)
            {
                if(adjMatrix[i][j] == 1)
                {
                    inDegree[j]--;
                }
            }
        }
    }
    return 0;
}
