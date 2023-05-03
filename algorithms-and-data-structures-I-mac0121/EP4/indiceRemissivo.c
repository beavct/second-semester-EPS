#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabelaSimbolos.c"
#define MAX 256


/*Lê o texto de um arquivo e o salva em uma árvore binária atrávez de uma tabela de símbolos*/
int main(){
    FILE * entrada;
    FILE * saida; 
    char nomeArquivo[MAX];
    char linha[MAX], *aux;
    no * raiz = NULL;
    int index = 1;

    printf("Digite o nome do arquivo para a leitura do texto:\n");
    scanf("%s", nomeArquivo);

    entrada = fopen(nomeArquivo, "r");

    while(fgets(linha, MAX, entrada) != NULL){

        aux = strtok(linha, "1234567890!@#$%*&()-_=+´`~^,.\'\"?\n ");

        while (aux != NULL){
            raiz = insercao(raiz, aux, index);   
            aux = strtok(NULL, "1234567890!@#$%*&()-_=+´`~^,.\'\"?\n ");
        }
        index++;
    }
    fclose(entrada);

    saida = fopen("saida.txt", "w");
    inordem(raiz, saida);
    fclose(saida);

    liberarArv(raiz);

    return 0;
}
