#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "lista.h"

int main() {
    Lista *lista = NULL;
    int qtd = 100;
    srand(time(NULL));

    for (; qtd > 0; qtd--) {
        lista = inserir(rand() % 400, lista);
    }
    cout << "Tamanho da lista " << contar(lista) << endl;
    exibir(lista);

    return 1;
}