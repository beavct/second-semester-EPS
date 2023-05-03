#define MAX 100
#define ERRO '\0'

typedef struct
{
    int x;
    int y;
}position;

typedef struct
{
    char string[MAX];
    position pos_ini;
    position pos_fim;
    int length;
    int orientation;
    int ID;
    int verificada;
}palavra;

typedef struct
{
    int *IDs;
    int topo;
    int capacidade;
}pilha;

void instancia (int m, int n, int vezes);

/*VERIFICACAO*/
void colocaPalavra (int orientation, int Xini, int Xfim, int Yini, int Yfim, char **Crossword, int **matID, int ID, palavra palavra);
int tamanhoLinha_Coluna (int orientation, int Xini, int Xfim, int Yini, int Yfim, char **Crossword, palavra palavra);
void tentaPreencher (int **matID, int numPalavras, char **Crossword, pilha *p, int lin, int col, palavra *palavras);
void atualiza_palavraAtual (int numPalavras, palavra *palavras);
int verifica_preenchimento (int **matID, int *espacos_vazios, int m, int n);
void removePalavra (int **matID, char **Crossword, palavra palavra);
void destroiPalavras (palavra *palavras);

/*MATRIZES*/
int **cria_matID (int m, int n, char **Crossword, int *cont);
char **alocaCrossword (int lin, int col);
void leCrossword (char **mat, int lin, int col);
palavra *alocaPalavras(int numPalavras);
void imprimeMatriz (char **a, int m, int n);
void destroiMatrizINT (int **matriz, int m);
void destroiMatrizCHAR (char **matriz, int m);

/*PILHA*/
pilha *criaPilha (int numPalavras);
void destroiPilha (pilha *pilha);
int pilhaVazia(pilha * p);
int topoPilha(pilha * p);
int desempilha(pilha * p);
void empilha (pilha * p, int x);







