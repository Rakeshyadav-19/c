#include <stdio.h>
#include <stdbool.h>

#define INF 999 // Represents infinity (no edge)

// Variables
int n; // Number of vertices
int cost[10][10]; // Cost adjacency matrix

void prim() {
    int visited[10] = {0}; // Tracks visited nodes
    int mincost = 0; // Total cost of MST
    int edges = 0; // Number of edges in MST

    visited[1] = 1; // Start from the first vertex

    printf("\nThe edges of Minimum Cost Spanning Tree are:\n");

    while (edges < n - 1) {
        int min = INF;
        int u = -1, v = -1;

        // Find the minimum cost edge from visited nodes
        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            printf("Edge (%d,%d) = %d\n", u, v, min);
            visited[v] = 1; // Mark the new vertex as visited
            mincost += min;
            edges++;
        }
    }

    printf("\nMinimum cost = %d\n", mincost);
}

int main() {
    printf("\n\tImplementation of Prim's Algorithm\n");
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INF; // Replace 0 with a high value to indicate no edge
            }
        }
    }

    prim(); // Call Prim's algorithm

    return 0;
}
