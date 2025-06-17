#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "grafo.h"

int main() {
    
    Grafo *grafo = NULL;

    grafo = inicializar(5);
    inserirAresta(0, 1, grafo);
    inserirAresta(0, 2, grafo);
    inserirAresta(1, 3, grafo);
    inserirAresta(2, 3, grafo);
    inserirAresta(3, 1, grafo);
    inserirAresta(3, 4, grafo);
    inserirAresta(4, 2, grafo);

    exibir(grafo);

    return 1;
}