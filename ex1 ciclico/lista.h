#ifndef LISTA_H
  #define LISTA_H
  typedef int elem;

  typedef struct no {
    elem info;
    struct no *proximo;
  }No;

/* A lista tem dois ponteiros, pois um deles é para o inicio e o outro é para
   indicar onde a iteração de retirada de elementos deve começar no próximo
  passo. */
  typedef struct{
    No *inicio,*inicio_iteracao;
  }Lista;

  void apaga_lista(Lista *l);
  void pato_pato_ganso(Lista *l, elem n, elem k, elem *elementos);
#endif
