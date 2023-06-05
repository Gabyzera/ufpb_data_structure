#include <stdio.h>

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