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

    int valor;
    cout << "Entre com valor para ser removido: ";
    cin >> valor;

    lista = removerRepetidosListaSimples(valor,lista);
    cout << "Lista alterada......\n";
    exibirListaSimples(lista);

    int valorAntigo;
    int valorNovo;
    cout << "Entre com valor para ser atualizado: ";
    cin >> valorAntigo;
    cout << "Entre com novo valor: ";
    cin >> valorNovo;
    

    lista = atualizarListaSimples(valorAntigo, valorNovo, lista);
    cout << "Lista atualizada......\n";
    exibirListaSimples(lista);


    lista = destruirListaSimples(lista);
    cout << "Lista destruida......\n";
    exibirListaSimples(lista);

    return 1;
}