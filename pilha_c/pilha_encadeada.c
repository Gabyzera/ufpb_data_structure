#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct pilha{
    Node* head;
    int size;
}pilha_encadeada;

pilha_encadeada* create_stack() {
    pilha_encadeada* pilha = (pilha_encadeada*) malloc(sizeof(pilha_encadeada));
    pilha->head = NULL;
    pilha->size = 0;
}

int is_empty(pilha_encadeada* pilha) {
    return (pilha->head == NULL);
}

int size(pilha_encadeada* pilha) {
    return pilha->size;
}

int head_stack(pilha_encadeada* pilha) {
    if (is_empty(pilha)) {
        printf("Pilha vazia\n");
        return -1;
    }
    return pilha->head->data;
}

void push(pilha_encadeada* pilha, int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = pilha->head;
    pilha->head = new_node;
    pilha->size++;
}

void pull(pilha_encadeada* pilha) {
    if (is_empty(pilha)) {
        printf("Pilha vazia!\n");
    } else {
        Node *node_removed = pilha->head;
        pilha->head = pilha->head->next;
        free(node_removed);
        pilha->size--;
    }
}

void print_pilha_encadeada(pilha_encadeada* pilha) {
    if (is_empty(pilha)) {
        printf("Pilha vazia!\n");
    } else {
        printf("Elementos da pilha: ");
        Node* current = pilha->head;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}


int main(){
    pilha_encadeada* pilha = create_stack();

    print_pilha_encadeada(pilha);
    
    printf("Tamanho da pilha: %d\n", size(pilha));

    push(pilha, 0);
    push(pilha, 1);
    push(pilha, 2);

    print_pilha_encadeada(pilha); 

    pull(pilha);

    print_pilha_encadeada(pilha); 

    printf("Tamanho da pilha: %d\n", size(pilha));
    
    return 0;
}