#include <stdio.h>

#define LEN 7

int main() {
  int v[LEN] = {826, 336, 313,136, 560 ,819, 833};
  int n = 1, troca = 1;
  int iteracoes = 0;

  while (n <= LEN && troca == 1) {
    troca = 0;
    for (int i = 0; i < LEN - 1; i++) {
      if (v[i] > v[i + 1]) {
        int aux = v[i];
        v[i] = v[i + 1];
        v[i + 1] = aux;
        troca = 1;
      }
    }
    iteracoes++;
    n++;
  }

  printf("Sorted array in ascending order after %d iterations:\n", iteracoes);
  for (int i = 0; i < LEN; i++) {
    printf("%d\n", v[i]);
  }

  return 0;
}
