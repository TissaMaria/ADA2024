#include <stdio.h> 
#include <stdlib.h> 

int comparator(const void* p1, const void* p2) 
{ 
    const int(*x)[3] = p1; 
    const int(*y)[3] = p2; 
    return (*x)[2] - (*y)[2]; 
} 

void makeSet(int parent[], int rank[], int n) 
{ 
    for (int i = 0; i < n; i++) { 
        parent[i] = i; 
        rank[i] = 0; 
    } 
} 

int findParent(int parent[], int component) 
{ 
    if (parent[component] == component) 
        return component; 
    return parent[component] = findParent(parent, parent[component]); 
} 
 
void unionSet(int u, int v, int parent[], int rank[], int n) 
{ 
    u = findParent(parent, u); 
    v = findParent(parent, v); 
    if (rank[u] < rank[v]) { 
        parent[u] = v; 
    } 
    else if (rank[u] > rank[v]) { 
        parent[v] = u; 
    } 
    else { 
        parent[v] = u; 
        rank[u]++; 
    } 
} 

//MST 
void kruskalAlgo(int n, int edge[n][3], int vertices) 
{ 
    qsort(edge, n, sizeof(edge[0]), comparator); 

    int parent[vertices]; 
    int rank[vertices]; 
    makeSet(parent, rank, vertices); 

    int minCost = 0; 
    printf("Following are the edges in the constructed MST\n"); 
    for (int i = 0; i < n; i++) { 
        int v1 = findParent(parent, edge[i][0]); 
        int v2 = findParent(parent, edge[i][1]); 
        int wt = edge[i][2]; 
        if (v1 != v2) { 
            unionSet(v1, v2, parent, rank, vertices); 
            minCost += wt; 
            printf("%d -- %d == %d\n", edge[i][0], edge[i][1], wt); 
        } 
    } 
    printf("Minimum Cost Spanning Tree: %d\n", minCost); 
} 

int main() 
{ 
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    int (*edge)[3] = malloc(edges * sizeof(*edge));
    if (edge == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the edges (format: v1 v2 w):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &edge[i][0], &edge[i][1], &edge[i][2]);
    }

    kruskalAlgo(edges, edge, vertices);

    free(edge);
    return 0; 
}
