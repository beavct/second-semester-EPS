#include "EP1.h"
#include <stdio.h>
#include <stdlib.h>

int calcula(int n, int inicio, info *v)
{
    int x, passos, i;

    x = n;
    passos = 0;
    i = n - inicio;

    while (x != 1)
    {   
        if (x < n)
        {
            passos = passos + procura(v, x, inicio);
            break;
        }
        else
        {
            x = conjec_collatz(x);
            passos++;
        }
    }

    v[i] = passos;
    return passos;
}

int conjec_collatz(int n)
{
    int eh_par;
    eh_par = n % 2 == 0;

    if (eh_par)
    {
        n = n / 2;
    }
    else if (!eh_par)
    {
        n = (3 * n) + 1;
    }
    return n;
}

void *cria(int inicio, int fim)
{
    int tamanho = fim - inicio + 1;
    info *w = malloc(sizeof(info) * tamanho);

    return w;
}

void destroi(info *v)
{
    free(v);
}

int procura(info *v, int n, int inicio)
{ 
    int i;

    i = n - inicio;
    return v[i];
}
