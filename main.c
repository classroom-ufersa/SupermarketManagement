#include <stdio.h>
#include "lista.c"
#include <locale.h>

int main(void) {
  
  setlocale(LC_ALL,"Portuguese");
  int escolha = 0;
  LstDep* lista_departamentos = lstdep_cria();

  do{
    
    menu();
    printf("digite a opção que deseja: ");
    scanf("%d",&escolha);
    
    switch(escolha){
      case 1:
  
        break;
      case 2:
  
        break;
      case 3:
  
       break;
      case 4:
  
        break;
      case 5:
  
        break;
      case 6:
  
        break;
      case 7:
  
        break;
      case 8:
        printf("finalização do progama");
        break;
      default:
        printf("o numero digitado não está entre as opções,tente novamente: ");
        break;
    }
    
  }while(escolha!=8);

  return 0;
}