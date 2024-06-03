#include <iostream>
#include <ctime>
using namespace std;

#include "arvore.h"

int main() {
    Arvore *raiz = NULL;

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        raiz = add(rand() % 10, raiz);
    }

    //showRED(raiz); //??
    //showERD(raiz); //??
    //showEDR(raiz); //??
    mostrarArvore(raiz, 0);

    cout << "Arvore possui " << contarElementos(raiz) << " elementos\n";
    cout << "Soma dos elementos eh: " << somarElementos(raiz) << endl;

    int valor;
    cout << "Digite um valor para pesquisar: ";
    cin >> valor;

    cout << valor << " esta ou nao na arvore? " << estaContido(valor,raiz) << endl;
    cout << valor << " esta no nivel: " << nivel(valor,raiz) << endl;

    raiz = remove(valor, raiz);
    cout << "Arvore apos delecao\n";
    mostrarArvore(raiz, 0);

    raiz = podar(raiz);
    cout << "Arvore apos poda\n";
    mostrarArvore(raiz, 0);

    return 1;
}

