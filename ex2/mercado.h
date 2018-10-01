#ifndef MERCADO_H
  #define MERCADO_H
  typedef enum {Cadeirante = 0,Gestante = 1,Idoso = 2, Publico = 3} tipo;

  typedef struct cliente{
    char *nome;
    int itens;
    tipo status;
  }Cliente;

  typedef struct no{
    Cliente *consumidor;
    struct no *proximo;
  }No;

  typedef struct{
    No *inicio,*fim;
  }Fila;

  typedef struct{
    Fila caixa[4];
    /* caixa[0] - caixa preferencial: cadeirantes, gestantes, idosos
       caixa[1] - caixa geral
       caixa[2] - caixa até 10 itens
       caixa[3] - caixa até 5 itens*/
  }Mercado;

  void cria_fila(Fila *f);
  int insere_fila(Fila *f,Cliente *c);
  void apaga_fila(Fila *f);
  void cria_mercado(Mercado *m);
  int distribui_clientes(Mercado *m, Fila *f, int x);
  void apaga_mercado(Mercado *m);

#endif
