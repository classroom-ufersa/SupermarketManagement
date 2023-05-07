#include<stdio.h>
#include"departamento.c"

int main(){
    Departamento* departamento = ler_txt();
    lista_departamento_imprime(departamento);
    return 0;
}