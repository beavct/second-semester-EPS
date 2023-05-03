#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio.h"

int main () {
    int m, n, vezes = 1;

    while (1) {
        printf ("Digite as dimensoes da matriz da instancia %d:\n", vezes);
        scanf ("%d %d", &m, &n);
        if (m && n) {
            instancia (m, n, vezes);
            vezes++;
        }      
        break;
    }
    return 0;
}

/*FUNCOES*/
void instancia (int m, int n, int vezes) {
    int **matID, numPalavras, auxID;
    char **Crossword;
    pilha *p;
    int espacos_vazios;
    palavra *palavras;

    Crossword = alocaCrossword(m, n);
    matID = cria_matID(m, n, Crossword, &espacos_vazios);

    scanf("%d", &numPalavras);

    palavras = alocaPalavras(numPalavras);
    p = criaPilha(numPalavras);

    tentaPreencher(matID, numPalavras, Crossword, p, m, n, palavras);

    /*Palavra cruzada nao esta completa*/
    if (!verifica_preenchimento(matID, &espacos_vazios, m, n)) {
        while (!pilhaVazia(p)) {
            auxID = desempilha(p);
            palavras[auxID - 1].verificada = 0;
            removePalavra(matID, Crossword, palavras[auxID]);
            tentaPreencher(matID, numPalavras, Crossword, p, m, n, palavras);         
        }
    }

    /*A matriz ID esta completamente preenchida, logo a palavra cruzada esta completa*/
    if (verifica_preenchimento(matID, &espacos_vazios, m, n)) {
        imprimeMatriz(Crossword, m, n);  
    }
    else {
    printf ("Instancia %d\n", vezes);
            printf ("Nao ha solucao\n");     
    }

    destroiPilha(p);
    destroiMatrizINT (matID, m);
    destroiMatrizCHAR (Crossword, m);
    destroiPalavras (palavras);
}

/*VERIFICACAO*/
void colocaPalavra (int orientation, int Xini, int Xfim, int Yini, int Yfim, char **Crossword, int **matID, int ID, palavra palavra) {
    int i, k;
    char letra;

    /*Preenche horizontalmente*/
    if (orientation == 0) {
        for (i = Yini; i <= Yfim; i++) {
            letra = palavra.string[k++];
            Crossword[Xini][i] = letra;
            if (matID[Xini][i] == 0) matID[Xini][i] = palavra.ID;
        }
    }

    /*Preenche verticalmente*/
    else {
        for (i = Xini; i <= Xfim; i++) {
            letra = palavra.string[k++]; 
            Crossword[i][Yini] = letra;
            if (matID[i][Yini] == 0) matID[i][Yini] = palavra.ID;         
        }
    }
}

int tamanhoLinha_Coluna (int orientation, int Xini, int Xfim, int Yini, int Yfim, char **Crossword, palavra palavra) {
    int i, cont = 0, k = 0;
    char letra;

    /*Verifica linha*/
    if (orientation == 0) {
        for (i = Yini; i <= Yfim; i++) {
            letra = palavra.string[k++];
            if (Crossword[Xini][i] == (char)0 || Crossword[Xini][i] == letra) cont++;
            else return 0;
        }
    }

    /*Verifica coluna*/
    else { /*orientation == 1*/
        for (i = Xini; i <= Xfim; i++) {
            letra = palavra.string[k++];
            if (Crossword[i][Yini] == (char)0 || Crossword[i][Yini] == letra)cont++;
            else return 0;
        }
    }

    return (cont == palavra.length);
}

void tentaPreencher (int **matID, int numPalavras, char **Crossword, pilha *p, int lin, int col, palavra *palavras) {
    int i, j;
    int Xini = 0, Xfim = 0, Yini = 0, Yfim = 0;
    int numIDs = 0;

    atualiza_palavraAtual(numPalavras, palavras);

    /*Horizontal*/
    for (i = 0; i < lin; i++) {
        Xini = i;
        for (j = 0; j < col; j++) {
            if (matID[i][j]) continue;
            else {
                /*Caso tenha um -1 logo na primeira coluna*/
                if (!j) break; 
                Yfim = j - 1;

                /*A palavra cabe na linha*/
                if (tamanhoLinha_Coluna(0, Xini, Xfim, Yini, Yfim, Crossword, palavras[numIDs])) {
                    colocaPalavra(0, Xini, Xfim, Yini, Yfim, Crossword, matID, numIDs + 1, palavras[numIDs]);
                    empilha (p, numIDs+1);
                    palavras[numIDs].orientation = 0;
                    palavras[numIDs].verificada = 1;
                    palavras[numIDs].pos_ini.x = Xini;
                    palavras[numIDs].pos_ini.y = Yini;
                    palavras[numIDs].pos_fim.x = Xfim;
                    palavras[numIDs].pos_fim.y = Yfim;
                    
                    atualiza_palavraAtual(numPalavras, palavras);
                }
                else { /*A palavra nao cabe*/
                    Yini = j + 1;
                    continue;
                }
            }
        }
        Yini = 0;
    }

    Xini = 0; Xfim = 0; Yini = 0; Yfim = 0;

    /*Vertical*/
    for (j = 0; j < col; j++) {
        Yini = j;
        for (i = 0; i < lin; i++){
            if (matID[i][j]) continue;
            else {
                /*Caso tenha -1 logo na primeira linha*/
                if (!i) break; 
                Xfim = i - 1; 

                /*Palavra cabe na coluna*/
                if (tamanhoLinha_Coluna(1, Xini, Xfim, Yini, Yfim, Crossword, palavras[numIDs])) {
                    colocaPalavra(1, Xini, Xfim, Yini, Yfim, Crossword, matID, numIDs + 1, palavras[numIDs]);
                    empilha(p, numIDs + 1);
                    palavras[numIDs].orientation = 1;
                    palavras[numIDs].verificada = 1;
                    palavras[numIDs].pos_ini.x = Xini;
                    palavras[numIDs].pos_ini.y = Yini;
                    palavras[numIDs].pos_fim.x = Xfim;
                    palavras[numIDs].pos_fim.y = Yfim;
                    
                    atualiza_palavraAtual(numPalavras, palavras);
                }
                else {
                    Xini = i + 1;
                    continue;
                }
            }
        }
        Xini = 0;
    }
}

void atualiza_palavraAtual (int numPalavras, palavra *palavras) {
    int numIDs = 0;

    while (palavras[numIDs].verificada == 1 && numIDs < numPalavras ) numIDs++;
}

int verifica_preenchimento (int **matID, int *espacos_vazios, int m, int n) {
    int i, j, cont = 0, zero = 0;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (matID[i][j] == 0) cont++; 
        }
    }

    /*Se retorna zero, significa que ha espacos na matriz de ID que nao foram preenchidos, logo a palavra cruzada nao foi totalmente preenchida*/
    return(cont == zero);
}

void removePalavra (int **matID, char **Crossword, palavra palavra) {
    int i;

    /*Remove palavra na horizontal*/
    if (palavra.orientation == 0) {
        for (i = palavra.pos_ini.y; i <= palavra.pos_fim.y; i++) {
            /*Verificacao, pois a mesma letra pode pertencer a mais de uma palavra*/
            if (matID[palavra.pos_ini.x][i] == palavra.ID) {
                matID[palavra.pos_ini.x][i] = 0;
                Crossword[palavra.pos_ini.x][i] = ' ';
            }
        }
    }
    /*Remove palavra na vertical*/
    else {
        for (i = palavra.pos_ini.x; i <= palavra.pos_fim.x; i++) {
            if (matID[i][palavra.pos_ini.y] == palavra.ID) {
                matID[i][palavra.pos_ini.y] = 0;
                Crossword[i][palavra.pos_ini.y] = ' ';
            }
        }
    }
}

void destroiPalavras (palavra *palavras) {
    free (palavras);
}

/*MATRIZES*/
int **cria_matID (int m, int n, char **Crossword, int *cont) {
    int **matID, i, j;

    *cont = 0;

    matID = malloc (sizeof(int) * m);

    for (i = 0; i < n; i++) {
        matID[i] = malloc (sizeof(int) * n);
    }

    /*Inicializa a matriz de acordo com o Crossword*/
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (Crossword[i][j] == '*') {
                matID[i][j] = -1;
                cont++;
            }
            else {
                matID[i][j] = 0;
            }
        }
    }

    *cont = (m * n) - *cont;
    return matID;
}

char **alocaCrossword (int lin, int col) {
    char ** mat = malloc (lin * sizeof(char *));
    int i;
    for (i = 0; i < lin; i++)
    mat[i] = malloc (col * sizeof(char));

    leCrossword(mat, lin, col);
    return mat;
}

void leCrossword (char **mat, int lin, int col) {
    int i, j, digito;
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &digito);
            if (digito == 0) mat[i][j] = ' ';
            else mat[i][j] = '*';
        }
    }
}

palavra *alocaPalavras(int numPalavras) {
    int i = 0, num_Ids = 1; 
    palavra *palavras;

    palavras = malloc (sizeof(palavra) * numPalavras);

    while (numPalavras > 0) {
        scanf ("%s", &palavras[i].string[0]);
        palavras[i].length = strlen(palavras[i].string);
        palavras[i].ID = num_Ids;

        numPalavras--; i++; num_Ids++;
    }
    return palavras;
}

void imprimeMatriz (char **a, int m, int n) {
    int i,j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++){
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }

}

void destroiMatrizINT (int **matriz, int m) {
    int i;

    for (i = 0; i < m; i++) {
        free(matriz[i]);
    }
    free(matriz);
} 

void destroiMatrizCHAR (char **matriz, int m) {
    int i;

    for (i = 0; i < m; i++) {
        free(matriz[i]);
    }
    free(matriz);
} 

/*PILHA*/
pilha *criaPilha (int numPalavras) {
    pilha *p = malloc (sizeof(pilha) * 1);

    p->IDs = malloc (sizeof(int) * numPalavras); 
    p-> topo = 0;
    p->capacidade = MAX;

    return p;
}

void destroiPilha (pilha *pilha) {
    free(pilha->IDs);
    free(pilha);
}

int pilhaVazia(pilha * p){
  return (p->topo == 0);
}

int topoPilha(pilha * p){
  if (!pilhaVazia (p))
    return p->IDs[p->topo-1];
  return ERRO;
}

int desempilha(pilha * p){
  char aux; 
  if (!pilhaVazia(p)){
    p->topo=p->topo - 1; 
    aux = p->IDs[p->topo];
    p->IDs[p->topo] = ERRO; 
    return aux;
  }
  return ERRO;
}

void empilha (pilha * p, int x){
  p->IDs[p->topo] = x;
  p->topo++;
}
