#include "casamento.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  /* Inicializando variáveis */
  Lista casamento;
  cria_lista(&casamento);
  int escolha,event;
  char nome[50],eventos[3];
  /* Começando o loop do menu de opções */
  do{
    printf("\n\n*******MENU**********\n\n");
    printf("Insira uma das opções abaixo:\n\n(1) Inserir Convidado\n(2) Mostrar Convidados\n");
    printf("(3) Mostrar Convidados de um dos Eventos\n(4) Sair\n\nOpção:\t");
    scanf(" %d",&escolha);
    switch (escolha) {
      case 1:
        printf("\n\nInsira o nome do convidado:\t");
        scanf(" %[^\n]s",nome );
        do{
          printf("%s está convidado para a recepção\? (S/N)\t", nome );
          scanf(" %c", &eventos[0] );
        }while(eventos[0] != 'S' && eventos[0] != 'N');
        do{
          printf("%s está convidado para a cerimônia\? (S/N)\t", nome );
          scanf(" %c",&eventos[1]);
        }while(eventos[1] != 'S' && eventos[1] != 'N');
        do{
          printf("%s está convidado para o banquete\? (S/N)\t", nome );
          scanf(" %c",&eventos[2]);
        }while(eventos[2] != 'S' && eventos[2] != 'N');
        insere_lista(&casamento,nome,eventos);
        break;
      case 2:
        mostrar_lista(&casamento);
        break;
      case 3:
        do{
          printf("Os convidados de qual evento serão exibidos\?\t(1) Recepção\t(2) Cerinônia\t(3) Banquete\n");
          scanf(" %d",&event );
        }while(event<0 && event>3);
        exibe_evento(&casamento, event-1);
        break;
    }
  }while(escolha != 4);

  /* Desaloca toda a memória usada na lista */
  apaga_lista(&casamento);
  return 0;
}
