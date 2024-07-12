#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
// Adjacency List Representation
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
Node* adjList[MAX_NODES];
// Visited Array to keep track of visited nodes
int visited[MAX_NODES] = {0};
// Stack to hold the topological order
int stack[MAX_NODES];
int top = -1;
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;//insert at beg
}

void DFS(int node) {
    visited[node] = 1;
    Node* adjNode = adjList[node];//first adjoint node 
    while (adjNode != NULL) {//traverse through all 
        if (!visited[adjNode->vertex]) {
            DFS(adjNode->vertex);
        }
        adjNode = adjNode->next;
    }
    // Pushing the node to the stack after all its descendants have been visited
    stack[++top] = node;
}

void topologicalSort() {
    for (int i = 0; i < MAX_NODES; i++) {
        if (adjList[i] != NULL && !visited[i]) {
            DFS(i);
        }
    }

    // Printing the topological order
    printf("Topological Order:\n");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    // Initialize the adjacency list
    for (int i = 0; i < MAX_NODES; i++) {
        adjList[i] = NULL;
    }

    // Add edges
    addEdge(4,0);
    addEdge(4,1);
    addEdge(3,1);
    addEdge(5,0);
    addEdge(2,3);
    addEdge(5,2);
    topologicalSort();

    return 0;
}
