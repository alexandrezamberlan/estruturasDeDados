#include <iostream>
#include <ctime>
using namespace std;

#include "listas.h"

int main() {
    Celula *lista = NULL;
    int quantidade = 10;
    srand(time(NULL));

    while (quantidade > 0) {
        lista = inserirR(rand() % 1000, lista);
        quantidade--;
    }

    cout << "Total de elementos na lista: " << contarR(lista) << endl;
    exibirR(lista);

    int numero;
    cout << "Digite numero para pesquisa: ";
    cin >> numero;

    if (estaContidoR(numero, lista)) {
        cout << numero << " localizado na lista\n";
    } else {
        cout << numero << " nao localizado na lista\n";
    }

    lista = removerR(numero, lista);
    
    cout << "Lista apos remoção\n";
    exibirR(lista);

    return 1;
}