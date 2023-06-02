#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_TAMANHO 101

void insertion_sort(int array[], int num){
  int i, j, key;
    
  for (i = 1; i < num; i++){
    key = array[i];
    j = i -1;

    while (j >= 0 && array[j] > key){
      array[j+1] = array[j];
      j = j -1;
    }

    array[j + 1] = key;
  }
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
  insertion_sort(array, num);
  clock_t tempo_fim = clock(); 
  double tempo_execucao = (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
    
  printf("\nArray ordenado do insertion_sort: \n");
  for (int i = 0; i < num; i++){
    printf("%d ", array[i]);
  }

  printf("\nTempo de execução: %.10f segundos.\n", tempo_execucao);
    
  return 0;
}