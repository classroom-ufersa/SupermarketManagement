#include <stdio.h>
#include<locale.h>
#include"listadepartamento.c"

int main(void) {
  setlocale(LC_ALL,"Portuguese");
  int escolha = 0;
  char produto_buscado[50],tipo[50],validade[50],fabricacao[50],estoque[50],nome_departamento[50];
  float preco;
  ListaDepartamento* lista_departamentos = lst_ler();
 

  do{
    
    menu();
    printf("digite a opção que deseja: ");
    scanf("%d",&escolha);
    
    switch(escolha){
      case 1:
        printf("inserindo novo produto...");
        printf("digite o nome do produto");
        scanf(" %[^\n]",tipo);
        printf("digite a validade(DD/MM/AAA): ");
        scanf(" %[^\n]");
        break;
      case 2:
  
        break;
      case 3:
        printf("\nListando os departamentos:\n\n");
        lst_imprime(lista_departamentos );
        
  
       break;
      case 4:
  
        break;
      case 5:
        // printf("Buscando produto...\n");
        // printf("digite o nome do produto que deseja buscar: ");
        //scanf(" %[^\n]",produto_buscado);
        // printf("aaaaaa\n");
       busca_produto(lista_departamentos, "papel");

  
        break;
      case 6:
  
        break;
      case 7:
  
        break;
      case 8:
        
        printf("\n|finalização do progama|\n");
        

        
        break;
      default:
        printf("\no numero digitado não está entre as opções\n\n");
        break;
    }
    
  }while(escolha!=8);

  return 0;
}
