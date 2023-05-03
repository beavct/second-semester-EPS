#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arv.c"

info * resizeInfo(info * velho, int linha){
  info * novo = malloc (sizeof(info));
  novo->linha = malloc(sizeof(int) * (velho->tam + 1));
  novo->qnt = malloc(sizeof(int) * (velho->tam + 1));
  int i;

  for(i = 0; i < velho->tam; i++) {
    novo->linha[i] = velho->linha[i];
    novo->qnt[i] = velho->qnt[i];
  }
  novo->linha[velho->tam] = linha;
  novo->qnt[velho->tam] = 1;
  novo->tam = velho->tam + 1;
  
  free(velho->linha);
  free(velho->qnt);
  free(velho);

  return novo;
} 

no * insercao (no * raiz, char * x, int linha){
  int i, ok = 0; 

  if (raiz == NULL){
    raiz = malloc (sizeof(no));
    raiz->chave = malloc(strlen(x)+1);
    strcpy(raiz->chave,x);

    /*Cria o vetor de informações com o seu tamanho, a linha em que se teve a primeira ocorrência da palavra e a quantidade incial*/
    raiz->info = malloc(sizeof(info));
    raiz->info->linha = malloc (sizeof(info));
    raiz->info->qnt = malloc (sizeof(info));
    raiz->info->linha[0] = linha;
    raiz->info->qnt[0] = 1;
    raiz->info->tam = 1;
    raiz->dir = raiz->esq = NULL;
    return raiz;
  }
  if (strcmp(x, raiz->chave) == 0){
    /*Verifica se a linha já não está no vetor de informações*/
    for(i = 0; i < raiz->info->tam && !ok; i++){
      if(raiz->info->linha[i] == linha){
        raiz->info->qnt[i] += 1;
        ok = 1;
      }
    }
    /*Se não estiver, aloca um vetor de informações maior e insere as informações referentes a nova linha*/
    if(!ok)
      raiz->info = resizeInfo(raiz->info, linha);
  }
  else if (strcmp(x, raiz->chave) < 0)
    raiz->esq = insercao (raiz->esq, x, linha);
  else if (strcmp(x, raiz->chave) > 0)
    raiz->dir = insercao (raiz->dir, x, linha);

  return raiz;
}