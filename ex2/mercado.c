#include "mercado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicializa os ponteiros da fila
void cria_fila(Fila *f){
  f->inicio = f->fim = NULL;
  return;
}

/* Inserção Fila: retira sempre ao final da fila */
int insere_fila(Fila *f,Cliente *c){
  // Alocando espeço para as novas variáveis
  Cliente *aux;
  No *novo;
  novo = (No *) malloc(sizeof(No));
  if (novo == NULL)
    return 1;
  aux = (Cliente *) malloc(sizeof(Cliente));
  if (aux == NULL)
    return 1;
  aux->nome = (char *) malloc( (strlen(c->nome)+1) * sizeof(char));
  if (aux->nome == NULL)
    return 1;
  // Transferindo dados para o novo nó
  strcpy(aux->nome,c->nome);
  aux->itens = c->itens;
  aux->status = c->status; // Atribuindo enumerações
  novo->consumidor = aux;
  novo->proximo = NULL;

  // Reorganizando ponteiros
  if(f->inicio == NULL){
    f->inicio = f->fim = novo;
    return 0;
  }
  f->fim->proximo = novo;
  f->fim = novo;
  return 0;
}

/* Retira Fila: retira no início da fila */
int retira_fila(Fila *f, Cliente *c){
  // Nó auxiliar
  No *aux;
  // Checa se a fila está vazia
  if(f->inicio == NULL)
    return 1;
  // Transfere dados para a variável c e desaloca o espaço do nó
  strcpy(c->nome,f->inicio->consumidor->nome);
  c->itens = f->inicio->consumidor->itens;
  c->status = f->inicio->consumidor->status;
  // Redefinição de ponteiros e desalocação de memória
  aux = f->inicio;
  f->inicio = f->inicio->proximo;
  free(aux->consumidor->nome);
  free(aux->consumidor);
  free(aux);
  return 0;
}

/* Desaloca a memória utilizada em uma fila */
void apaga_fila(Fila *f){
  No *aux;
  if(f->inicio == NULL)
    return;
  while(f->inicio != NULL){
    aux = f->inicio;
    f->inicio = f->inicio->proximo;
    free(aux->consumidor->nome);
    free(aux->consumidor);
    free(aux);
  }
  return;
}

/* Incializa os ponteiros das filas dos caixas do mercado */
void cria_mercado(Mercado *m){
  for(int i = 0; i<4 ; i++){
    cria_fila(&m->caixa[i]);
  }
  return;
}

/* Transforma o status do consumidor em uma string a ser printada */
void avalia_status(char* status,int i){
  switch (i) {
    case 0:
      strcpy(status,"Cadeirante");
      break;
    case 1:
      strcpy(status,"Gestante");
      break;
    case 2:
      strcpy(status,"Idoso");
      break;
    case 3:
      strcpy(status,"Publico Geral");
      break;
  }
  return;
}

// Imprime a fila dada como entrada. A fila é passada pro valor a fim de mudar
//os ponteiros na cópia e não no original
void mostrar_fila(Fila f){
  if (f.inicio == NULL){
    printf("\t\tFila vazia\n");
    return;
  }
  char status[20];
  while(f.inicio != NULL){
    avalia_status(status,f.inicio->consumidor->status);
    printf("\t\t%s\tItens: %d\tStatus: %s\n",f.inicio->consumidor->nome,f.inicio->consumidor->itens,status );
    f.inicio = f.inicio->proximo;
  }
  return;
}

/* Imprime as filas do mercado */
void mostrar_mercado(Mercado *m){
  printf("MERCADO\n");
  printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
  printf("\n");
  printf("->Fila 1: Cadeirantes, Gestantes, Idosos\n");
  mostrar_fila(m->caixa[0]);
  printf("\n");
  printf("->Fila 2: Caixa Geral\n");
  mostrar_fila(m->caixa[1]);
  printf("\n");
  printf("->Fila 3: Caixa de até 10 itens\n");
  mostrar_fila(m->caixa[2]);
  printf("\n");
  printf("->Fila 4: Caixa de até 5 itens\n");
  mostrar_fila(m->caixa[3]);
  printf("\n");
  printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
}

/* Conta o número de pessoas em uma fila. Outro jeito de saber isso, seria colocar
   um atributo em cada fila que mostrasse quantas pessoas estão na fila. Para
   filas maiores isso seria mais eficiente. Como este é um exemplo simples pre-
   feri exercitar minha navegação pela fila. */
int numero_fila(Fila *f){
  No *aux;
  int x = 0;
  aux = f->inicio;
  while(aux != NULL){
    aux = aux->proximo;
    x++;
  }
  return x;
}

/* Decide qual é a melhor fila que o pagante deve ir dependendo de seu status e
   quantidade de itens a serem comprados*/
int melhor_fila(int status, int itens,Mercado *m){
  No *aux;
  int fila[4], menor,j;
  switch (status) {
    default:
      if(itens<6){
        fila[0] = numero_fila(&m->caixa[0]);
        fila[1] = numero_fila(&m->caixa[1]);
        fila[2] = numero_fila(&m->caixa[2]);
        fila[3] = numero_fila(&m->caixa[3]);

        menor = fila[0];
        j = 0;
        for(int i =1 ;i<4; i++){
          if(menor>fila[i]){
            menor = fila[i];
            j = i;
          }
        }
        return j;
      }else{
        if(itens<11){
          fila[0] = numero_fila(&m->caixa[0]);
          fila[1] = numero_fila(&m->caixa[1]);
          fila[2] = numero_fila(&m->caixa[2]);

          menor = fila[0];
          j = 0;
          for(int i =1 ;i<3; i++){
            if(menor>fila[i]){
              menor = fila[i];
              j = i;
            }
          }
          return j;
        }else{
          fila[0] = numero_fila(&m->caixa[0]);
          fila[1] = numero_fila(&m->caixa[1]);

          menor = fila[0];
          j = 0;
          for(int i =1 ;i<2; i++){
            if(menor>fila[i]){
              menor = fila[i];
              j = i;
            }
          }
          return j;
        }
      }
    case 3:
      if(itens<6){
        fila[1] = numero_fila(&m->caixa[1]);
        fila[2] = numero_fila(&m->caixa[2]);
        fila[3] = numero_fila(&m->caixa[3]);

        menor = fila[1];
        j = 1;
        for(int i =2 ;i<4; i++){
          if(menor>fila[i]){
            menor = fila[i];
            j = i;
          }
        }
        return j;
      }else{
          fila[1] = numero_fila(&m->caixa[1]);
          fila[2] = numero_fila(&m->caixa[2]);

          menor = fila[1];
          j = 1;
          for(int i =2 ;i<3; i++){
            if(menor>fila[i]){
              menor = fila[i];
              j = i;
            }
          }
          return j;
        }

  }

}

/* Avalia em qual fila o consumidor deve entrar */
int avalia_cliente(Cliente *c, Mercado *m){
  if(c->status == 0 || c->status == 1 || c->status == 2 )
      return melhor_fila(c->status,c->itens, m);
  if(c->itens <= 10)
      return melhor_fila(c->status,c->itens, m);
  return 1;
}

/* Processo iterativo que esvazia a fila única dada de acordo com o número x de
   clientes nela. */
int distribui_clientes(Mercado *m, Fila *f, int x){
  // Variável auxiliar para receber os clientes da fila única de entrada e
  // tranferí-los para os seus respectivos caixas
  Cliente c;
  c.nome = (char *)malloc(50*sizeof(char));
  if(c.nome == NULL){
    free(c.nome);
    return 1;
  }
  int fila;
  printf("FILA ÚNICA\n");
  mostrar_fila(*f);
  printf("\n");
  mostrar_mercado(m);
  printf("\n\n");
  printf("\n\nCOMEÇANDO A TRANSFRÊNCIA DE CADA PAGANTE PARA SEU RESPECTIVO CAIXA:\n\n\n");
  // Separando os x clientes na fila única para os seus respectivos caixas
  for(int i = 0 ; i<x ; i++){
    if(retira_fila(f,&c)){
      free(c.nome);
      return 1;
    }
    fila = avalia_cliente(&c, m);
    insere_fila(&m->caixa[fila],&c);
    printf("FILA ÚNICA: %s SAIU PARA O CAIXA %d \n\n",c.nome,fila+1);
    mostrar_fila(*f);
    printf("\n\n");
    mostrar_mercado(m);
    printf("\n\n");
  }
  free(c.nome);
  return 0;
}

/* Desaloca a memória utilizada pelas filas do mercado */
void apaga_mercado(Mercado *m){
  for(int i = 0; i<4 ; i++){
    apaga_fila(&m->caixa[i]);
  }
  return;
}
