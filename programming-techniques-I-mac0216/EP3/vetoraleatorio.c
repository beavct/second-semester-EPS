#include <stdio.h>
#include <stdlib.h>
#include "vetoraleatorio.h"

long long* criaVetorAleatorio (int semente, int tamanho) {
    long long *V = malloc (sizeof(long long) *tamanho);
    int i;

    srand(semente);
    for (i = 0; i < tamanho; i++) {
        V[i] = (long long)rand() * rand ();
    }
    return V;
}