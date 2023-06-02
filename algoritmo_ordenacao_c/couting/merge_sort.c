#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_TAMANHO 101

void merge(int array[], int esquerda[], int tamanho_esquerda, int direita[], int tamanho_direita){
  int i = 0, j = 0, k = 0;
    
  while (i < tamanho_esquerda && j < tamanho_direita){
    if (esquerda[i] <= direita[j]){
      array[k] = esquerda[i];
      i++;
    } else{
      array[k] = direita[j];
      j++;
    }
    k++;
  }

  while (i < tamanho_esquerda){
    array[k] = esquerda[i];
    i++;
    k++;
  }

  while (j < tamanho_direita){
    array[k] = direita[j];
    j++;
    k++;
  }
}

void merge_sort(int array[], int num){
  if(num <= 1)
    return;

  int mid = num/2;
  int esquerda[mid];
  int direita[num - mid];

  for (int i = 0; i < mid; i++) {
    esquerda[i] = array[i];
  }

  for (int i = mid; i < num; i++) {
    direita[i - mid] = array[i];
  }

  merge_sort(esquerda, mid);
  merge_sort(direita, num - mid);

  merge(array, esquerda, mid, direita, num - mid);
}

int main(){
  int array[ARRAY_TAMANHO];
  int num = 0;

  FILE *file = fopen("couting.txt", "r");
  if (file == NULL){
    printf("Erro ao abrir o arquivo.");
  }

  int n;
  while (fscanf(file, "%d", &n) == 1 && num < ARRAY_TAMANHO){
    array[num] = n;
    num++;
  }

  fclose(file);

  clock_t tempo_inicio = clock(); 
  merge_sort(array, num);
  clock_t tempo_fim = clock(); 
  double tempo_execucao = (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
    
  printf("\nArray ordenado do merge_sort: \n");
  for (int i = 0; i < num; i++){
    printf("%d ", array[i]);
  }

  printf("\nTempo de execução: %.10f segundos.\n", tempo_execucao);
    
  return 0;
}