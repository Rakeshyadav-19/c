#include <stdio.h>
#include <stdbool.h>

#define MAX 20

// Define types for nodes in the AND/OR graph
typedef enum
{
    AND,
    OR
} NodeType;

// Struct to represent a node in the graph
typedef struct
{
    NodeType type;     // AND or OR node
    int numChildren;   // Number of children (paths)
    int children[MAX]; // Indices of child nodes (0-based)
} Node;

// Sample AND/OR graph
Node graph[MAX];

// A helper function to simulate the DFS search in the AND/OR graph
bool dfs(int nodeIndex, bool visited[MAX])
{
    if (visited[nodeIndex])
    {

        return false; // Avoid revisiting nodes
    }

    visited[nodeIndex] = true;

    // If it's an OR-node, we just need one successful path
    if (graph[nodeIndex].type == OR)
    {
        for (int i = 0; i < graph[nodeIndex].numChildren; i++)
        {
            int child = graph[nodeIndex].children[i];
            if (dfs(child, visited))
            {
                return true;
            }
        }
        return false;
    }

    // If it's an AND-node, all paths must be successful
    if (graph[nodeIndex].type == AND)
    {
        for (int i = 0; i < graph[nodeIndex].numChildren; i++)
        {

            int child = graph[nodeIndex].children[i];
            if (!dfs(child, visited))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main()
{
    int N; // Number of nodes in the graph

    printf("Enter number of nodes in the AND/OR graph: ");
    scanf("%d", &N);

    // Initialize the nodes
    for (int i = 0; i < N; i++)
    {
        printf("Enter type of node %d (0 for AND, 1 for OR): ", i);
        int type;
        scanf("%d", &type);

        graph[i].type = (type == 0) ? AND : OR;

        printf("Enter the number of children for node %d: ", i);
        scanf("%d", &graph[i].numChildren);

        for (int j = 0; j < graph[i].numChildren; j++)
        {
            printf("Enter child %d for node %d: ", j + 1, i);
            scanf("%d", &graph[i].children[j]);
        }
    }
    // Assume the starting node is node 0
    bool visited[MAX] = {false};
    if (dfs(0, visited))
    {
        printf("Solution found!\n");
    }
    else
    {
        printf("No solution exists.\n");
    }
    return 0;
}