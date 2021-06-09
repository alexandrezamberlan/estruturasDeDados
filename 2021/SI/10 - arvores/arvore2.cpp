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
    int quantidade, valor;
    system("clear");

    cout << "Quantos números quer inserir na árvore? ";
    cin >> quantidade;

    raiz = popular(raiz, quantidade);

    exibir(raiz, 0);
    cout << "Esta árvore possui " << contar(raiz) << " elementos" << endl;
    cout << "A soma dos elementos da árvore é: " << somar(raiz) << endl;
    cout << "Esta árvore tem altura de: " << calcularAltura(raiz) << endl;
    cout << "A quantidade de números pares é: " << contarPares(raiz) << " elementos" << endl;
    cout << "A soma dos elementos pares é: " << somarPares(raiz) << endl;

    cout << "\n\n";
    cout << "Digite valor para pesquisa: ";
    cin >> valor;

    if (localizar(valor,raiz)) {
        cout << "Valor encontrado na árvore" << endl;
        cout << "E está no nível " << descobrirNivel(valor,raiz) << endl;
    } else {
        cout << "Valor não localizado na árvore" << endl;
    }

    cout << "O total de elementos múltiplos de " << valor << " é: " << multiplos(valor,raiz) << endl;

    cout << "Total de folhas na árvore é: " << contarFolhas(raiz) << endl;
    cout << "Total de nós não folhas na árvore é: " << contarNaoFolhas(raiz) << endl;

    

    
    return 1;
}
