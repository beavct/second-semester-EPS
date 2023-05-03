#include <stdio.h>
#include "propriedadesnumericas.h"
#include "vetoraleatorio.h"

void resposta (int feedback) {
    if (feedback == 0) printf ("   Falso   | ");
    else printf ("Verdadeiro | ");
}

int main () {
    int tamanho = 10, semente = 13673214, i;
    long long* vetorTestes = criaVetorAleatorio(semente, tamanho);


    printf("\n");

    for (i = 0; i < tamanho; i++) {
        printf ("Teste %d:\n", i+1);
        printf ("Número de entrada: %lld \n", vetorTestes[i]);
        printf ("| ");

        printf ("É par: ");
        resposta (ehPar(vetorTestes[i]));

        printf ("É primo: ");
        resposta (ehPrimo(vetorTestes[i]));
    
        printf ("É quadrado perfeito: ");
        resposta(ehQuadradoPerfeito(vetorTestes[i]));

        printf ("É cubo perfeito: ");
        resposta(ehCuboPerfeito(vetorTestes[i]));

        printf ("É fibonacci: ");
        resposta(ehFibonacci(vetorTestes[i]));

        printf ("É fatorial: ");
        resposta(ehFatorial(vetorTestes[i]));

        printf ("\n\n");
    }
    return 0;

}