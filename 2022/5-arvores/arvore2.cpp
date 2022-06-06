#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include "arvores.h"

int main() {
    ArvoreString *raiz = NULL;

    raiz = inserirString("Gabriel", raiz);
    raiz = inserirString("Alex", raiz);
    raiz = inserirString("Carlos", raiz);
    raiz = inserirString("Arthur", raiz);
    raiz = inserirString("Itamar", raiz);
    

    exibirString(raiz,0);

    // cout << "A altura desta arvore eh: " << calcularAltura(raiz) << endl;

    // int numero = 500;
    // cout << numero << " estah no nivel: " << localizarNivel(numero, raiz) << endl;

    // cout << "Menor valor: " << menorElemento(raiz)->valor << endl;
    // cout << "Maior valor: " << maiorElemento(raiz)->valor << endl;

    return 1;

}