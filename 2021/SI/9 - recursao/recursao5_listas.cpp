#include <iostream>
#include "lista.h"

using namespace std;


int main() {
    Celula *lista = NULL;
    system("clear");
    cout << "Recursão em listas simples!" << endl;
    lista = popular(lista, 5);
    exibirR(lista);
    cout << "\nA lista possui " << contarElementosR(lista) << endl;
    cout << "A soma dos elementos da lista é: " << somarElementosR(lista) << endl;
    cout << "A quantidade de números pares da lista é: " << contarParesR(lista) << endl;
    return 1;
}