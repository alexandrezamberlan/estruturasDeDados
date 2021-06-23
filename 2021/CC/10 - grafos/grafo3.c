#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "grafo.h"

int main() {
    setlocale(LC_ALL,"Portuguese");
	Grafo *grafo1 = NULL;
	Grafo *grafo2 = NULL;

	grafo2 = inicializarGrafo(7);
	inserirGrafoSimetricoValorado(0,1,grafo2,7);
	inserirGrafoSimetricoValorado(0,3,grafo2,5);
	inserirGrafoSimetricoValorado(1,2,grafo2,8);
	inserirGrafoSimetricoValorado(1,3,grafo2,9);
	inserirGrafoSimetricoValorado(1,4,grafo2,7);
	inserirGrafoSimetricoValorado(2,4,grafo2,5);
	inserirGrafoSimetricoValorado(3,4,grafo2,15);
	inserirGrafoSimetricoValorado(3,5,grafo2,6);
	inserirGrafoSimetricoValorado(4,5,grafo2,8);
	inserirGrafoSimetricoValorado(4,6,grafo2,9);
	inserirGrafoSimetricoValorado(5,6,grafo2,11);
	exibirGrafo(grafo2);
	printf("O grau do vértice 3 (D) é: %d\n\n", grauVertice(3,grafo2));




	// inserirGrafoSimetrico(0,1,grafo1);
	// inserirGrafoSimetrico(0,3,grafo1);
	// inserirGrafoSimetrico(0,4,grafo1);
	// inserirGrafoSimetrico(2,3,grafo1);
	// inserirGrafoSimetrico(2,4,grafo1);
	// inserirGrafoSimetrico(4,5,grafo1);

	// inserirGrafo(0,1,grafo1);
	// inserirGrafo(0,3,grafo1);
	// inserirGrafoSimetrico(0,4,grafo1);
	// inserirGrafo(1,3,grafo1);
	// inserirGrafo(2,4,grafo1);
	// inserirGrafo(3,2,grafo1);
	// inserirGrafoSimetrico(4,5,grafo1);
	// exibirGrafo(grafo1);

	// int origem, destino;
	// printf("Digite um vértice de origem válido: ");
	// scanf("%d", &origem);

	// printf("Digite um vértice de destino válido: ");
	// scanf("%d", &destino);
    
	// printf("\n\nSerá que tem caminho entre %d e %d? %d\n", origem, destino, temCaminhoAmplitude(grafo1, origem, destino));
	
	// percorreAmplitude(grafo1,origem);

	return 0;
}













