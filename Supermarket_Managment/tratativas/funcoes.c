#include <stdio.h>
#include <string.h>
#include <ctype.h>

int somente_numeros(){
    int valor, retorno = -1;
    char letra;
    int verifica = 0;
    do{
       if(verifica != 0){
        printf("Por favor, digite apenas numeros: ");
       }
        retorno = scanf("%d", &valor);
        do{
          letra = getchar();
        }while(letra != '\n');
        verifica++;
    }while(retorno == 0);
    return valor;
}

float somente_numeros_preco(){ // lembrar de colocar ela no codigo
    int retorno = -1;
    float valor;
    char letra;
    int verifica = 0;
    do{
       if(verifica != 0){
        printf("Por favor, digite apenas numeros: ");
       }
        retorno = scanf("%f", &valor);
        do{
          letra = getchar();
        }while(letra != '\n');
        verifica++;
    }while(retorno == 0);
    return valor;
}

void remover_especiais(char *nome_verificar) {
  int cont_original = 0, cont_nova = 0;
  char aux[50];
  // loop para percorrer toda a string
  while (nome_verificar[cont_original] != '\0') {
    if (isalpha(nome_verificar[cont_original] )) {
      // Salvando na string auxiliar os valores que são somente caracteres 
      aux[cont_nova] = nome_verificar[cont_original];
      cont_nova++;
    }else if(isspace(nome_verificar[cont_original])){
      aux[cont_nova] = nome_verificar[cont_original];
      cont_nova++;
    }
    cont_original++;
  }
  aux[cont_nova] = '\0';
  strcpy(nome_verificar,aux);
}

void minuscula(char* nome){
    int i = 0;
    char aux[50];
    strcpy(aux,nome);
    while(aux[i] != '\0'){
      aux[i] = tolower(aux[i]);
      i++;
    }
    remover_especiais(aux);
    strcpy(nome,aux);
}

