#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "insertion_sort.c"

void insertion_sort();

int main() {
  clock_t inicio, fim;
  double tempo_execucao;

  inicio = clock();
  const char *files[] = {
    "../instancias_numericas/couting.txt",
    "../instancias_numericas/num.1000.1.in",
    "../instancias_numericas/num.1000.2.in",
    "../instancias_numericas/num.1000.3.in",
    "../instancias_numericas/num.1000.4.in",
    "../instancias_numericas/num.10000.1.in",
    "../instancias_numericas/num.10000.2.in",
    "../instancias_numericas/num.10000.3.in",
    "../instancias_numericas/num.10000.4.in",
    "../instancias_numericas/num.100000.1.in",
    "../instancias_numericas/num.100000.2.in",
    "../instancias_numericas/num.100000.3.in",
    "../instancias_numericas/num.100000.4.in"
  };

  int num_files = sizeof(files) / sizeof(files[0]);

  printf("\nAlgoritmo de ordenação - Insertion Sort\n");

  for (int i = 0; i < num_files; i++){
    FILE *file = fopen(files[i], "r");
    if(file){
      printf("\nArray ordenado:\n");
      printf("%s\n", files[i]);

      int n;
      fscanf(file, "%d", &n);
      int *array = malloc(n * sizeof(int));

      for (int i = 0; i < n; i++){
        fscanf(file, "%d ", &array[i]);
      }

      fclose(file);

      insertion_sort(array, n);
      fim = clock();
      tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
      printf("Tempo de execução: %.5f segundos.\n", tempo_execucao);
      
    }else{
      printf("\nErro ao abrir o arquivo.");
    }
  }
}  