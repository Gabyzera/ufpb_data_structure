#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct list {
    Node* head;
    int size;
} List;

List* createList() {
    List* list = (List*) malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

int isEmpty(List* list) {
    return (list->head == NULL);
}

int size(List* list) {
    return list->size;
}

Node* getNode(List* list, int pos) {
    if (isEmpty(list) || pos < 0 || pos >= list->size) {
        return NULL;
    }

    Node* current = list->head;
    int i;
    for (i = 0; i < pos; i++) {
        current = current->next;
    }
    return current;
}

int getValue(List* list, int pos) {
    Node* node = getNode(list, pos);
    if (node == NULL) {
        return -1;
    }
    return node->data;
}

void setValue(List* list, int pos, int value) {
    Node* node = getNode(list, pos);
    if (node != NULL) {
        node->data = value;
    }
}

void insert(List* list, int pos, int value) {
    if (pos < 0 || pos > list->size) {
        return;
    }

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;

    if (pos == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        Node* prev = getNode(list, pos-1);
        newNode->next = prev->next;
        prev->next = newNode;
    }

    list->size++;
}

void removeNode(List* list, int pos) {
    if (isEmpty(list) || pos < 0 || pos >= list->size) {
        return;
    }

    Node* nodeToRemove;
    if (pos == 0) {
        nodeToRemove = list->head;
        list->head = list->head->next;
    } else {
        Node* prev = getNode(list, pos-1);
        nodeToRemove = prev->next;
        prev->next = nodeToRemove->next;
    }

    free(nodeToRemove);
    list->size--;
}

void printList(List* list) {
    if (isEmpty(list)) {
        printf("A lista esta vazia\n");
    } else {
        printf("Elementos da lista: ");
        Node* current = list->head;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}
