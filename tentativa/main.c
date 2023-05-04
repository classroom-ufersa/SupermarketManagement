#include <stdio.h>
#include<locale.h>
#include"listadepartamento.c"

int main(void) {
  setlocale(LC_ALL,"Portuguese");
  int escolha = 0;
  char produto_buscado[50],tipo[50],validade[50],fabricacao[50],nome_departamento[50],estoque[50];
  char nome_produto_editar[50],nome_encontrar_departamento[50],nome_produto_removido[50];
  float preco;
  ListaDepartamento* lista_departamentos = ler_lista_departamentos();
 

  do{
    
    imprime_menu();
    printf("digite a opção que deseja: ");
    scanf("%d",&escolha);
    
    switch(escolha){
      case 1:

        printf("\n\ninserindo novo produto...\n");
        printf("digite o nome do produto: ");
        scanf(" %[^\n]",tipo);
        printf("digite o preço do produto: ");
        scanf("%f",&preco);
        printf("digite a data de validade do produto(DD/MM/AAAA): ");
        scanf(" %[^\n]",validade);
        printf("digite a data de fabricação do produto(DD/MM/AAAA): ");
        scanf(" %[^\n]",fabricacao);
        printf("digite a quantidade desse produto em estoque: ");
        scanf(" %[^\n]",estoque);
        printf("digite o nome do departamento em que esse produto vai estar: ");
        scanf(" %[^\n]",nome_departamento);
        insere_novo_produto(lista_departamentos,tipo,validade,fabricacao,estoque,nome_departamento,preco);
        lista_imprime_txt(lista_departamentos);

        break;
      case 2:
        printf("removendo produto...\n");
        printf("digite o nome do produto que deseja retirar: ");
        scanf(" %[^\n]",nome_produto_removido);
  
        break;
      case 3:

        printf("\nListando os departamentos:\n\n");
        //lista_imprime_txt(lista_departamentos);
        lista_departamento_imprime(lista_departamentos );
        
  
       break;
      case 4:

        printf("editando produto...\n");
        printf("digite o nome do produto que deseja editar: ");
        scanf(" %[^\n]",nome_produto_editar);

        break;
      case 5:

        printf("Buscando produto...\n");
        printf("digite o nome do produto que deseja buscar: ");
        scanf(" %[^\n]",produto_buscado);
        busca_produto(lista_departamentos,produto_buscado);

  
        break;
      case 6:
        printf("digite o nome do departamento que deseja listar os produtos disponiveis: ");
        scanf(" %[^\n]",nome_encontrar_departamento);
        lista_produtos_departamento(lista_departamentos,nome_encontrar_departamento);
        break;
      case 7:
          produtos_por_departamento(lista_departamentos);

        break;
      case 8:
        printf("\n|finalização do progama|\n");
        
        break;
      default:
        printf("\no numero digitado não está entre as opções\n\n");
        break;
    }
    
  }while(escolha!=8);
  libera_memoria(lista_departamentos);
  return 0;
}
