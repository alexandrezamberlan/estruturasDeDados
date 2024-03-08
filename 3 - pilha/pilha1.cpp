#include <iostream>
#include <cstdlib>

using namespace std;

#include "pilha.h"

int main() 
{
    Pilha *pilha = NULL;

    pilha = inserir(10, pilha);
    pilha = inserir(15, pilha);
    pilha = inserir(5, pilha);

    exibir(pilha);
    cout << topo(pilha) << endl;

    cout << localizado(6,pilha) << endl;

    pilha = remover(pilha);
    cout << "Pilha alterada" << endl;

    exibir(pilha);

    return 1;

}