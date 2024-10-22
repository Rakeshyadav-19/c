#include <iostream>

using namespace std;

// Enum to define node types: AND or OR
enum NodeType { AND_NODE, OR_NODE };

// Function to check if a node is satisfied
bool isSatisfied(int type, int children[], int numChildren, bool satisfied[]) {
    if (type == AND_NODE) {
        // For AND node, all children must be satisfied
        for (int i = 0; i < numChildren; i++) {
            if (!satisfied[children[i]]) return false;
        }
        return true;
    } else if (type == OR_NODE) {
        // For OR node, at least one child must be satisfied
        for (int i = 0; i < numChildren; i++) {
            if (satisfied[children[i]]) return true;
        }
        return false;
    }
    return false;
}

int main() {
    int n;  // Number of nodes
    cout << "Enter the number of nodes: ";
    cin >> n;

    int types[10];  // Array to store the type of each node (AND/OR)
    int children[10][10];  // Array to store the children of each node
    int numChildren[10];  // Array to store the number of children for each node
    bool satisfied[10] = { false };  // Array to mark if a node is satisfied

    // Input node types and their children
    for (int i = 0; i < n; i++) {
        cout << "Enter type of node " << i << " (0 for AND, 1 for OR): ";
        cin >> types[i];
        cout << "Enter the number of children for node " << i << ": ";
        cin >> numChildren[i];
        for (int j = 0; j < numChildren[i]; j++) {
            cout << "Enter child " << j + 1 << " of node " << i << ": ";
            cin >> children[i][j];
        }
    }

    // Input the initially satisfied nodes
    int numSatisfied;
    cout << "Enter the number of initially satisfied nodes: ";
    cin >> numSatisfied;
    for (int i = 0; i < numSatisfied; i++) {
        int node;
        cout << "Enter node that is initially satisfied: ";
        cin >> node;
        satisfied[node] = true;
    }

    // Check each node and determine if it can be satisfied
    for (int i = 0; i < n; i++) {
        if (!satisfied[i] && isSatisfied(types[i], children[i], numChildren[i], satisfied)) {
            satisfied[i] = true;
            cout << "Node " << i << " is now satisfied." << endl;
        }
    }

    return 0;
}
