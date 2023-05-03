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

void igualaPalavra (palavras *a, int i, palavras* b, int j) {
    int k;

    for (k = 0; k < 10; k++) {
        a->palavra[i][k] = b->palavra[j][k];
    }
}

void intercala (int p, int q, int r, palavras *pal) {
    int n1, n2;
    palavras *A, *B;
    int i, j, k, l;

    n1 = q - p + 1;
    n2 = r - q;

    A = malloc (sizeof(palavras));
    A->palavra = malloc (sizeof(palavra) * n1);

    B = malloc (sizeof(palavras));
    B->palavra = malloc (sizeof(palavra) * n2);

    for (i = 0; i < n1; i++) 
        igualaPalavra(A, i, pal, p+i);

    for (i = 0; i < n2; i++)
        igualaPalavra(B, i, pal, q+1+i);


    i=0; j=0; k=p; l=0;

    while (i < n1 && j < n2) {
        while (A->palavra[i][l] == B->palavra[j][l])
            l++;
        CMPS++;

        if (A->palavra[i][l] <= B->palavra[j][l])
            igualaPalavra(pal, k, A, i++);
        else 
            igualaPalavra(pal, k, B, j++);
        l=0; k++; CMPS++; MOVS++;
    }

    while (i < n1) {
        igualaPalavra(pal, k++, A, i++); 
        MOVS++;    
    }

    while (j < n2) {
        igualaPalavra(pal, k++, B, j++);  
        MOVS++;      
    }

    limpa(A); limpa(B);
}

void mergeSort (int i, int f, palavras *p) {
    int m;

    if (i < f) {
        m = (i + f) / 2;
        mergeSort(i, m, p);
        mergeSort(m+1, f, p);
        intercala(i, m, f, p);
    }
}

palavras *lePalavras (int n) {
    int i;
    int lixo;
    palavras *p = malloc (sizeof(palavras));
    p->palavra = calloc (n, sizeof(palavra) * n);


    for (i = 0; i < n; i++)
        lixo =scanf ("%s", p->palavra[i]);
    
    (void)lixo;

    return p;
}

int main () {
    int quant, lixo;
    palavras *palavras;
    clock_t tempo;

    lixo = scanf("%d", &quant);
    (void)lixo;
    palavras = lePalavras(quant);

    tempo= clock();
    mergeSort(0, quant-1, palavras);
    tempo = clock() - tempo;

    printf("tempo: %fs\n", ((float)tempo/CLOCKS_PER_SEC));
    printf("%d comparações\n%d movimentações\n\n", CMPS, MOVS);
    imprimePalavras(quant, palavras);

    return 0;
}