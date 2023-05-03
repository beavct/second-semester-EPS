#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bibliotecaSorts.h"
int CMPS = 0;
int MOVS = 0;

void imprimePalavras(int n, palavras *p) {
    int i;

    for (i = 0; i < n; i++) {
        printf ("%s\n", p->palavra[i]);
    }
}

void limpa (palavras *p) {
    free(p->palavra);
    free(p);
}

palavras *lePalavras (int n) {
    int i, lixo;
    palavras *p = malloc (sizeof(palavras));
    p->palavra = calloc (n, sizeof(palavra) * n);
    
    for (i = 0; i < n; i++) 
        lixo = scanf ("%s", p->palavra[i]);
    (void)lixo;
    return p;
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

int particiona (palavras *p, int ini, int fim) {
    int i, j, k;
    char chave[10];

    for (i = 0; i < strlen(p->palavra[ini]); i++) 
        chave[i] = p->palavra[ini][i];

    i = ini+1;
    j = fim;
    k = 0;

    while (1){

        while (i != fim) {
            while (p->palavra[i][k] == chave[k] && k < 10)
                k++;
            if(p->palavra[i][k] < chave[k])
                i++;
            else 
                break;
            k=0; CMPS++;
        }

        while (j != ini) {
            while (p->palavra[j][k] == chave[k] && k < 10) 
                k++;
            if (p->palavra[j][k] > chave[k])
                j--;
            else 
                break;
            k=0; CMPS++;
        }
    
        if (i >= j) {
            break;
        }
        troca(i, j, p);
        MOVS++;
    }
    troca(ini, j, p);
    MOVS++;

    return j;
}

void quickSort (palavras *p, int ini, int fim) {
    int x;

    if (ini < fim){
        x = particiona(p, ini, fim);
        quickSort(p, ini, x - 1);
        quickSort(p, x + 1, fim);
    }
}

int main () {
    int quant, lixo;
    palavras *palavras;
    clock_t tempo;

    lixo = scanf("%d", &quant);
    (void)lixo;
    palavras = lePalavras(quant);

    tempo= clock();
    quickSort(palavras, 0, quant-1);
    tempo = clock() - tempo;

    printf("tempo: %fs\n", ((float)tempo/CLOCKS_PER_SEC));
    printf("%d comparações\n%d movimentações\n\n", CMPS, MOVS); 
    /*imprimePalavras(quant, palavras);*/

    return 0;
}




