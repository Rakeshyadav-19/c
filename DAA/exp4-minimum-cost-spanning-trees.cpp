#include <stdio.h>
#include <stdlib.h>

int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];

int find(int);
int uni(int, int);

int main()
{ // Change void to int
  printf("\n\tImplementation of Kruskal's Algorithm\n");
  printf("\nEnter the number of vertices: ");
  scanf("%d", &n);

  // Initialize parent array
  for (i = 1; i <= n; i++)
  {
    parent[i] = -1; // Initialize parent array for union-find
  }

  printf("\nEnter the cost adjacency matrix:\n");
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      scanf("%d", &cost[i][j]);
      if (cost[i][j] == 0)
      {
        cost[i][j] = 999; // Replace 0 with a high value to indicate no edge
      }
    }
  }

  printf("\nThe edges of Minimum Cost Spanning Tree are:\n");
  while (ne < n)
  { // This should be `ne < n-1` for MST
    min = 999;
    for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= n; j++)
      {
        if (cost[i][j] < min)
        {
          min = cost[i][j];
          a = u = i;
          b = v = j;
        }
      }
    }

    // Check if the selected edge forms a cycle
    if (uni(u, v))
    {
      printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
      mincost += min;
    }

    // Mark the edge as processed (remove it from the graph)
    cost[a][b] = cost[b][a] = 999;
  }

  printf("\n\tMinimum cost = %d\n", mincost);

  return 0; // Return 0 to indicate successful execution
}

int find(int i)
{
  while (parent[i] >= 0) // Find the root of the set
    i = parent[i];
  return i;
}

int uni(int i, int j)
{
  int root1 = find(i);
  int root2 = find(j);

  if (root1 != root2)
  {
    // Union by rank (or simple linking)
    parent[root2] = root1;
    return 1; // Successful union, no cycle
  }
  return 0; // Cycle detected, no union
}