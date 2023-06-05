#include <stdio.h>

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