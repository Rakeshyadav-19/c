#include <stdio.h>
#include <limits.h>
#define V 4 // Number of vertices in the graph
// Function to print the colors assigned to vertices
void printSolution(int color[])
{
    printf("Vertex Coloring:\n");
    for (int i = 0; i < V; i++)
    {
        printf("Vertex %d ---> Color %d\n", i, color[i]);
    }
}
// Function to check if it is safe to color vertex v with color c
int isSafe(int v, int graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] && color[i] == c)
        {
            return 0; // Not safe if adjacent vertex has the same color
        }
    }
    return 1; // Safe if no adjacent vertex has the same color
}
// Function to perform greedy coloring of the graph
void greedyColoring(int graph[V][V])
{
    int color[V];
    for (int i = 0; i < V; i++)
    {
        color[i] = -1; // Initialize all vertices as uncolored
        color[0] = 0;  // Assign the first color to the first vertex
        // Assign colors to the remaining vertices
        for (int u = 1; u < V; u++)
        {
            // Check available colors and assign the smallest valid color
            for (int c = 0; c < V; c++)
            {
                if (isSafe(u, graph, color, c))
                {
                    color[u] = c;
                    break;
                }
            }
        }
        printSolution(color);
    }
}
int main()
{
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}};
    greedyColoring(graph);
    return 0;
}