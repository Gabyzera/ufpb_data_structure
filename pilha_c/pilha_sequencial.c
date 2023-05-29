#include <stdio.h>
#define MAX 10 

typedef struct{
    int data[MAX];
    int size;
}pilha_sequencial;

void create_stack(pilha_sequencial *pilha){
    pilha->size = 0;
}

int is_empty(pilha_sequencial pilha) {
    return pilha.size == 0;
}

int its_full(pilha_sequencial pilha) {
    return pilha.size == MAX;
}

int size(pilha_sequencial pilha){
  return pilha.size;
}

int position_data(pilha_sequencial pilha, int position){
  if (position > 0 || position <= pilha.size){
    return pilha.data[position];
  }else{
    printf("Posicao invalida!\n");
  }
}

void modify_data(pilha_sequencial *pilha, int position, int value){
  if (position > 0 || position <= pilha->size){
    pilha->data[position] = value;
  } else {
    printf("Posicao invalida!\n");
  }
}

void insert_data(pilha_sequencial *pilha, int position, int value){
    if (its_full(*pilha)){
        printf("Pilha cheia!\n");
    }
    if (position <= 0 || position < pilha->size){
        printf("Posicao invalida!\n");
    }
    for (int i = pilha->size; i > position; i--) {
        pilha->data[i] = pilha->data[i-1];
    }
    pilha->data[position] = value;
    pilha->size++;
}

int removed_data(pilha_sequencial *pilha, int position) {
    if (is_empty(*pilha)) {
        printf("Pilha vazia!\n");
    }
    if (position < 1 || position > pilha->size) {
        printf("Posicao invalida!\n");
    }
    int value = pilha->data[position];
    for (int i = position; i <= pilha->size-1; i++) {
        pilha->data[i] = pilha->data[i+1];
    }
    pilha->size--;
    return value;
}

int main(){
    pilha_sequencial pilha;
    create_stack(&pilha);

    if (is_empty(pilha)) {
        printf("Pilha vazia!\n");
    } else { 
      printf("Pilha cheia!\n"); 
      }

    printf("Tamanho da pilha: %d\n", size(pilha));

    insert_data(&pilha, 1, 20);
    insert_data(&pilha, 2, 92);
    insert_data(&pilha, 3, 3);
  
    printf("Pilha sequencial: %d %d %d\n", position_data(pilha, 1), 
            position_data(pilha, 2), position_data(pilha, 3));

    modify_data(&pilha, 2, 4);

    printf("Pilha sequencial: %d %d %d\n", position_data(pilha, 1), 
            position_data(pilha, 2), position_data(pilha, 3));

    removed_data(&pilha, 1);
    
    printf("Pilha sequencial: %d %d\n", position_data(pilha, 1), 
            position_data(pilha, 2));

    printf("Tamanho da pilha: %d\n", size(pilha));
  }
