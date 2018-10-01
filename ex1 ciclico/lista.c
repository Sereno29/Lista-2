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
  /* Copiando informação para o primeiro elemento da lista e encadeando-o como
     um vetor circular*/
  novo->info = elementos[0];
  l->inicio = novo;
  l->inicio->proximo = l->inicio;
  l->inicio_iteracao = l->inicio;
  /* Armazenando os outros n-1 elementos da lista */
  anterior = l->inicio;
  for (int i = 1 ; i < n ; i++){
    novo = (No *) malloc(sizeof(No));
    if(novo == NULL){
      apaga_lista(l);
      return 1;
    }
    /* Encadeando novos ponteiros */
    novo->info = elementos[i];
    novo->proximo = l->inicio;
    anterior->proximo = novo;
    anterior = novo;
  }
  return 0;
}

/* Processo iterativo de retirar um elemento a cada k elementos até restar um na
   lista circular*/
int retira_lista_k_elemento(Lista *l, elem k, elem *x){
  /* Variáveis auxiliares */
  No *aux, *anterior;
  /* Repetição para encontrar o k-ésimo elemento */
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

/* Desaloca todos os nós da lista */
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

/* Exibe todos os elementos da lista */
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

/* Procedimento iterativo que retira o k-ésimo elemento da lista circular até
   restar somente 1*/
void pato_pato_ganso(Lista *l, elem n, elem k, elem *elementos){
  elem x;
  /* Inicializa a lista */
  if(cria_lista_tam_n(l,n,elementos)){
    printf("Ocorreu um erro ao alocar espaço para a lista com %d elementos!!\n", n);
    return;
  }
  mostrar_lista(*l);
  /* Retira elementos da lista até sobrar 1 */
  while(!retira_lista_k_elemento(l,k,&x)){
    mostrar_lista(*l);
    printf("Elemento retirado: %d\n\n", x);
  }
  /* Exibe a lista final */
  printf("\n\nLISTA FINAL DO PROCESSO:\n\n");
  mostrar_lista(*l);
  printf("\n\n\n");
  return;
}
