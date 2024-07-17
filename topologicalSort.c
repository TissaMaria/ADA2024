#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
Node* adjList[MAX_NODES];

int visited[MAX_NODES] = {0};

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


    printf("Topological Order:\n");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int vertices, edges;
    int start, end;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
     
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (start end): \n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &start, &end);
        addEdge(start, end);
    }

    topologicalSort();

    return 0;
}
