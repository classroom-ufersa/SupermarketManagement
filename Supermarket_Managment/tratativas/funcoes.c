#include <stdio.h>
#include <string.h>
#include <ctype.h>

int somente_numeros(){
    int valor, retorno = -1;
    char letra;
    do{
        printf("Digite um valor: ");
        retorno = scanf("%d", &valor);
        do{
          letra = getchar();
        }while(letra != '\n');
    }while(retorno == 0);
    return valor;
}

void minuscula(char* nome){
    int i = 0;
    char aux[50];
    strcpy(aux,nome);
    while(aux[i] != '\0'){
      aux[i] = tolower(aux[i]);
      i++;
    }
    strcpy(nome,aux);
}

void remover_especiais(char *nome_verificar) {
  int cont_original = 0, cont_nova = 0;
  char aux[50];
  
  // loop para percorrer toda a string
  while (nome_verificar[cont_original] != '\0') {
    if (isalpha(nome_verificar[cont_original])) {
      // Salvando na string auxiliar os valores que são somente caracteres 
      aux[cont_nova] = nome_verificar[cont_original];
      cont_nova++;
    }
    cont_original++;
  }
  strcpy(nome_verificar,aux);
}
