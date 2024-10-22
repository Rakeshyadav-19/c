#include <iostream>
using namespace std;

const int MAX_NODES = 100;  // Maximum number of nodes
int graph[MAX_NODES][MAX_NODES];  // Adjacency matrix
bool visited[MAX_NODES];  // Visited array

void dfs(int node, int nodes) {
    visited[node] = true;
    cout << node << " ";

    // Explore all adjacent nodes of the current node
    for (int i = 0; i < nodes; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, nodes);
        }
    }
}

int main() {
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    // Initialize the graph (adjacency matrix) with 0
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            graph[i][j] = 0;
        }
    }

    // Read edges and fill the adjacency matrix
    cout << "Enter the edges (u v format): " << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;  // If the graph is undirected
    }

    // Initialize visited array
    for (int i = 0; i < nodes; i++) {
        visited[i] = false;
    }

    // Perform DFS traversal from the first node (node 0)
    cout << "DFS Traversal: ";
    dfs(0, nodes);

    return 0;
}
