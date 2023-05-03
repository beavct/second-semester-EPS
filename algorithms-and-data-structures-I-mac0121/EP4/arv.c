#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

void inordem (no *raiz, FILE * arquivo) {
  int i;

  if (raiz != NULL){
    inordem (raiz->esq, arquivo);

    fprintf(arquivo, "%s:", raiz->chave);
    for(i = 0; i < raiz->info->tam; i++){
      fprintf(arquivo, " %d", raiz->info->linha[i]);
      if(raiz->info->qnt[i] > 1)
        fprintf(arquivo, "(%d)", raiz->info->qnt[i]);
    }
    fprintf(arquivo, "\n");

    inordem (raiz->dir, arquivo);
  }
}

void liberarArv(no * raiz){

  if (raiz != NULL){
    if (raiz->esq != NULL)
      liberarArv(raiz->esq);
    if (raiz->dir != NULL)
      liberarArv(raiz->dir);


    free(raiz->info->linha);
    free(raiz->info->qnt);
    free(raiz->info);
    free(raiz->chave);
    free(raiz);
  }
}




