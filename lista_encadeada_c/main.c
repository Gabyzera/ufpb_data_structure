#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

typedef struct lista{
    Node* head;
    int size;
}lista_encadeada;

lista_encadeada* create_list() {
    lista_encadeada* lista = (lista_encadeada*) malloc(sizeof(lista_encadeada));
    lista->head = NULL;
    lista->size = 0;
}

int is_empty(lista_encadeada* lista) {
    return (lista->head == NULL);
}

int size(lista_encadeada* lista) {
    return lista->size;
}

Node* get_Node(lista_encadeada* lista, int pos) {
    if (is_empty(lista) || pos < 0 || pos >= lista->size) {
        return NULL;
    }

    Node* current = lista->head;
    int i;
    for (i = 0; i < pos; i++) {
        current = current->next;
    }
    return current;
}

int get_value(lista_encadeada* lista, int pos) {
    Node* node = get_Node(lista, pos);
    if (node == NULL) {
        return -1;
    }
    return node->data;
}

void set_value(lista_encadeada* lista, int pos, int value) {
    Node* node = get_Node(lista, pos);
    if (node != NULL) {
        node->data = value;
    }
}

void insert(lista_encadeada* lista, int pos, int value) {
    if (pos < 0 || pos > lista->size) {
        return;
    }

    Node* new_Node = (Node*) malloc(sizeof(Node));
    new_Node->data = value;

    if (pos == 0) {
        new_Node->next = lista->head;
        lista->head = new_Node;
    } else {
        Node* prev = get_Node(lista, pos-1);
        new_Node->next = prev->next;
        prev->next = new_Node;
    }

    lista->size++;
}

void remove_Node(lista_encadeada* lista, int pos) {
    if (is_empty(lista) || pos < 0 || pos >= lista->size) {
        return;
    }

    Node* node_to_remove;
    if (pos == 0) {
        node_to_remove = lista->head;
        lista->head = lista->head->next;
    } else {
        Node* prev = get_Node(lista, pos-1);
        node_to_remove = prev->next;
        prev->next = node_to_remove->next;
    }

    free(node_to_remove);
    lista->size--;
}

void print_lista_encadeada(lista_encadeada* lista) {
    if (is_empty(lista)) {
        printf("A lista esta vazia!\n");
    } else {
        printf("Elementos da lista: ");
        Node* current = lista->head;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    lista_encadeada* lista = create_list();

    print_lista_encadeada(lista);
    
    printf("Tamanho da lista: %d\n", size(lista));

    insert(lista, 0, 10);
    insert(lista, 1, 15);
    insert(lista, 2, 20);

    print_lista_encadeada(lista); 

    set_value(lista, 0, 5);

    print_lista_encadeada(lista); 

    remove_Node(lista, 1);

    print_lista_encadeada(lista); 

    printf("Tamanho da lista: %d\n", size(lista));
    
    return 0;
}