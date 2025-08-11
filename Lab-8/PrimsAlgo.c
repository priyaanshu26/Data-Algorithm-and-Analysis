#include <stdio.h>

void PrimsAlgo(int V, int adj[V][V]) {
    int selected[V];     // Array to track included vertices
    for (int i = 0; i < V; i++) selected[i] = 0;

    selected[0] = 1;      // Start from vertex 0
    int edge = 0;

    while (edge < V - 1) {
        int min = __INT_MAX__;
        int x = 0, y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && adj[i][j] && adj[i][j] < min) {
                        min = adj[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("Edge %d: %d - %d with weight %d\n", edge + 1, x, y, adj[x][y]);
        selected[y] = 1;
        edge++;
    }
}

int main() {
    int V = 5;
    int adj[5][5] = {
        {0, 4, 6, 6, 5},
        {4, 0, 2, 0, 3},
        {6, 2, 0, 1, 5},
        {6, 0, 1, 0, 2},
        {5, 3, 5, 2, 0}
    };

    PrimsAlgo(V, adj);
    return 0;
}
