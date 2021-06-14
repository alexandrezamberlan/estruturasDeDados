#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "grafo.h"

int main() {
    setlocale(LC_ALL,"Portuguese");
	Grafo *grafo1 = NULL;
	
	grafo1 = inicializarGrafo(6); //'construtor' do grafo

	// inserirGrafoSimetrico(0,1,grafo1);
	// inserirGrafoSimetrico(0,3,grafo1);
	// inserirGrafoSimetrico(0,4,grafo1);
	// inserirGrafoSimetrico(2,3,grafo1);
	// inserirGrafoSimetrico(2,4,grafo1);
	// inserirGrafoSimetrico(4,5,grafo1);

	inserirGrafo(0,1,grafo1);
	inserirGrafo(0,3,grafo1);
	inserirGrafoSimetrico(0,4,grafo1);
	inserirGrafo(1,3,grafo1);
	inserirGrafo(2,4,grafo1);
	inserirGrafo(3,2,grafo1);
	inserirGrafoSimetrico(4,5,grafo1);
	exibirGrafo(grafo1);

	int origem, destino;
	printf("Digite um vértice de origem válido: ");
	scanf("%d", &origem);

	// printf("Digite um vértice de destino válido: ");
	// scanf("%d", &destino);
    
	// printf("\n\nSerá que tem caminho entre %d e %d? %d\n", origem, destino, temCaminhoAmplitude(grafo1, origem, destino));
	
	percorreAmplitude(grafo1,origem);

	return 0;
}













