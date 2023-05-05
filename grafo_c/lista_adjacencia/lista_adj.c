#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int vertex;
    struct node* next;
} node;

typedef struct graph {
    int num_vertices;
    node** adj_list;
} graph;

node* create_node(int v) {
    node* new_node = malloc(sizeof(node));
    new_node->vertex = v;
    new_node->next = NULL;
    return new_node;
}

graph* create_graph(int n) {
    graph* new_graph = malloc(sizeof(graph));
    new_graph->num_vertices = n;
    new_graph->adj_list = malloc(n * sizeof(node*));
    int i;
    for (i = 0; i < n; i++) {
        new_graph->adj_list[i] = NULL;
    }
    return new_graph;
}

void add_edge(graph* g, int src, int dest) {
    node* new_node = create_node(dest);
    new_node->next = g->adj_list[src];
    g->adj_list[src] = new_node;

    new_node = create_node(src);
    new_node->next = g->adj_list[dest];
    g->adj_list[dest] = new_node;
}

void print_graph(graph* g) {
    int i;
    for (i = 0; i < g->num_vertices; i++) {
        node* tmp = g->adj_list[i];
        printf("Adjacência do vértice %d: ", i);
        while (tmp) {
            printf("%d -> ", tmp->vertex);
            tmp = tmp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    graph* g = create_graph(4);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    print_graph(g);
    return 0;
}