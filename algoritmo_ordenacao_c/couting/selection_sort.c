#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_TAMANHO 101

void selection_sort(int array[], int num){
  int i, j, min_indice, temp;
    
  for (i = 0; i < num - 1; i++){
    min_indice = i;
    for (j = i+1; j < num; j++){
      if (array[j] < array[min_indice]){
        min_indice = j;
      }
    }

    temp = array[min_indice];
    array[min_indice] = array[i];
    array[i] = temp;
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
  selection_sort(array, num);
  clock_t tempo_fim = clock(); 
  double tempo_execucao = (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
    
  printf("\nArray ordenado do selection_sort: \n");
  for (int i = 0; i < num; i++){
    printf("%d ", array[i]);
  }

  printf("\nTempo de execução: %.10f segundos.\n", tempo_execucao);
    
  return 0;
}