#include <stdio.h>

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