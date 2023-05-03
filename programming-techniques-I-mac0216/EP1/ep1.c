#include <stdio.h>

int eh_primo (int n);
int prox_primo(int n);
void mult_primos(int n);

int main(void) {
  int n;
  int modo;

  scanf ("%d %d",&modo, &n);
  
  if (modo) {
    mult_primos(n);
  }
  else {
    printf ("%d\n", prox_primo(n));
  }

  return 0;
}

int eh_primo (int n) {
  int i;

  for (i = 2; i < n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int prox_primo(int n) {
  int prox;
  prox = n + 1;
  while (eh_primo(prox) == 0) 
    prox++;

  return prox;
}

void mult_primos(int n) {
  int flag = 0;
  int i, j;

  i = n / 2;
  while (i > 2) {
    j = n / i;
    if (eh_primo(i) && eh_primo(j) && i * j == n) {
      flag = 1;
      break;
    }
    i--;
  }

  if (flag) {
    printf ("%d %d\n", i, j);
  } 
}