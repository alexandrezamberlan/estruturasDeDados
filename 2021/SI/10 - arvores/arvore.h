#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} Arvore;

Arvore *inserir(int valor, Arvore *raiz) {
    if (raiz) {
        if (valor < raiz->valor) { //avançar ou empilhar para a esquerda
            raiz->esq = inserir(valor, raiz->esq);  //teoria da guia ou joão e maria (migalhas)
        } else { //avançar ou empilhar para a direita
            raiz->dir = inserir(valor, raiz->dir);
        }
        return raiz;  //desempilhar e retornar a raiz para o método que o chamou
    } else {
        //se estamos aqui, pq chegamos em um folha e estamos prontos para adicionar o nodo na árvore
        Arvore *novo = (Arvore*)malloc(sizeof(Arvore));
        novo->esq = NULL;
        novo->dir = NULL;
        novo->valor = valor;
        return novo;
    }
}


//RED -> visita Raiz; vai para Esquerda; vai para Direita
void exibirRED(Arvore *raiz) {
    if (raiz) {
        cout << raiz->valor << endl; //antes do primeiro empilhamento
        exibirRED(raiz->esq); //avança empilhando para a esquerda da árvore
        exibirRED(raiz->dir); //avança empilhando para a direita da árvores
    }
}

//ERD -> vai para Esquerda; visita Raiz; vai para Direita
void exibirERD(Arvore *raiz) {
    if (raiz) {
        exibirERD(raiz->esq);
        cout << raiz->valor << endl; //depois do primeiro empilhamento
        exibirERD(raiz->dir);
    }
}

//EDR -> vai para Esquerda; vai para Direita; visita Raiz
void exibirEDR(Arvore *raiz) {
    if (raiz) {
        exibirEDR(raiz->esq);
        exibirEDR(raiz->dir);
        cout << raiz->valor << endl; //depois de todos os empilhamentos
    }
}

//método para exibir uma árvore baseado no livro C Completo e Total de Robert Schild
void exibir(Arvore *raiz, int nivel) {
    if (raiz) {
        //avançar ou empilhar para a direita.... imprimir os maiores valores
        exibir(raiz->dir, nivel + 1);

        //imprimir o elemento que estiver na raiz do momento
        int i;
        for (i = 0; i < nivel; i++) {
            cout << "   ";
        }
        cout << "(" << nivel << ")" << raiz->valor << endl;


        //avançar ou empilhar para a esquerda.... imprimir os menores valores
        exibir(raiz->esq, nivel + 1);
    }
}

int contar(Arvore *raiz) {
    if (raiz) {
        return 1 + contar(raiz->esq) + contar(raiz->dir);
    } else {
        return 0;
    }
}

int somar(Arvore *raiz) {
    if (raiz) {
        return raiz->valor + somar(raiz->esq) + somar(raiz->dir);
    } else {
        return 0;
    }
}

int contarPares(Arvore *raiz) {
    if (raiz) {
        if (raiz->valor % 2 == 0)
            return 1 + contarPares(raiz->esq) + contarPares(raiz->dir);
        return 0 + contarPares(raiz->esq) + contarPares(raiz->dir);
    } else {
        return 0;
    }
}

int somarPares(Arvore *raiz) {
    if (raiz) {
        if (raiz->valor % 2 == 0)
            return raiz->valor + somarPares(raiz->esq) + somarPares(raiz->dir);
        return 0 + somarPares(raiz->esq) + somarPares(raiz->dir);
    } else {
        return 0;
    }
}

bool localizar(int valor, Arvore *raiz) {
    if (raiz) {
        if (valor == raiz->valor) return true; //valor localizado
        if (valor < raiz->valor) { //vamos avançar na árvore para o lado esquerdo
            return localizar(valor, raiz->esq);
        } else { //vamos avançar na árvore para o lado direito
            return localizar(valor, raiz->dir);
        }
    } else {
        return false; //percorri a arvore e cheguei em um nó folha e o valor não foi localizado
    }
}


int descobrirNivel(int valor, Arvore *raiz) {
    if (raiz) {
        if (valor == raiz->valor) return 0; 
        if (valor < raiz->valor) { //vamos avançar na árvore para o lado esquerdo
            int resultadoEmpilhamento = descobrirNivel(valor, raiz->esq);
            if (resultadoEmpilhamento != -1) return resultadoEmpilhamento + 1;
            return resultadoEmpilhamento;
        } else { //vamos avançar na árvore para o lado direito
            int resultadoEmpilhamento = descobrirNivel(valor, raiz->dir);
            if (resultadoEmpilhamento != -1) return resultadoEmpilhamento + 1;
            return resultadoEmpilhamento;
        }
    } else {
        return -1; //percorri a arvore e cheguei em um nó folha e o valor não foi localizado
    }
}

int calcularAltura(Arvore *raiz) {
    if (raiz) {
        int alturaE = calcularAltura(raiz->esq);
        int alturaD = calcularAltura(raiz->dir);
        if (alturaE > alturaD) return alturaE + 1;
        /*else*/ return alturaD + 1;
    } else {
        return 0;
    }
}


/*
                            100
            20                                150
    10              25
                            50

RED: 100 20 10 25 50 150
ERD: 10 20 25 50 100 150  -> percurso ordenado
EDR: 10 50 25 20 150 100  -> percurso das folhas à raiz

                46(0)
        13(1)
    11(2)           37(2)
                33(3)       41(3)


*/