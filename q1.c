#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
    int chave;
    int valor;
    struct arv *esq;
    struct arv *dir;
} Arv; 

void inserir(Arv **t, int chave, int valor);
void inordem(Arv *t);
void posordem(Arv *t);
void preordem(Arv *t);
int busca(Arv *aux, int n);
void remover(Arv **pRaiz, int numero);
Arv *MaiorDireita(Arv **no);

int somatorioNos(Arv *t) {
    if (t == NULL) return 0;
    
    else return t->chave + somatorioNos(t->esq) + somatorioNos(t->dir);
}
void imprimirPaiFolha(Arv *t) {
    if (t != NULL) {
        if (t->esq == NULL && t->dir == NULL) {
            printf("PAI DE FOLHA: %d - %d\n", t->chave, t->valor);
        }
        imprimirPaiFolha(t->esq);
        imprimirPaiFolha(t->dir);
    }
}

int main() {
    Arv *t = NULL;

    inserir(&t, 6, 6);
    inserir(&t, 2, 2);
    inserir(&t, 8, 8);
    inserir(&t, 7, 7);
    inserir(&t, 9, 9);
    inserir(&t, 1, 1);
    inserir(&t, 4, 4);
    inserir(&t, 3, 3);

    printf("\nPRE-ordem:");
    preordem(t);

    printf("\nIN-ordem:");
    inordem(t);

    printf("\nPOS-ordem:");
    posordem(t);
    printf("\n\n");

    if (busca(t, 4)) {
        printf("\nO numero está na arvore!\n");
    } else {
        printf("O numero NAO está na arvore!\n");
    }

    printf("\nPre-ordem:");
    preordem(t);
    printf("\n");

    remover(&t, 8);

    printf("\nPrint após remoção (Pre-ordem):");
    preordem(t);
    printf("\n");
    printf("SOMA = %d\n", somatorioNos(t));
    imprimirPaiFolha(t);
    return 0;
}

void preordem(Arv *t) {
    if (t != NULL) {
        printf("%d ", t->chave);
        preordem(t->esq);
        preordem(t->dir);
    }
}

void inordem(Arv *t) {
    if (t != NULL) {
        inordem(t->esq);
        printf("%d ", t->chave);
        inordem(t->dir);
    }
}

void posordem(Arv *t) {
    if (t != NULL) {
        posordem(t->esq);
        posordem(t->dir);
        printf("%d ", t->chave);
    }
}

void inserir(Arv **t, int chave, int valor) {
    if (*t == NULL) {
        *t = (Arv *)malloc(sizeof(Arv));
        (*t)->esq = NULL;
        (*t)->dir = NULL;
        (*t)->chave = chave;
        (*t)->valor = valor;
    } else {
        if (chave < (*t)->chave) {
            inserir(&(*t)->esq, chave, valor);
        }
        if (chave > (*t)->chave) {
            inserir(&(*t)->dir, chave, valor);
        }
    }
}

int busca(Arv *aux, int n) {
    if (aux == (Arv *)NULL)
        return (0);
    if (aux->chave == n)
        return (1);
    if (n < aux->chave)
        busca(aux->esq, n);
    else
        busca(aux->dir, n);
}

Arv *MaiorDireita(Arv **no) {
    if ((*no)->dir != NULL)
        return MaiorDireita(&(*no)->dir);
    else {
        Arv *aux = *no;
        if ((*no)->esq != NULL) {
            *no = (*no)->esq;
        } else {
            *no = NULL;
        }
        return aux;
    }
}

void remover(Arv **pRaiz, int numero) {
    if (*pRaiz == NULL) {
        printf("Numero nao existe na arvore!");
        return;
    }
    if (numero < (*pRaiz)->chave)
        remover(&(*pRaiz)->esq, numero);
    else if (numero > (*pRaiz)->chave)
        remover(&(*pRaiz)->dir, numero);
    else {
        Arv *pAux = *pRaiz;
        // 01 - no sem filhos
        if (((*pRaiz)->esq == NULL) && ((*pRaiz)->dir == NULL)) {
            free(pAux);
            (*pRaiz) = NULL;
        } else {
            // 02 - no com filho direito
            if ((*pRaiz)->esq == NULL) {
                (*pRaiz) = (*pRaiz)->dir;
                pAux->dir = NULL;
                free(pAux);
                pAux = NULL;
            } else {
                // 02 - no com filho esquerdo
                if ((*pRaiz)->dir == NULL) {
                    (*pRaiz) = (*pRaiz)->esq;
                    pAux->esq = NULL;
                    free(pAux);
                    pAux = NULL;
                } else {
                    // 03 - no com dois filhos
                    pAux = MaiorDireita(&(*pRaiz)->esq);
                    pAux->esq = (*pRaiz)->esq;
                    pAux->dir = (*pRaiz)->dir;
                    (*pRaiz)->esq = (*pRaiz)->dir = NULL;
                    free((*pRaiz));
                    *pRaiz = pAux;
                    pAux = NULL;
                }
            }
        }
    }
}