#include <stdio.h>

#define V 8

int visited[V];

void dfs(int graph[V][V], int start) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs(graph, i);
        }
    }
}

int main() {
    int graph[V][V] = {
        {0,1,0,0,0,0,0,1},
        {1,0,1,1,0,0,0,0},
        {0,1,0,0,1,0,0,0},
        {0,1,0,0,0,1,0,0},
        {0,0,1,0,0,1,0,0},
        {0,0,0,1,1,0,1,0},
        {0,0,0,0,0,1,0,1},
        {1,0,0,0,0,0,1,0}
    };

    for (int i = 0; i < V; i++) visited[i] = 0;

    printf("DFS Traversal: ");
    dfs(graph, 0);

    return 0;
}
