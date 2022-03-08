/*Trabalho Final da disciplina de Programação de Computadores - feito por Pedro Henrique Lima de Mesquita*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "locale.h"
#include "time.h"
#include "lib.h"

int main(void)
{
  ini = cria();
  int selecao = 0;
  for (;;)
  {
    menu();
    scanf("%d", &selecao);
    switch (selecao)
    {
    case 1:
      play();
      break;
    case 2:
      ajuda();
      break;
    case 3:
      imprime(ini);
      break;
    case 4:
      score();
    case 5:
      gravar(ini);
      break;
    case 6:
      zerarSSD();
      break;
    case 7:
      free(ini);
      ini = cria();
      break;
    case 8:
      exit(0);
    }
  }
  return 0;
}