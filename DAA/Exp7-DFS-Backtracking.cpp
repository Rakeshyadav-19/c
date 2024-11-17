#include <stdio.h>
#define MAX 100      // Define maximum number of vertices
int graph[MAX][MAX]; // Adjacency matrix
int visited[MAX];    // Visited array to keep track of visited nodes
void DFS(int vertex, int n)
{
    // Mark the current node as visited and print it
    visited[vertex] = 1;

    printf("%d ", vertex);
    // Recursively visit adjacent nodes
    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            DFS(i, n); // Recursive call for DFS on unvisited adjacent node
        }
    }
}

int main()
{
    int n, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }

        visited[i] = 0;
    }
    // Input edges in the adjacency matrix
    printf("Enter the edges (format: source destination):\n");
    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
        graph[dest][src] = 1; // For undirected graph
    }

    // Perform DFS traversal
    printf("DFS traversal starting from vertex 0:\n");
    DFS(0, n); // Start DFS from vertex 0

    return 0;
}