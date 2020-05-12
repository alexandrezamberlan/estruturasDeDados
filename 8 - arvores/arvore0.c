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

//inserir
Arvore *inserir(int valor, Arvore *r) { //ponto A - inicialização da variável de controle
    if (r) { //ponto B - teste de parada
        //avançar ou pra esquerda ou pra direita
        if (valor < r->conteudo) {
            //ir para esquerda
            r->esq = inserir(valor,r->esq);
        } else {
            //ir para direita
            r->dir = inserir(valor, r->dir);
        }
        return r;
    } else {
        //toda a inserção ocorre nas folhas da árvore
        Arvore *novo = (Arvore *)malloc(sizeof(Arvore));
        novo->conteudo = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
}

//exibir

void RED(Arvore *r) { //pesquisa
    if (r) {
        printf("%d\t", r->conteudo); //visita o raiz
        RED(r->esq); //vai para esquerda
        RED(r->dir); //vai para direita
    }
}

void ERD(Arvore *r) { //ordem
   if (r) {
        ERD(r->esq); //vai para esquerda
        printf("%d\t", r->conteudo); //visita o raiz
        ERD(r->dir); //vai para direita
    } 
}

void EDR(Arvore *r) { //podar/excluir/calcular altura
    if (r) {
        EDR(r->esq); //vai para esquerda
        EDR(r->dir); //vai para direita
        printf("%d\t", r->conteudo); //visita o raiz
    } 
}

//contar

//localizar

//remover

//podar

//destruir

/*
       124

   43      200

2       150
*/

int contar(Arvore *r) {
    if (r) {
        return 1 + contar(r->esq) + contar(r->dir);
    }
    return 0;
}

int somar(Arvore *r) {
    if (r) {
        return r->conteudo + somar(r->esq) + somar(r->dir);
    }
    return 0;
}

int localizar(int valor, Arvore *r) {
    if (r) {    
        if (valor == r->conteudo) {
            return 1; //localizado
        }
        if (valor < r->conteudo) {
            //ir para esquerda
            return localizar(valor, r->esq);
        } else {
            //ir para direita
            return localizar(valor, r->dir);
        }
    }
    return 0; //nao localizado
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    printf("Aula sobre árvores encadeadas.....\n");
    Arvore *raiz = NULL;
    raiz = inserir(124,raiz);
    raiz = inserir(43,raiz);
    raiz = inserir(2,raiz);
    raiz = inserir(200,raiz);
    raiz = inserir(150,raiz);


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