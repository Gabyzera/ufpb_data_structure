#include <stdio.h>

#define MAX_NODES 10

void dfs_iterative(int v) {
    int visited[MAX_NODES] = {0};
    int stack[MAX_NODES];
    int top = -1;

    stack[++top] = v;

    while (top >= 0) {
        int u = stack[top--];

        if (!visited[u]) {
            visited[u] = 1;
            printf("%d ", u);

            for (int i = 0; i < num_nodes; i++) {
                if (adjacency_matrix[u][i] && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
}
