#include "mercado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
  /* Inicializando variáveis. Fila única, Mercado e Clientes */
  Mercado super;
  Fila unica;
  cria_mercado(&super);
  cria_fila(&unica);
  Cliente pagante;
  pagante.nome = (char *) malloc(50*sizeof(char));
  int x = 0;
  /* Inserindo primeiro cliente */
  strcpy(pagante.nome,"Mario Cortela");
  pagante.itens = 38;
  pagante.status = 3;
  insere_fila(&unica,&pagante);
  x++;

  /* Inserindo segundo cliente */
  strcpy(pagante.nome,"Pelé");
  pagante.itens = 5;
  pagante.status = 2;
  insere_fila(&unica,&pagante);
  x++;

  /* Inserindo terceiro cliente */
  strcpy(pagante.nome,"Bartosz Kurek");
  pagante.itens = 99;
  pagante.status = 3;
  insere_fila(&unica,&pagante);
  x++;

  /* Inserindo quarto cliente */
  strcpy(pagante.nome,"Garry Kasparov");
  pagante.itens = 8;
  pagante.status = 3;
  insere_fila(&unica,&pagante);
  x++;

  /* Inserindo quinto cliente */
  strcpy(pagante.nome,"Gisele Bundchen");
  pagante.itens = 29;
  pagante.status = 1;
  insere_fila(&unica,&pagante);
  x++;

  /* Inserindo sexto cliente */
  strcpy(pagante.nome,"Bill Gates");
  pagante.itens = 18;
  pagante.status = 3;
  insere_fila(&unica,&pagante);
  x++;

  /* Inserindo sétimo cliente */
  strcpy(pagante.nome,"Stephen Hawking");
  pagante.itens = 1;
  pagante.status = 0;
  insere_fila(&unica,&pagante);
  x++;

  // Entregando fila única a procedimento que irá dividir os clientes nas filas
  // do supermercado. Além de entregar a fila, também entregar variável x que
  // indica quantos clientes estão na fila única.
  if(distribui_clientes(&super, &unica, x))
    printf("Ocorreu um erro\n");

  // Desalocando toda a memória utilizada no programa
  free(pagante.nome);
  apaga_fila(&unica);
  apaga_mercado(&super);
  return 0;
}
