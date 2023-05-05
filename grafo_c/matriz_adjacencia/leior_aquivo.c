#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int matriz[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} GrafoMatriz;

int main() {
    FILE* arquivo = fopen("grafo.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        exit(1);
    }
    
    int num_vertices;
    fscanf(arquivo, "%d", &num_vertices);

    GrafoMatriz grafo;
    grafo.num_vertices = num_vertices;
    
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            grafo.matriz[i][j] = 0;
        }
    }

    int v1, v2;
    while (fscanf(arquivo, "%d %d", &v1, &v2) == 2) {
        grafo.matriz[v1][v2] = 1;
        grafo.matriz[v2][v1] = 1; 
    }
    
    fclose(arquivo);

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            printf("%d ", grafo.matriz[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
