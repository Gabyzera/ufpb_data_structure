#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_TAMANHO 101

void bubble_sort(int array[], int num){
  int i, j, temp;

  for (i = 0; i < num - 1; i++){
    for (j = 0; j < num-i-1; j++){
      if (array[j] > array[j+1]){
        temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }
}

int main(){
  int array[ARRAY_TAMANHO];
  int num = 0;

  FILE *file = fopen("couting.txt", "r");
  if (file == NULL){
    printf("Erro ao abrir o arquivo.");
    return 1;
  }

  int n;
  while (fscanf(file, "%d", &n) == 1 && num < ARRAY_TAMANHO){
    array[num] = n;
    num++;
  }

  fclose(file);

  clock_t tempo_incio = clock();
  bubble_sort(array, num);
  clock_t tempo_fim = clock();
  double tempo_execucao = (double)(tempo_fim - tempo_incio) / CLOCKS_PER_SEC;

  printf("\nArray ordenado do bubble_sort: \n");
  for (int i = 0; i < num; i++){
    printf("%d ", array[i]);
  }

  printf("\nTempo de execução: %.10f segundos.\n", tempo_execucao);

  return 0;
}