#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  Lista l;
  elem n,k,*elementos;
  char confirma = 'N';
  do{
  printf("Quantos elementos inteiros a sua lista terá\?\t");
  scanf(" %d",&n );
}while(n<=1);
  elementos = (elem *) malloc(n * sizeof(elem));
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
  pato_pato_ganso(&l,n,k, elementos);
  free(elementos);
  apaga_lista(&l);
  return 0;
}
