#include <stdio.h>
#include <stdlib.h>
#include "propriedadesnumericas.h"

int ehPar (long long x) {
    return (x%2 == 0);    
}

int ehPrimo (long long x){
    long long i;

    for (i = 2; i <= x/2; i++) {
        if (x%i == 0) {
            return 0;
        }
    }
    return 1;
}

int ehQuadradoPerfeito (long long x) {
    long long i = 1, j = x, k;

    while (i <= j) {
        k = (i + j) / 2;

        if (k * k == x) 
            return 1;

        if (k * k < x) i = k + 1;
        else j = k - 1;
    }
    return 0;
}

int ehCuboPerfeito (long long x) {
    long long i = 1, j = x, k;

    while (i <= j) {
        k = (i + j) / 2;

        if (k * k  * k == x) 
            return 1;

        if (k * k * k < x) i = k + 1;
        else j = k - 1;
    }
    return 0;
}

int ehFibonacci (long long x) {
    long long i = 0, j = 1, k = 0;

    if (x == i || x == j) 
        return 1;

    k = i + j;

    while (k <= x) {
        if (k == x) 
            return 1;
        i = j;
        j = k;
        k = i + j;
    }
    return 0;
}

int ehFatorial (long long x) {
    long long i;

    for (i = 1;; i++) {
        if (x % i == 0) 
            x /= i;
        else 
            break;
    }

    if (x == 1) 
        return 1;

    return 0; 
}