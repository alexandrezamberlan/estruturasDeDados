#include <iostream>
#include "lista.h"

using namespace std;

int main() {
    Celula *lista = NULL;
    system("clear");
    cout << "Recursão em listas simples!" << endl;
    lista = popular(lista, 5); //há alteração na lista
    exibirR(lista); //não há alteração da lista
    cout << "\nA lista possui " << contarElementosR(lista) << endl;
    cout << "A soma dos elementos da lista é: " << somarElementosR(lista) << endl;
    cout << "A quantidade de números pares da lista é: " << contarParesR(lista) << endl;

    int valor;
    cout << "Digite um valor para ser removido: ";
    cin >> valor;

    lista = excluirR(valor, lista); //há alteração na lista
    exibirR(lista); 
    cout << "\nA lista possui " << contarElementosR(lista) << endl;

    cout << "Lista destrída...." << endl;
    lista = destruirR(lista);
    cout << "\nA lista possui " << contarElementosR(lista) << endl;

    return 1;
}