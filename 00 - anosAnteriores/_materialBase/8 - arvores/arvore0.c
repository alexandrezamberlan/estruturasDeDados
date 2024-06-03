#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

/*
As três maneiras mais usuais para percorrer os nós são (PROFUNDIDADE):

Caminhamento Pré-fixado (RED)
    visita a raiz - printf, if, comando qualquer sobre o conteúdo do nodo
    percorre a sub-árvore da esquerda
    percorre a sub-árvore da direita

Caminhamento In-fixado (ERD)
    percorre a sub-árvore da esquerda
    visita a raiz - printf, if, comando qualquer sobre o conteúdo do nodo
    percorre a sub-árvore da direita

Caminhamento Pós-fixado (EDR)
    percorre a sub-árvore da esquerda
    percorre a sub-árvore da direita
    visita a raiz - printf, if, comando qualquer sobre o conteúdo do nodo

*/
typedef struct no {
    int conteudo;
    struct no *esq;
    struct no *dir;
} Arvore;

Arvore *inserir(int valor, Arvore *r) { //garante que a árvore esteja ordenada
    if (r) {
        if (valor < r->conteudo) {
            //vai para esquerda
            r->esq = inserir(valor, r->esq);
        } else {
            //vai para direita
            r->dir = inserir(valor,r->dir);
        }
        return r;
    } else {
        Arvore *novo;
        //alocar memoria
        novo = (Arvore *)malloc(sizeof(Arvore));
        //depositar valores
        novo->conteudo = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        //todo nó é inserido numa extremidade da árvore e ele torna-se folha
        return novo;
    }
}

//RED
void RED(Arvore *r) {
    if (r) {
        printf("%d\t",r->conteudo); //visito o raiz
        RED(r->esq);//vou pra esquerda
        RED(r->dir);//vou pra direita
    }
}

//ERD
void ERD(Arvore *r) {
    if (r) {
        ERD(r->esq);
        printf("%d\t",r->conteudo); //visito o raiz
        ERD(r->dir);
    }
}

//EDR
void EDR(Arvore *r) {
    if (r) {
        EDR(r->esq);
        EDR(r->dir);
        printf("%d\t",r->conteudo); //visito o raiz
    }
}

//contar
int contar(Arvore *r) {
    if (r) {
        return 1 + contar(r->esq) + contar(r->dir);
    }
    return 0;
}

//somar
int somar(Arvore *r) {
    if (r) {
        return r->conteudo + somar(r->esq) + somar(r->dir);
    }
    return 0;
}

//localizar
int localizar(int valor, Arvore *r) {
    if (r) {
        if (valor == r->conteudo) { //RED
            return 1; //localizado
        }
        if (valor < r->conteudo) {
            //ir para esquerda
            return localizar(valor, r->esq);
        } else {
            //ir para direita
            return localizar(valor, r->dir);
        }
    } else {
        return 0; //nao localizado
    }
}

//remover

//podar

//destruir

/*
       124

   43      200

2       150
    124
*/


int main() {
    setlocale(LC_ALL,"Portuguese");
    printf("Aula sobre árvores encadeadas.....\n");
    
    Arvore *raiz = NULL;

    raiz = inserir(124,raiz);
    raiz = inserir(43,raiz);
    raiz = inserir(2,raiz);
    raiz = inserir(200,raiz);
    raiz = inserir(150,raiz);
    raiz = inserir(124,raiz);


    printf("A árvore possui %d elementos\n", contar(raiz));
    printf("A soma dos elementos da árvore é %d \n", somar(raiz));

    printf("\nRED\n"); //124 43 2 200 150
    RED(raiz);

    printf("\nERD\n"); //2 43 124 150 200
    ERD(raiz);

    printf("\nEDR\n"); //2 43 150 200 124
    EDR(raiz);

    int numero;
    printf("\nEntre número para pesquisar: ");
    scanf("%d", &numero);

    printf("%d foi localizado: %d\n", numero, localizar(numero,raiz));

}