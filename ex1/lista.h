#ifndef LISTA_H
  #define LISTA_H
  typedef int elem;

  typedef struct no {
    elem info;
    struct no *proximo;
  }No;

  typedef struct{
    No *inicio, *fim;
  }Lista;

  void apaga_lista(Lista *l);
  void pato_pato_ganso(Lista *l, elem n, elem k, elem *elementos);
#endif
