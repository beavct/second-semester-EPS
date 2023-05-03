#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bibliotecaSorts.h"
int CMPS = 0;
int MOVS = 0;

palavras *lePalavras (int n) {
    int i, lixo;
    palavras *p = malloc (sizeof(palavras));
    p->palavra = calloc (n, sizeof(palavra) * n);

    for (i = 0; i < n; i++)
        lixo = scanf ("%s", p->palavra[i]);

    (void)lixo;

    return p;
}

void imprimePalavras(int n, palavras *p) {
    int i;

    for (i = 0; i < n; i++) {
        printf ("%s\n", p->palavra[i]);
    }
}

void troca (int i, int j, palavras *p) {
    char aux[10];
    int k;

    for (k = 0; k < 10; k++) 
        aux[k] = p->palavra[i][k];

    for (k = 0; k < 10; k++)
        p->palavra[i][k] = p->palavra[j][k];

    for (k = 0; k < 10; k++)
        p->palavra[j][k] = aux[k];
}

void insertionSort (palavras *p, int n) {
    int i, j, k=0, flag;
    char chave[10];

    for (i = 1; i < n; i++) {
        for (j = 0; j < strlen(p->palavra[i]); j++) 
            chave[j] = p->palavra[i][j];            
        
        j = i-1;
        flag=1;

        while (j >= 0 && flag) {
            while (p->palavra[j][k] == chave[k] && k < 10)
                k++;

            if (p->palavra[j][k] > chave[k]) {
                troca(j, j+1, p);   
                MOVS++;              
            }

            else
                flag = 0;
            j--; k = 0; CMPS++;
        }
    }
}

void limpa (palavras *p) {
    free(p->palavra);
    free(p);
}

int main () {
    int quant, lixo;
    palavras *palavras;
    clock_t tempo;

    lixo = scanf("%d", &quant);
    (void)lixo;
    palavras = lePalavras(quant);

    tempo= clock();
    insertionSort(palavras, quant);
    tempo = clock() - tempo;

    printf("tempo: %fs\n", ((float)tempo/CLOCKS_PER_SEC));
    printf("%d comparações\n%d movimentações\n\n", CMPS, MOVS);
    imprimePalavras(quant, palavras);

    limpa(palavras);

    return 0;
}