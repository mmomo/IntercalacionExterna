#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tokens.h"

/*
 * Devuelve el numero de tokens que se generan en el string.
 */
int getTokens(char *buff)
{
  const char s[2] = ",";
  char *token;
  int i = 0;

  char *tmp;
  tmp = malloc(sizeof(int) * strlen(buff));
  strcpy(tmp, buff);
  
  token = strtok(tmp, s);
  while (token != NULL) {
    i++;
    token = strtok(NULL, s);
  }
  return i;
}

/*
 * Toma un string buff, genera sus tokens y los guarda en un arreglo de ints
 */
int generar_tokens(int nums[], char *buff)
{
  const char s[2] = ",";
  char *token;
  int i = 0;
  char *tmp;
  int tmp2;
  
  tmp = malloc (sizeof(int) * strlen(buff));
  strcpy(tmp, buff);

  token = strtok(tmp, s);
  while (token != NULL) {
    sscanf(token, "%d", &tmp2);
    nums[i] = tmp2;
    i++;
    token = strtok(NULL, s);
  }
}

/*
 * Lee un archivo y guarda su contenido en un string. Devuelve el string generado.
 */
char *leer(FILE *f, char *archivo)
{
  char *buff = malloc(sizeof(char) * 2000);

  f = fopen(archivo, "r");
  fscanf(f, "%[^\n]%*c", buff);

  fclose(f);
  return buff;
}
