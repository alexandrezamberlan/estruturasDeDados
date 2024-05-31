#include<iostream>
#include<ctime>
#include "celula.h"

using namespace std;

int main() {
    Celula *lista = NULL;
    int valor;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        valor = rand() % 50;
        lista = add(valor, lista);
    }

    cout << "Tamanho da lista: " << count(lista) << endl;
    print(lista);

    cout << "Digite um valor para pesquisa: ";
    cin >> valor;

    if (contains(valor, lista)) {
        cout << "Valor localizado e sendo apagado..... " << endl;
        lista = remove(valor, lista);
    } else {
        cout << "Valor nao localizado" << endl;
    }
    
    cout << "Total de pares: " << countPair(lista) << endl;

    cout << "Tamanho da lista apos remocao: " << count(lista) << endl;
    print(lista);

    cout << "Digite um valor para descobrir seu indice: ";
    cin >> valor;

    cout << "Indice do valor na lista eh: " << indexOf(valor,lista) << endl;

    return 1;
}
