#include <stdio.h>
#include <stdlib.h>

struct no {
    int valor;
    struct no *prox;
};

typedef struct no No;

struct pilha {
    No *topo;
    int tamanho;
};

typedef struct pilha Pilha;

Pilha *criar_pilha() {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

int pilha_vazia(Pilha *p) {
    return (p->topo == NULL);
}

int tamanho_pilha(Pilha *p) {
    return p->tamanho;
}

int topo_pilha(Pilha *p) {
    if (pilha_vazia(p)) {
        printf("Pilha vazia\n");
        return -1;
    }
    return p->topo->valor;
}

void push(Pilha *p, int valor) {
    No *novo_no = (No *) malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->prox = p->topo;
    p->topo = novo_no;
    p->tamanho++;
}

void pop(Pilha *p) {
    if (pilha_vazia(p)) {
        printf("Pilha vazia\n");
        return;
    }
    No *no_removido = p->topo;
    p->topo = p->topo->prox;
    free(no_removido);
    p->tamanho--;
}
