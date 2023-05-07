#include <stdio.h>
#include<locale.h>
#include"departamento.c"

int main(void) {
  setlocale(LC_ALL,"Portuguese");
  int escolha = 0;
  char produto_buscado[50],tipo[50],validade[50],fabricacao[50],nome_departamento[50],estoque[50];
  char nome_produto_editar[50],nome_encontrar_departamento[50],nome_produto_removido[50];
  float preco;
  Departamento* departamentos = ler_txt();
 

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
        insere_novo_produto(departamentos,tipo,validade,fabricacao,estoque,nome_departamento,preco);
        lista_imprime_txt(departamentos);

        break;
      case 2:
        printf("removendo produto...\n");
        printf("digite o nome do produto que deseja retirar: ");
        scanf(" %[^\n]",nome_produto_removido);
  
        break;
      case 3:

        printf("\nListando os departamentos:\n\n");
        //lista_imprime_txt(lista_departamentos);
        lista_departamento_imprime(departamentos );
        
  
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
        busca_produto(departamentos,produto_buscado);

  
        break;
      case 6:
        printf("digite o nome do departamento que deseja listar os produtos disponiveis: ");
        scanf(" %[^\n]",nome_encontrar_departamento);
       // lista_produtos_departamento(departamentos,nome_encontrar_departamento);
        break;
      case 7:
          produtos_por_departamento(departamentos);

        break;
      case 8:
        printf("\n|finalização do progama|\n");
        lista_imprime_txt(departamentos);
        break;
      default:
        printf("\no numero digitado não está entre as opções\n\n");
        break;
    }
    
  }while(escolha!=8);
//   libera_memoria(departamentos);
  return 0;
}




// #include<stdio.h>
// #include"departamento.c"

// int main(){
//     Departamento* departamento = ler_txt();

//         // insere_novo_produto(departamento,"arroz","10/10/2030","10/10/2029","5 disp","limpeza",4.0);
//         // lista_imprime_txt(departamento);
//         // busca_produto(departamento,"arroz");
//         // produtos_por_departamento(departamento);
//         // lista_departamento_imprime(departamento);
//     return 0;
// }