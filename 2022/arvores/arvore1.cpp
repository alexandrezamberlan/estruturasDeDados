#include <iostream>
#include <cstdlib>

using namespace std;

#include "arvores.h"

int main() {
    Arvore *raiz = NULL;

    raiz = inserir(15, raiz);
    raiz = inserir(100, raiz);
    raiz = inserir(15, raiz);
    // raiz = inserir(50, raiz);
    // raiz = inserir(15, raiz);
    // raiz = inserir(10, raiz);
    

    exibir(raiz,0);

    cout << "A altura desta arvore eh: " << calcularAltura(raiz) << endl;

    // int numero = 500;
    // cout << numero << " estah no nivel: " << localizarNivel(numero, raiz) << endl;

    // cout << "Menor valor: " << menorElemento(raiz)->valor << endl;
    // cout << "Maior valor: " << maiorElemento(raiz)->valor << endl;

    return 1;

}