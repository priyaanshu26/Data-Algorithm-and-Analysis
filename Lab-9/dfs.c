#include <stdio.h>

#define N 8

int visited[N];

void dfs(int graph[N][N], int start) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < N; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs(graph, i);
        }
    }
}

int main() {
    int graph[N][N] = {
        {0,1,0,0,0,0,0,1},
        {1,0,1,1,0,0,0,0},
        {0,1,0,0,1,0,0,0},
        {0,1,0,0,0,1,0,0},
        {0,0,1,0,0,1,0,0},
        {0,0,0,1,1,0,1,0},
        {0,0,0,0,0,1,0,1},
        {1,0,0,0,0,0,1,0}
    };

    for (int i = 0; i < N; i++) visited[i] = 0;

    printf("DFS Traversal: ");
    dfs(graph, 0);

    return 0;
}
