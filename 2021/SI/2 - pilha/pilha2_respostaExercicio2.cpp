#include <iostream>
#include <string>

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct nodo {
    char valor; // um ou mais atributos ou variávies
    struct nodo *prox;
} Celula;

Celula *inserir(char valor, Celula *topo) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores dos parametros
    novo->valor = valor;

    //engatar
    novo->prox = topo;

    //retornar
    return novo;
}

Celula *excluir(Celula *topo) {
    //soh eh possivel excluir se a pilha nao estiver vazia
    if (!topo) {
        cout << "Expressao estah incorreta. Ha um fecha parenteses antes de um abre parenteses" << endl;
        exit(0);
    }
    Celula *lixo;
    lixo = topo;
    topo = topo->prox; //o ponteiro topo andou uma posição para frente
    free(lixo); //libera a memória ou seja, apaga o elemento
    return topo;
}


int main() {
    system("clear");//system("cls");
    string expressao;
    cout << "Entre com a expressao matematica: ";
    cin >> expressao;

    char letra;
    Celula *pilha = NULL;
    for (int i = 0; i < expressao.size(); i++){
        letra = expressao[i];
        //cout << "analisando a letra: " << letra << endl;
        switch (letra) {
            case '(' : pilha = inserir('(', pilha);
                       break;
            case ')' : pilha = excluir(pilha);
                       break;
            default : break;
        }
    }
    cout << "A expressao digitada foi: " << expressao << endl;

    if (!pilha) {
        cout << "Expressao digitada, em termos de parenteses, estah correta." << endl;
    } else {
        cout << "Expressao digitada, em termos de parenteses, estah incorreta. Ha mais abre parenteses do que fecha parenteses." << endl;
    }

    return 1;
}