#include <iostream>
#include <cstdlib>

#include "estruturas.h"

using namespace std;

int main() {
    Fila fila;

    inicializar(&fila);

    inserir(100, &fila);
    inserir(101, &fila);
    inserir(102, &fila);

    int valor = remover(&fila);

    cout << valor << endl;
    
    return 1;
}