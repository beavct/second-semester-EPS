#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaPrioridades.h"

/*Codigo de preenchimento e correcao feitos com base das notas de aula sobre heapsort.*/
void limpa (heap *h) {
    free(h->indice);
    free(h->palavra);
    free(h);
}

heap *criaHeap (int quant) {
    int i, lixo;
    /*Iremos inutilizar o primeiro indice do h->letras para nossa implementacao.*/
    heap *h = malloc (sizeof(heap));
    h->capacidade = quant;
    h->tamanho = quant;
    h->indice = malloc (sizeof(int) * (quant + 1));
    h->palavra = calloc (quant + 1,sizeof(palavra) * (quant + 1));


    for (i = 1; i <= quant; i++) {
        lixo = scanf("%s", h->palavra[i]);      
        h->indice[i] = i;  
    }
    (void)lixo;
    
    return h;
}

void imprime (heap *h) {
    int i;

    for (i = 1; i <= h->capacidade; i++) {
        printf ("%s\n", h->palavra[i]);
    }
}
