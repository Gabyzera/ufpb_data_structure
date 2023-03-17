#include <stdio.h>
#define MAX 10 

typedef struct{
    int elementos[MAX];
    int quantidade;
}lista_sequencial;

void criar_lista (lista_sequencial *lista){
    lista->quantidade = 0;
}

int esta_vazia(lista_sequencial lista) {
    return lista.quantidade == 0;
}

int esta_cheia(lista_sequencial lista) {
    return lista.quantidade == MAX;
}

int tamanho(lista_sequencial lista){
  return lista.quantidade;
}

int posicao_elemento(lista_sequencial lista, int posicao){
  if(posicao > 0 && posicao <= lista.quantidade){
    return lista.elementos[posicao];
  }else{
    printf("Posicao invalida!\n");
  }
}

void modificar_elemento(lista_sequencial *lista, int posicao, int valor){
  if (posicao > 0 && posicao <= lista->quantidade){
    lista->elementos[posicao] = valor;
  }else{
    printf("Posicao invalida!\n");
  }
}

void inserir_elemento(lista_sequencial *lista, int posicao, int valor) {
    if (esta_cheia(*lista)) {
        printf("Lista cheia!\n");
    }
    if (posicao <= 0 || posicao > lista->elementos) {
        printf("Posicao invalida!\n");
    }
    for (int i = lista->quantidade; i > posicao; i--) {
        lista->elementos[i] = lista->elementos[i-1];
    }
    lista->elementos[posicao] = valor;
    lista->quantidade++;
}

int retirar_elemento(lista_sequencial *lista, int posicao) {
    if (esta_vazia(*lista)) {
        printf("Lista vazia\n");
    }
    if (posicao < 1 || posicao > lista->quantidade) {
        printf("Posicao invalida!\n");
    }
    int valor = lista->elementos[posicao];
    for (int i = posicao; i < lista->quantidade-1; i++) {
        lista->elementos[i] = lista->elementos[i+1];
    }
    lista->quantidade--;
    return valor;
}

int main(){
    lista_sequencial lista;
    criar_lista(&lista);

    // 1 = sim 2 = não
    printf("Lista esta' vazia? %d\n", esta_vazia(lista));
    printf("Lista esta' cheia? %d\n", esta_cheia(lista));
    printf("O tamanho da lista e' %d\n", tamanho(lista));

    // exemplos para testagem
    inserir_elemento(&lista, 1, 10);
    inserir_elemento(&lista, 2, 20);
    inserir_elemento(&lista, 3, 30);
  
    printf("Elemento na posição 1: %d\n", posicao_elemento(lista, 1));
    printf("Elemento na posição 2: %d\n", posicao_elemento(lista, 2));
    printf("Elemento na posição 3: %d\n", posicao_elemento(lista, 3));

    modificar_elemento(&lista, 1, 25);
    retirar_elemento (&lista,2);
    
    printf("Elemento na posição 1: %d\n", posicao_elemento(lista, 1));
    printf("Tamanho da lista: %d\n", tamanho(lista));
  }
