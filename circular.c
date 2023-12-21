#include <stdio.h>
typedef struct Node{
      int valor;
      struct Node *prox;
}Node;

void inserir(Node **head, Node **tail, int valor);
void imprimir(Node *head, Node *tail);
int tamanho(Node *head,  Node *tail);
void remover(Node **head, Node **tail);

int main(void) {   
  Node *head = NULL;
  Node *tail = NULL;
  imprimir(head, tail);

 // printf("\nTamanho: %d", tamanho(head));
  //inserção de nós
  inserir(&head, &tail, 40);
  inserir(&head, &tail, 96);
  inserir(&head, &tail, 53);

  //impressão da lista
  imprimir(head, tail);
  
  //tamanho da lista
  printf("\nTamanho: %d \n", tamanho(head, tail));
  
  //remocao de um nó
  remover(&head,&tail);

  imprimir(head, tail);
  return 0;
}

//insere um novo nó na lista
void inserir(Node **head, Node **tail, int valor) {
  Node *novo = (Node *) malloc(sizeof(Node));
  if(novo != NULL){
    novo->valor = valor;    
    if(*head==NULL){
      *tail = novo;
    }else{
      novo->prox = *head;
    }
    *head = novo;
    (*tail)->prox = *head;
  }
}

//imprime toda a lista
void imprimir(Node *head, Node *tail) { 
  if(head != NULL){  
    do{
      printf("%d ",head->valor);
      head = head->prox;
    }while(head != tail->prox);
  }
}

//retorna o tamanho da lista
int tamanho(Node *head, Node *tail) {
  int contador = 0;
  if(head != NULL){
    do{
      head = head->prox;
      contador ++;
    }while(head != tail->prox);
  }
  return(contador);
}

//Remove o elemento na primeira posição
void remover(Node **head, Node **tail) {
  if(*head != NULL){
    Node *aux = *head;
    if(*head == *tail){
      *head = NULL;
      *tail = NULL;
    }else{  
      *head = (*head)->prox;
      (*tail)->prox = *head;
    }
    free(aux);
  }
}