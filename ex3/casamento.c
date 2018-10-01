#include "casamento.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void cria_lista(Lista *l){
  l->inicio = l->fim = NULL; // Inicializando a lista
}

int insere_lista(Lista *l, char *nome, char *convites){
  // Alocando memória para o próximo convidado
  No *novo = (No *) malloc(sizeof(No));
  if(novo == NULL)
    return 1;
  novo->nome = (char*) malloc( (strlen(nome)+1) * sizeof(char));
  if(novo->nome == NULL)
    return 1;
  //Copiando informações
  strcpy(novo->nome, nome);
  for(int i=0;i<3;i++)
    novo->evento[i] = convites[i];
  novo->proximo = NULL;
  /* Alterando os ponteiros */
  if(l->inicio == NULL){
    l->inicio = l->fim = novo;
    return 0;
  }
  l->fim->proximo = novo;
  l->fim = novo;
  return 0;
}

void apaga_lista(Lista *l){
  No *aux;
  while(l->inicio != NULL){
    aux = l->inicio;
    l->inicio = l->inicio->proximo;
    free(aux->nome);
    free(aux);
  }
  l->fim = NULL;
  return;
}

void exibe_evento(Lista *l, int evento){
  No *aux;
  if(evento == 0)
    printf("\n**********RECEPÇÃO**********\n");
  if(evento == 1)
    printf("\n**********CERIMÔNIA**********\n");
  if(evento == 2)
    printf("\n**********BANQUETE**********\n");
  aux = l->inicio;
  while (aux != NULL){
    if(aux->evento[evento] == 'S')
      printf("%s\n",aux->nome);
    aux = aux->proximo;
  }
  printf("\n");
  return;
}

void mostrar_lista(Lista *l){
  No *aux;
  printf("\n**********LISTA DE CONVIDADOS**********\n");
  aux = l->inicio;
  while (aux != NULL){
    printf("%s\n",aux->nome);
    aux = aux->proximo;
  }
  printf("\n");
  return;
}
