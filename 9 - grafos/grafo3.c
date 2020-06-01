#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "grafo.h"
#include "fila.h"

int main() {
    setlocale(LC_ALL,"Portuguese");
	Grafo *grafo = NULL;
	Grafo *grafo1 = NULL;

	grafo = inicializarGrafo(5); //'construtor' do grafo

	inserirGrafo(0,1,grafo);
	inserirGrafo(0,4,grafo);
	inserirGrafo(1,0,grafo);
	inserirGrafo(1,2,grafo);
	inserirGrafo(2,3,grafo);
	inserirGrafo(3,0,grafo);
	inserirGrafo(4,3,grafo);
	exibirGrafo(grafo);

	printf("\n");

	grafo1 = inicializarGrafo(3); //'construtor' do grafo
    printf("O grau do vértice 2 é: %d\n\n", grauVertice(2,grafo));

	inserirGrafoSimetrico(0,1,grafo1);
	inserirGrafoSimetrico(1,2,grafo1);
	inserirGrafoSimetrico(2,0,grafo1);
	exibirGrafo(grafo1);

    printf("grafo é simétrico? %d\n", ehSimetrico(grafo));

	return 0;
}













