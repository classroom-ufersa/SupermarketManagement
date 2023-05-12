#include <stdio.h>
#include <locale.h>
#include <time.h>
#include "departamento.c"

#define N_caracteres 50

int main(void) {
  setlocale(LC_ALL,"Portuguese"); // comando para trabalhar com Portugês no código
  //variáveis para calcular o tempo de execução
  double tempo;
  clock_t inicio;
  clock_t fim;
  inicio = clock();
  //variáveis auxiliares
  int escolha = 0, estoque; 
  char produto_procurado[N_caracteres],tipo[N_caracteres],validade[N_caracteres],fabricacao[N_caracteres],nome_departamento[N_caracteres];
  char nome_produto_editar[N_caracteres],nome_encontrar_departamento[N_caracteres],nome_produto_removido[N_caracteres];
  float preco;
  Departamento* departamentos = ler_txt();  // lendo as informações dos arquivos
  Produto* produto_buscado; // guarda o produto que foi buscado pelo usuario
  

  do{
    
    imprime_menu();
    printf("digite a opção que deseja: ");
    escolha =  somente_numeros(); // para garantir que o usuário digite apenas números
    switch(escolha){
      case 1://inserir produto

        printf("\n\ninserindo novo produto...\n");
        printf("digite o nome do produto: ");
        scanf(" %[^\n]",tipo);
        minuscula(tipo);//para retirar os caracteres especiais e deixar o texto todo em minusculo
        printf("digite o preço do produto: ");
        scanf("%f",&preco);
        printf("digite a data de validade do produto(DD/MM/AAAA): ");
        scanf(" %[^\n]",validade);
        printf("digite a data de fabricação do produto(DD/MM/AAAA): ");
        scanf(" %[^\n]",fabricacao);
        printf("digite a quantidade desse produto em estoque: ");
        scanf("%d",&estoque);
        printf("digite o nome do departamento em que esse produto vai estar: ");
        scanf(" %[^\n]",nome_departamento);
        minuscula(nome_departamento);
        // if(verifica_departamento_existe(departamentos,nome_departamento) == 0){//verificando se o departamento digitado pertence no sistema
        //   produto_buscado = busca_produto(departamentos, tipo);
        // if(produto_buscado != NULL){ //verificando se o produto já existe no sistema
         insere_novo_produto(departamentos,tipo,validade,fabricacao,estoque,nome_departamento,preco);
        // }else{
        //   printf("\no produto %s já existe no sistema\n",tipo);
        // }
        // }else{
        //   printf("departamento não encontrado");
        // }
        

        break;
      case 2://remover produto
      
        printf("removendo produto...\n");
        printf("digite o nome do produto que deseja retirar: ");
        scanf(" %[^\n]",nome_produto_removido);
        minuscula(nome_produto_removido);
        remove_produto(departamentos,nome_produto_removido);
  
        break;
      case 3://listar produtos cadastrados

        printf("\nListando os departamentos:\n\n");
        lista_departamento_imprime(departamentos );
  
       break;
      case 4://editar produto

        printf("editando produto...\n");
        printf("digite o nome do produto que deseja editar: ");
        scanf(" %[^\n]",nome_produto_editar);
        minuscula(nome_produto_editar);
        editar_produto(departamentos, nome_produto_editar);
        break;
      case 5://buscar produto

        printf("Buscando produto...\n");
        printf("digite o nome do produto que deseja buscar: ");
        scanf(" %[^\n]",produto_procurado);
        minuscula(produto_procurado);
        produto_buscado = busca_produto(departamentos, produto_procurado);
        if(produto_buscado == NULL){//verifica se o produto que foi buscado existe
          printf("produto não encontrado");
        }else{
          printf("nome do departamento que se encontra o produto: %s\n",produto_buscado->nome_departamento);
          printf("preço do produto: %.2f\n",produto_buscado->preco);
          printf("data de fabricação do produto: %s\n",produto_buscado->fabricacao);
          printf("data de validade do produto: %s\n",produto_buscado->validade);
          printf("quantidade disponivel em estoque: %d\n\n",produto_buscado->estoque);
        }
  
        break;
      case 6://Consultar produtos disponíveis em um dado departamento

        printf("digite o nome do departamento que deseja verificar a quantidade de produtos disponiveis: ");
        scanf(" %[^\n]",nome_encontrar_departamento);
        minuscula(nome_encontrar_departamento);
        verifica_produtos_estoque(departamentos,nome_encontrar_departamento);

        break;
      case 7://Consultar quantitativo de produtos por departamento
          produtos_por_departamento(departamentos);

        break;
      case 8://sair

        printf("\n|finalização do progama|\n");
        imprime_txt(departamentos);

        break;
      default:

        printf("\no numero digitado não está entre as opções\n\n");

        break;
    }
    
  }while(escolha!=8);

  libera_memoria(departamentos); // libera a memoria alocada
  fim = clock();
  tempo = (double) (fim - inicio) / (CLOCKS_PER_SEC/1000);
  printf("tempo gasto na execução do codigo: %lf\n",tempo);

  return 0;
}

