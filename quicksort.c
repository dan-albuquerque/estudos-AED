#include <stdio.h>
#include <stdlib.h>
#define TAM 7

void quicksort(int v[], int inicio, int fim);
void troca(int v[], int i, int j);
int particao(int v[], int inicio, int fim);
int particao_aleatoria(int v[], int inicio, int fim);

int main() {
  int vet[7] = {55, 25, 34, 10, -20, 68, 62};

  printf("Vetor de Entrada:\n");
  for (int i = 0; i < TAM; i++)
    printf("%d ", vet[i]);

  quicksort(vet, 0, TAM - 1);

  printf("\n\nVetor Ordenado:\n");
  for (int i = 0; i < TAM; i++)
    printf("%d ", vet[i]);

  return 0;
}

void quicksort(int v[], int inicio, int fim) {
  if (inicio < fim) {
    int indice = particao_aleatoria(v, inicio, fim);

    quicksort(v, inicio, indice - 1);
    quicksort(v, indice + 1, fim);
  }
}

int particao(int v[], int inicio, int fim) {
  int pivot, indice;
  pivot = v[inicio];
  indice = fim;

  for (int i = fim; i > inicio; i--)
    if (v[i] >= pivot) {
      swap(v, i, indice);
      indice--;
    }

  troca(v, inicio, indice);
  return indice;
}


void swap(int v[], int i, int j) {
  int aux = v[i];
  v[i] = v[j];
  v[j] = aux;
}
//desordena pra aumentar eficiencia
int particao_aleatoria(int v[], int inicio, int fim) {
  int indice = (rand() % (fim - inicio + 1)) + inicio;
  troca(v, indice, inicio);
  return particao(v, inicio, fim);
}