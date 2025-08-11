#include <stdio.h>

#define N 8

int visited[N];
int queue[N];
int front = 0, rear = -1;

void enqueue(int vertex) {
    queue[++rear] = vertex;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

void bfs(int graph[N][N], int start) {
    visited[start] = 1;
    enqueue(start);

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < N; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
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

    printf("BFS Traversal: ");
    bfs(graph, 0);

    return 0;
}
