#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

int cria_lista_tam_n(Lista *l, int n, elem *elementos){
  l->inicio = l->fim = NULL; // Inicializando a lista
  No *novo; // Nó auxiliar

  // Criando lista com os n elementos dados pelo usuário
  novo = (No *) malloc(sizeof(No));
  if(novo == NULL)
    return 1;
  novo->info = elementos[0];
  l->inicio = novo;
  l->fim = novo;
  for (int i = 1 ; i < n ; i++){
    novo = (No *) malloc(sizeof(No));
    if(novo == NULL){
      apaga_lista(l);
      return 1;
    }
    novo->info = elementos[i];
    novo->proximo = NULL;
    l->fim->proximo = novo;
    l->fim = novo;
  }
  return 0;
}

int retira_lista_k_elemento(Lista *l, elem k, elem *x){
  No *aux, *anterior;
  anterior = NULL;
  aux = l->inicio;
  for(int i = 1 ; i <= k ; i++){
    if(aux == NULL)
      return 1;
    //retirar k-ésimo elemento
    if(i == k){
      if(aux == l->inicio){ // Retirar o primeiro elemento da lista
        *x = l->inicio->info;
        l->inicio = l->inicio->proximo;
        free(aux);
        return 0;
      }
      if(aux == l->fim){ // Retirar o último elemento da lista
        *x = l->fim->info;
        l->fim = anterior;
        l->fim->proximo = NULL;
        free(aux);
        return 0;
      }else{ // Retirar um elemento que está entre o fim e o inicio da lista
        *x = aux->info;
        anterior->proximo = aux->proximo;
        free(aux);
        return 0;
      }
    }
    anterior = aux;
    aux = aux->proximo;
  }
  // K-ésimo elemento não foi encontrado
  return 1;
}

void apaga_lista(Lista *l){
  No *aux;
  while(l->inicio != NULL){
    aux = l->inicio;
    l->inicio = l->inicio->proximo;
    free(aux);
  }
  l->fim = NULL;
  return;
}

void mostrar_lista(Lista l){
  printf("\n**********LISTA**********\n");
  while (l.inicio != NULL){
    printf("%d\t",l.inicio->info);
    l.inicio = l.inicio->proximo;
  }
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
    printf("%dº elemento retirado da lista: %d\n\n",k, x);
  }
  printf("\n\nLISTA FINAL DO PROCESSO:\n\n");
  mostrar_lista(*l);
  printf("\n\n\n");
  return;
}
