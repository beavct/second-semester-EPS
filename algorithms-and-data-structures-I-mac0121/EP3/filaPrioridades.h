typedef char palavra[11];

typedef struct {
    int *indice;
    palavra *palavra;
    int tamanho; 
    int capacidade; 
}heap;

void limpa(heap *h);
heap *criaHeap (int quant);
void imprime (heap *h);
