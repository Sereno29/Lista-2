#ifndef CASAMENTO_H
  #define CASAMENTO_H

  typedef struct no {
    char *nome;
    char evento[3];
    /*  evento[0]: Lista de Convidados da Recepção
        evento[1]: Lista de Convidados da Cerimônia
        evento[2]: Lista de Convidados do Banquete
        'S': se a pessoa foi convidada para aquele evento
        'N': se a pessoa não foi convidada para aquele evento
    */
    struct no *proximo;
  }No;

  typedef struct{
    No *inicio, *fim;
  }Lista;

  void cria_lista(Lista *l);
  int insere_lista(Lista *l, char *nome, char *convites);
  void mostrar_lista(Lista *l);
  void exibe_evento(Lista *l, int evento);
  void apaga_lista(Lista *l);

#endif
