#include <iostream>
#include <ctime>
using namespace std;

#include "arvore.h"

int main() {
    Arvore *raiz = NULL;

    srand(time(NULL));
    for (int i = 0; i < 25; i++) {
        raiz = add(rand() % 50, raiz);
    }

    //showRED(raiz); //??
    //showERD(raiz); //??
    //showEDR(raiz); //??
    mostrarArvore(raiz, 0);

    return 1;
}

