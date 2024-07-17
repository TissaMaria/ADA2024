#include <stdio.h>
#define MAX_VERTICES 100
void topologicalSort(int vertices, int adjMatrix[][MAX_VERTICES]) {
    int indegree[vertices];
    int i, j, k;
    for (i = 0; i < vertices; i++) {
        indegree[i] = 0;//initialize
        for (j = 0; j < vertices; j++) {
            if (adjMatrix[j][i] != 0)
                indegree[i]++;//find indegree
        }
    }
    for (i = 0; i < vertices; i++) {
        // Find a vertex with indegree 0
        for (j = 0; j < vertices; j++) {
            if (indegree[j] == 0) {
                printf("%d ", j);
                indegree[j] = -1; // mark vertex as visited
                // reduce indegree of adjacent vertices
                for (k = 0; k < vertices; k++) {
                    if (adjMatrix[j][k] != 0)
                        indegree[k]--;
                }
                break; //break to find next vertex with indegree=0
            }
        }
    }
}

int main() {
    int vertices, edges, i, j, start, end;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the edges (format: start_vertex end_vertex):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &start, &end);
        adjMatrix[start][end] = 1;
    }
    printf("\nTopological Sort using source removal: ");
    topologicalSort(vertices, adjMatrix);

    printf("\n");

    return 0;
}
