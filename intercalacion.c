#include <stdio.h>
#include <string.h>
#include "tokens.h"

int main (int argc, char *argv[])
{
  if (argc != 3) {
    printf("Ingrese los archivos: ./intercalacion <archivo1> <archivo2>\n");
    return 1;
  }

  char archivo1[50], archivo2[50];
  strcpy(archivo1, argv[1]);
  strcpy(archivo2, argv[2]);

  FILE *c = fopen("salida.txt", "w");

  int n1, n2;
  char *buffer = leer(archivo1);
  n1 = getTokens(buffer);
  int nums1[n1];
  generar_tokens(nums1, buffer);

  buffer = leer(archivo2);
  n2 = getTokens(buffer);
  int nums2[n2];
  generar_tokens(nums2, buffer);

  int i = 0, j = 0;
  while (i < n1 || j < n2) {
    if (nums1[i] <= nums2[j]) {
      fprintf(c, "%d ", nums1[i]);
      i++;
    } else if (nums1[i] >= nums2[j]) {
      fprintf(c , "%d ", nums2[j]);
      j++;
    }
  }
  fprintf(c, "\n");
  fclose(c);
  return 0;
}
