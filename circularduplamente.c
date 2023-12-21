#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int valor;
  struct Node *prox;
  struct Node *ant;
} Node;

void inserir(Node **head, Node **tail, int valor);
void imprimirInverso(Node *head, Node *tail);
void remover(Node **head, Node **tail);

// funções iguais - ListSimplismCirc
void imprimir(Node *head, Node *tail);
int tamanho(Node *head, Node *tail);

int main()
{
  Node *head = NULL;
  Node *tail = NULL;
  // Criação da lista
  imprimir(head, tail);

  // inserção de nós
  inserir(&head, &tail, 60);
  inserir(&head, &tail, 45);
  inserir(&head, &tail, 27);

  // impressão da lista
  imprimir(head, tail);

  // tamanho da lista
  printf("\nTamanho: %d \n", tamanho(head, tail));

  printf("\nImpressão Inversa: ");
  // impressão da lista inversa
  imprimirInverso(head, tail);

  // remocao de elemento
  remover(&head, &tail);

  printf("\n\nApós Remoção: ");
  imprimir(head, tail);
}


// insere um novo nó na lista
void inserir(Node **head, Node **tail, int valor)
{
  Node *novo = (Node *)malloc(sizeof(Node));
  novo->valor = valor;

  if (*head == NULL)
  {
    *head = novo;
    *tail = novo;
    novo->ant = *head;
    novo->prox = *head;
  }
  else
  {
    novo->prox = *head;
    (*head)->ant = novo;
    novo->ant = *tail;
    (*tail)->prox = novo;
    *head = novo;
  }
}
// imprime toda a lista na ordem inversa
void imprimirInverso(Node *head, Node *tail)
{
  if (head != NULL)
  {
    do
    {
      printf("%d ", tail->valor);
      tail = tail->ant;
    } while (head != tail->prox);
  }
}

// Remove o elemento na primeira posição
void remover(Node **head, Node **tail)
{
  if (*head != NULL)
  {
    Node *aux = *head;
    if (*head == *tail)
    {
      *head = NULL;
      *tail = NULL;
    }
    else
    {
      *head = aux->prox;
      (*head)->ant = *tail;
      (*tail)->prox = *head;
    }
    free(aux);
  }
}
//***************Funções em Comum com a Lista Sim. Enc. Circular***************

// imprime toda a lista
void imprimir(Node *head, Node *tail)
{
  if (head != NULL)
  {
    do
    {
      printf("%d ", head->valor);
      head = head->prox;
    } while (head != tail->prox);
  }
}

// retorna o tamanho da lista
int tamanho(Node *head, Node *tail)
{
  int contador = 0;
  if (head != NULL)
  {
    do
    {
      head = head->prox;
      contador++;
    } while (head != tail->prox);
  }
  return (contador);
}