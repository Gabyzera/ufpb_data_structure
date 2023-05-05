#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Grafo{
  int matriz_adj[MAX_VERTICES][MAX_VERTICES];
  int num_vertices;
} Grafo;

Grafo* cria_grafo(int num_vertices){
  Grafo* g = (Grafo*) malloc(sizeof(Grafo));
  g->num_vertices = num_vertices;

  for (int i = 0; i < num_vertices; i++){
    for (int j = 0; j < num_vertices; j++){
      g->matriz_adj[i][j] = 0; 
    }
  }

  return g; 
}

void adiciona_aresta(Grafo* g, int vertice_origem, int vertice_destino){
  g->matriz_adj[vertice_origem][vertice_destino] = 1;
  g->matriz_adj[vertice_destino][vertice_origem] = 1; 
}

void remove_aresta(Grafo* g, int vertice_origem, int vertice_destino){
  g->matriz_adj[vertice_origem][vertice_destino] = 0;
  g->matriz_adj[vertice_destino][vertice_origem] = 0; 
}

void imprime_matriz_adj(Grafo* g){
  for(int i = 0; i < g -> num_vertices; i++){
    for(int j = 0; j < g -> num_vertices; j++))
      printf("%d", g -> matriz_adj[i][j]);
  }
  printf("\n");
}

int main(){
  Grafo* g = cria_grafo(5);
  
  adiciona_aresta(g, 0, 1);
  adiciona_aresta(g, 0, 2);
  adiciona_aresta(g, 1, 3);
  adiciona_aresta(g, 2, 3);
  adiciona_aresta(g, 2, 4);

  imprime_matriz_adj(g); 

  return 0; 
}