#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.c"

int main() {
    List* list = createList();

    printList(list);
    
    printf("Tamanho da lista: %d\n", size(list));

    insert(list, 0, 10);
    insert(list, 1, 20);
    insert(list, 1, 15);
    printList(list); 

    setValue(list, 0, 5);
    printList(list); 

    removeNode(list, 1);
    printList(list); 

    printf("Tamanho da lista: %d\n", size(list));
    
    return 0;
}
