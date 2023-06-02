#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_TAMANHO 101

void troca(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int particao(int array[], int baixo, int alto){
  int pivo = array[alto];
  int i = (baixo - 1);

  for (int j = baixo; j <= alto - 1; j++){
    if (array[j] < pivo){
      i++;
      troca(&array[i], &array[j]);
    }
  }

  troca(&array[i + 1], &array[alto]);
  return (i + 1);
}

void quick_sort(int array[], int baixo, int alto){
  if(baixo < alto){
    int pi = particao(array, baixo, alto);

    quick_sort(array, baixo, pi -1);
    quick_sort(array, pi + 1, alto);
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
  quick_sort(array, 0, num - 1);
  clock_t tempo_fim = clock(); 
  double tempo_execucao = (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
    
  printf("\nArray ordenado do quick_sort: \n");
  for (int i = 0; i < num; i++){
    printf("%d ", array[i]);
  }

  printf("\nTempo de execução: %.10f segundos.\n", tempo_execucao);
    
  return 0;
}