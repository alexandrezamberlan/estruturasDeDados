#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "grafo.h"

int main() {
    setlocale(LC_ALL,"Portuguese");
	Grafo *grafo1 = NULL;
	
	grafo1 = inicializarGrafo(6); //'construtor' do grafo

	inserirGrafoSimetrico(0,1,grafo1);
	inserirGrafoSimetrico(0,3,grafo1);
	inserirGrafoSimetrico(0,4,grafo1);
	inserirGrafoSimetrico(2,3,grafo1);
	inserirGrafoSimetrico(2,4,grafo1);
	inserirGrafoSimetrico(4,5,grafo1);

	exibirGrafo(grafo1);

	int vertice;
	printf("Digite um vértice válido: ");
	scanf("%d", &vertice);
    printf("O grau do vértice %d é %d\n", vertice, grauVertice(vertice, grafo1));
	percorreAmplitude(grafo1, vertice);

	return 0;
}













