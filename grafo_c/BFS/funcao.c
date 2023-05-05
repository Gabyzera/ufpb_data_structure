#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

typedef struct {
    int n; 
    int mat[MAX_VERTICES][MAX_VERTICES]; 
} Grafo;

void add_edge(Grafo *G, int u, int v) {
    G->mat[u][v] = 1;
    G->mat[v][u] = 1; 
}

void bfs_path(Grafo *G, int s, int t, int parent[]) {
    if (parent[t] == -1) {
        printf("Não há caminho entre os vértices.\n");
        return;
    }

    int path[MAX_VERTICES], len = 0;
    int curr = t;
    while (curr != -1) {
        path[len++] = curr;
        curr = parent[curr];
    }

    printf("Caminho encontrado: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

void bfs(Grafo *G, int s, int parent[]) {
    int queue[MAX_VERTICES], front = 0, back = 0;
    bool visited[MAX_VERTICES] = { false }; 

    queue[back++] = s;
    visited[s] = true;
    parent[s] = -1; 

    while (front < back) {
        int u = queue[front++];

        for (int v = 0; v < G->n; v++) {
            if (G->mat[u][v] == 1 && !visited[v]) {
                queue[back++] = v;
                visited[v] = true;
                parent[v] = u;
            }
        }
    }
}

int main() {
    Grafo* g = criaGrafo(6);
    leGrafo("grafo.txt", g);

    int s = 0;
    int t = 5;

    printf("Caminho entre %d e %d: ", s, t);
    bfs(g, s, t);

    destroiGrafo(g);
    return 0;
}
