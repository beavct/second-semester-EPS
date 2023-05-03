typedef struct {
  int * linha;
  int * qnt;
  int tam;
} info;


typedef struct cel {
  char * chave; 
  info * info;  
  struct cel * esq;
  struct cel * dir;
} no;

void inordem (no *raiz, FILE * arquivo);
void liberarArv(no * raiz);