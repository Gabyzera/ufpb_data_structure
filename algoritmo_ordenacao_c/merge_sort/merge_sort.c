#include <stdio.h>

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