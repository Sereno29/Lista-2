#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  /* Criando variáveis para testar o programa */
  Lista l;
  elem n,k,*elementos;
  char confirma = 'N';
  /* Perguntando ao usuário quantos elementos a lista irá ter */
  do{
    printf("Quantos elementos inteiros a sua lista terá\?\t");
    scanf(" %d",&n );
  }while(n<=1);
  /* Alocando espaço para o tamanho pedido pelo usuário */
  elementos = (elem *) malloc(n * sizeof(elem));
  /* Adquirindo do usuário a lista que ele quer inserir*/
  while(confirma == 'N'){
    for(int i = 0 ; i<n ; i++){
      printf("Insira o %dº elemento inteiro da lista de um total de %d:\t",i+1,n );
      scanf(" %d", &elementos[i]);
    }
    printf("-> Lista a ser criada: \n");
    for(int i = 0 ; i<n ; i++){
      printf("%d \t",elementos[i] );
    }
    printf("\nEsta é a lista que você gostaria de criar\? (S/N)\t");
    do{
      scanf(" %c", &confirma);
    }while(confirma != 'S' && confirma != 'N' );
  }
  do{
    printf("Qual será o parâmetro k (k>=1)\?\t");
    scanf(" %d",&k );
  }while(k<1);
  /* Chamada para o processo iterativo */
  pato_pato_ganso(&l,n,k, elementos);
  /* Desalocando toda a memória do programa */
  free(elementos);
  apaga_lista(&l);
  return 0;
}
