#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "util.h"

Celula *popular(Celula *lista, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        lista = inserirListaSimples(rand() % 100, lista);
    }
    return lista;
}

int main() {
    Celula *lista = NULL;
    lista = popular(lista, 10);
    exibirListaSimples(lista);

    //contar celulas

    //localizar o menor valor

    //localizar o maior valor

    //calcular e exibir a média

    //fazer uma versao do inserir que nao permita duplicados
    return 1;
}