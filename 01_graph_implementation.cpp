/*
    This program does the following
    - takes vertex and edge input
    - displays the adjacency matrix
    - shows the degree of each vertex
    - shows if the graph is simple or not (finds loops)
    - finds if the graph is wheel or not
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int vertex, edge, v1, v2;
    int adjMatrix[100][100];
    int degreeOfVertex[100];
    memset(adjMatrix, 0, sizeof(adjMatrix)); // assigning zero in every index of the array
    memset(degreeOfVertex, 0, sizeof(degreeOfVertex)); // assigning zero in every index of the array

    printf("Enter number of vertices: ");
    scanf("%d", &vertex);
    printf("Enter number of edges: ");
    scanf("%d", &edge);
    for (int i = 0; i < edge; i++)
    {
        printf("Enter two adjacent vertices of an edge: ");
        scanf("%d%d", &v1, &v2);
        adjMatrix[v1][v2] = 1;
        adjMatrix[v2][v1] = 1;
    }

    // Display the adjacency matrix
    int sumForLoops = 0;
    printf("\nThe Adjacency Matrix\n");
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            printf("%d", adjMatrix[i][j]);

            // finding degree
            if(adjMatrix[i][j] == 1)
            {
                degreeOfVertex[i]++;
            }

        }
        // checking for loop
        if(adjMatrix[i][i] == 0)
        {
            sumForLoops++;
        }
        printf("\n");
    }

    // display the degree of every vertex
    printf("\nDegree of all vertices:\n");
    bool centreVertex = false; // centre vertex of the wheel
    int otherVertices = 0;
    for(int i = 0; i < vertex; i++)
    {
        printf("Vertex %d : %d\n", i, degreeOfVertex[i]);

        // Determining if a graph is wheel or not
        // degree of the centre vertex of a wheel is always 1 less than the total vartices
        // all the other vertices except the centre vertex have exactly degree 3
        if(degreeOfVertex[i] == (vertex - 1))
        {
            centreVertex = true;
        }
        if(degreeOfVertex[i] == 3)
        {
            otherVertices++;
        }
    }

    // display loop info
    if(sumForLoops == vertex)
    {
        printf("\nThis is a simple graph\n");
    } else
    {
        printf("\nThis is a Not simple graph\n");
    }

    // if the graph does not have a centre vertex then its not a wheel
    if(!centreVertex)
    {
        printf("\nThis Graph is Not a Wheel\n");
    }

    // if the graph has a centre vertex and all the other vertices have degree 3
    if(centreVertex && (otherVertices == vertex - 1))
    {
        printf("\nThis Graph is a Wheel\n");
    }
    return 0;
}
