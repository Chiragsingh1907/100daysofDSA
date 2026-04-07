#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX]; // Adjacency Matrix
int V, E;

bool isCyclicUtil(int v, bool visited[], bool recStack[]) {
    if (visited[v] == false) {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Recur for all vertices adjacent to this vertex
        for (int i = 0; i < V; ++i) {
            if (adj[v][i]) {
                if (!visited[i] && isCyclicUtil(i, visited, recStack))
                    return true;
                else if (recStack[i])
                    return true;
            }
        }
    }
    // Remove the vertex from recursion stack before returning
    recStack[v] = false;
    return false;
}

bool isCyclic() {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    // Call the recursive helper function for all vertices
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    // Example: A graph with a cycle 0 -> 1 -> 2 -> 0
    V = 3;
    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][0] = 1;

    if (isCyclic())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}