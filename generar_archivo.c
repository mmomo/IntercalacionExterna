#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int comparar (const void *a, const void *b)
{
  return (*(int*)a - *(int*)b);
}

int main (int argc, char *argv[])
{
  if (argc != 3) {
    printf("Ingrese el numero de elementos y el nombre del archivo a crear:\n./generar_archivos <n> <nombre_archivo>\n");
    return 1;
  }

  // Obtener numero de elementos, convertir argv[1] a entero
  int n;
  sscanf(argv[1], "%d", &n);
  // Obtener nombre del archivo argv[2]
  char archivo[50];
  strcpy(archivo, argv[2]);

  // arreglo donde se guardan los elementos generados
  int nums[n];

  FILE *salida;
  salida = fopen(archivo, "w");
  // semilla aleatoria
  srand(time(NULL));

  // guardar numeros aleatorios en el arreglo
  int i;
  for (i = 0; i < n; i++) {
    nums[i] = rand() % 100;
  }

  // ordenar arreglo de menor a mayor
  qsort(nums, n, sizeof(int), comparar);

  // guardar arreglo en archivo
  for (i = 0; i < n; i++) {
    if (i == n-1) {
      fprintf(salida, "%d", nums[i]);
    } else {
      fprintf(salida, "%d,", nums[i]);
    }
  }
  
  fclose(salida);
  return 0;
}
