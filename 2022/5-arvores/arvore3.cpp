#include <iostream>
#include <cstdlib>

using namespace std;

#include "arvores.h"

int main() {
    Arvore *raiz = NULL;

    raiz = inserir(15, raiz);
    raiz = inserir(100, raiz);
    raiz = inserir(5, raiz);
    raiz = inserir(50, raiz);
    raiz = inserir(25, raiz);
    raiz = inserir(10, raiz);
    raiz = inserir(2, raiz);
    

    exibir(raiz,0);

    raiz = excluir(15, raiz);

    
    cout << "Arvore apos exclusao\n";
    exibir(raiz,0);

    
    return 1;

}