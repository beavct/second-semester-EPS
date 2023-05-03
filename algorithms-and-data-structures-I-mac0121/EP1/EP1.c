#include <stdio.h>
#include "EP1.h"

int main()
{
    int i, f, j;
    info *w;

    printf("Digite o inicio intervalo desejado:\n");
    scanf("%d", &i);
    printf("Digite o fim do intervalo desejado:\n");
    scanf("%d", &f);

    w = cria(i, f);

    for (j = i; j <= f; j++)
    {
        printf("=> O numero de passos necessarios para %d convergir para 1 foram %d.\n", j, calcula(j, i, w));
    }

    destroi(w);

    return 0;
}
