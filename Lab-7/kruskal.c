#include <stdio.h>

struct Edge {
    int src, dest, weight;
};

void sortEdges(struct Edge edges[], int numEdges) {
    for (int i = 0; i < numEdges - 1; i++) {
        for (int j = 0; j < numEdges - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int findParent(int parent[], int i) {
    if (parent[i] == i) return i;
    return findParent(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = findParent(parent, x);
    int yroot = findParent(parent, y);

    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot;
    } else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void kruskal(int numVertices, struct Edge edges[], int numEdges) {
    struct Edge result[numVertices]; // To store the resultant MST
    int parent[numVertices];
    int rank[numVertices];
    
    for (int i = 0; i < numVertices; i++) {
        parent[i] = -1;
        rank[i] = 0;
    }

    sortEdges(edges, numEdges);

    int e = 0; // Count of edges in MST
    for (int i = 0; i < numEdges && e < numVertices - 1; i++) {
        int x = findParent(parent, edges[i].src);
        int y = findParent(parent, edges[i].dest);

        if (x != y) {
            result[e++] = edges[i];
            unionSets(parent, rank, x, y);
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    }
}

void main() {
    int numVertices = 4; // Number of vertices in the graph
    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    int numEdges = sizeof(edges) / sizeof(edges[0]);

    kruskal(numVertices, edges, numEdges);
}