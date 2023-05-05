#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct node {
    int vertex;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    int degree;
} Vertex;

typedef struct {
    Vertex vertices[MAX_VERTICES];
    int num_vertices;
    int num_edges;
    int is_directed;
} Graph;

void init_graph(Graph *g, int n, int is_directed) {
    g->num_vertices = n;
    g->num_edges = 0;
    g->is_directed = is_directed;
    for (int i = 0; i < n; i++) {
        g->vertices[i].head = NULL;
        g->vertices[i].degree = 0;
    }
}

void add_edge(Graph *g, int u, int v) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->vertex = v;
    new_node->next = g->vertices[u].head;
    g->vertices[u].head = new_node;
    g->vertices[u].degree++;
    g->num_edges++;
    if (!g->is_directed) {
        add_edge(g, v, u);
    }
}

Graph* read_graph(char *filename, int is_directed) {
    FILE *fp;
    Graph *g;
    int n, u, v;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fscanf(fp, "%d", &n);
    g = (Graph *)malloc(sizeof(Graph));
    init_graph(g, n, is_directed);

    while (fscanf(fp, "%d %d", &u, &v) != EOF) {
        add_edge(g, u, v);
    }

    fclose(fp);

    return g;
}

void print_graph(Graph *g) {
    printf("Numero de vertices: %d\n", g->num_vertices);
    printf("Numero de arestas: %d\n", g->num_edges);
    printf("Grafo %s\n", g->is_directed ? "direcionado" : "nao direcionado");
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertice %d - grau %d: ", i, g->vertices[i].degree);
        Node *node = g->vertices[i].head;
        while (node != NULL) {
            printf("%d ", node->vertex);
            node = node->next;
        }
        printf("\n");
    }
}

int main() {
    Graph *g = read_graph("grafo.txt", 0);
    print_graph(g);
    return 0;
}
