/**
 * Árvores binárias de pesquisa == ordenadas
 * 
 * métodos: inserir, exibir (variações), localizar, contar, somar ...
 * 
 */
#include <iostream>
#include <time.h>

#include "arvore.h"

using namespace std;

Arvore *popular(Arvore *raiz, int n) {
    srand(time(NULL));
    for (;n > 0; n--) {
        raiz = inserir(rand() % 50, raiz);
    }
    return raiz;
}


int main() {
    Arvore *raiz = NULL;
    int quantidade;
    system("clear");

    cout << "Quantos números quer inserir na árvore? ";
    cin >> quantidade;

    raiz = popular(raiz, quantidade);

    exibir(raiz, 0);
    cout << "Esta árvore possui " << contar(raiz) << " elementos" << endl;
    cout << "A soma dos elementos da árvore é: " << somar(raiz) << endl;
    cout << "A quantidade de números pares é:" << contarPares(raiz) << " elementos" << endl;
    // cout << "RED" << endl;
    // exibirRED(raiz);

    // cout << "ERD" << endl;
    // exibirERD(raiz);
    
    // cout << "EDR" << endl;
    // exibirEDR(raiz);
    return 1;
}
