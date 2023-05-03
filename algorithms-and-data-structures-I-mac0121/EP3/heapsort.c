#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "filaPrioridades.h"
int CMPS = 0;
int MOVS = 0;

void troca (heap *h, int i, int j) {
    int auxInt, k;
    char auxPalavra[11];

    for (k = 0; k < 10; k++)
        auxPalavra[k] = h->palavra[i][k];

    for (k = 0; k < 10; k++)
        h->palavra[i][k] = h->palavra[j][k];

    for (k = 0; k < 10; k++)
        h->palavra[j][k] = auxPalavra[k];

    auxInt = h->indice[i];
    h->indice[i] = h->indice[j];
    h->indice[j] = auxInt;

}

void corrigeDescendo (heap *h, int i) {
    int maior = i, j = 0;

    /*A prioridade já é a propria letra, de maneira que A < B < ... < a < ... < z*/
    while (h->palavra[maior][j] == h->palavra[2*i][j] && j < 10)
        j++;

    /*Não tem filho à esquerda e a prioridade ele é maior que a de h->letras[i].*/
    if (2*i <= h->tamanho && h->palavra[2*i][j] > h->palavra[maior][j])
        maior = 2*i; 
    CMPS++;       


    j = 0;
    while(h->palavra[maior][j] == h->palavra[(2*i)+1][j] && j < 10)
        j++;
    
    /*Não tem filho à direita e este tem prioridade maior que a de h->letras[maior].*/
    if ((2*i)+1 <= h->tamanho && h->palavra[(2*i)+1][j] > h->palavra[maior][j])
        maior = (2*i)+1;
    CMPS++;

    /*Se maior != i, entao temos que consertar o heap.*/
    if (maior != i) {
        troca(h, i, maior);
        MOVS++;
        corrigeDescendo(h, maior); 
    }
}

void constroiHeap(heap *h, int n) {
    int i;
    h->tamanho = n;

    for(i = h->tamanho/2; i >= 1; i--)
        corrigeDescendo(h, i); 
}

void heapsort (heap *h, int n) {
    int i;
    constroiHeap(h, n);
    for (i = n; i >= 2; i--){
        troca (h, 1, i);
        MOVS++;
        h->tamanho--;
        corrigeDescendo(h, 1);
    }
}

int main () {
    int quant, lixo; 
    heap *h;
    clock_t tempo;

    lixo = scanf("%d", &quant);
    (void)lixo;
    h = criaHeap(quant);

    tempo= clock();
    heapsort (h, quant);
    tempo = clock() - tempo;

    printf("tempo: %fs\n", ((float)tempo/CLOCKS_PER_SEC));
    printf("%d comparações\n%d movimentações\n\n", CMPS, MOVS);
    imprime(h);
    limpa(h);

    return 0;  
}