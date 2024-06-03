#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "lista.h"
#include "util.h"

int main() {
    Lista *lista1 = NULL;
    Lista *lista2 = NULL;
    Lista *listaComuns = NULL;
    Lista *listaDisjuncao = NULL;

    lista1 = popularLista(lista1, 8);
    lista2 = popularLista(lista2, 10);

    system("cls");

    cout << "Lista 1" << endl;
    exibir(lista1);

    cout << "Lista 2" << endl;
    exibir(lista2);

    system("pause");

    listaComuns = localizarComuns(lista1, lista2);
    cout << "Números comuns nas listas" << endl;
    exibir(listaComuns);

    system("pause");

    listaDisjuncao = localizarDisjuncao(lista1, lista2);
    cout << "Números disjuntos nas listas" << endl;
    exibir(listaDisjuncao);

    



    return 1;
}