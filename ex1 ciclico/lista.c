#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

int cria_lista_tam_n(Lista *l, int n, elem *elementos){
  l->inicio = NULL; // Inicializando a lista
  No *novo,*anterior; // Nós auxiliar

  // Criando lista circular com os n elementos dados pelo usuário
  novo = (No *) malloc(sizeof(No));
  if(novo == NULL)
    return 1;
  novo->info = elementos[0];
  l->inicio = novo;
  l->inicio->proximo = l->inicio;
  l->inicio_iteracao = l->inicio;
  anterior = l->inicio;
  for (int i = 1 ; i < n ; i++){
    novo = (No *) malloc(sizeof(No));
    if(novo == NULL){
      apaga_lista(l);
      return 1;
    }
    novo->info = elementos[i];
    novo->proximo = l->inicio;
    anterior->proximo = novo;
    anterior = novo;
  }
  return 0;
}

int retira_lista_k_elemento(Lista *l, elem k, elem *x){
  No *aux, *anterior;
  anterior = NULL;
  aux = l->inicio_iteracao;
  for(int i = 1 ; i <= k ; i++){
    if(aux->proximo == aux )// Somente sobrou um elemento
      return 1;
    //retirar k-ésimo elemento
    if(i == k){
      if(aux == l->inicio)
        l->inicio = aux->proximo;
      *x = aux->info;
      anterior->proximo = aux->proximo;
      l->inicio_iteracao = aux->proximo;
      free(aux);
      return 0;
      }
    // Andar na lista
    anterior = aux;
    aux = aux->proximo;
  }
  // K-ésimo elemento não foi encontrado
  return 1;
}

void apaga_lista(Lista *l){
  No *aux,*beginning;
  beginning = l->inicio;
  do{
    aux = l->inicio;
    l->inicio = l->inicio->proximo;
    free(aux);
  }while(l->inicio != beginning);
  return;
}

void mostrar_lista(Lista l){
  No *aux;
  aux = l.inicio;
  printf("\n**********LISTA**********\n");
  do{
    printf("%d\t",l.inicio->info);
    l.inicio = l.inicio->proximo;
  }while (l.inicio != aux);
  printf("\n");
  return;
}

void pato_pato_ganso(Lista *l, elem n, elem k, elem *elementos){
  elem x;
  if(cria_lista_tam_n(l,n,elementos)){
    printf("Ocorreu um erro ao alocar espaço para a lista com %d elementos!!\n", n);
    return;
  }
  mostrar_lista(*l);
  while(!retira_lista_k_elemento(l,k,&x)){
    mostrar_lista(*l);
    printf("Elemento retirado: %d\n\n", x);
  }
  printf("\n\nLISTA FINAL DO PROCESSO:\n\n");
  mostrar_lista(*l);
  printf("\n\n\n");
  return;
}
