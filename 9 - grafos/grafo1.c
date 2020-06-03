#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int **matrizAdj;
	int qtdVertices; //qtdNos ou qtdNodos
	int qtdArestas;
} Grafo;

Grafo *inicializarGrafo(int vertices) { //ideia de construtor
	int i, j;

	Grafo *g = (Grafo *)malloc(sizeof(Grafo));

	g->qtdVertices = vertices;
	g->qtdArestas = 0;

	g->matrizAdj = malloc(vertices * sizeof(int *));

	for (i = 0; i < g->qtdVertices; i++)
		g->matrizAdj[i] = malloc(vertices * sizeof(int));

	for (i = 0; i < g->qtdVertices; i++)
		for (j = 0; j < g->qtdVertices; j++)
			g->matrizAdj[i][j] = 0;

	return g;
}

void inserirGrafo(int origem, int destino, Grafo *g) {
	if (origem < 0 || origem >= g->qtdVertices || destino < 0 ||
		destino >= g->qtdVertices || g->matrizAdj[origem][destino] != 0) {
		printf("Aresta nao cadastrada\n");
	} else {
		g->matrizAdj[origem][destino] = 1;
		g->qtdArestas++;
	}
}

void inserirGrafoSimetrico(int origem, int destino, Grafo *g) {
	if (origem < 0 || origem >= g->qtdVertices || destino < 0 ||
		destino >= g->qtdVertices || g->matrizAdj[origem][destino] != 0 ||
		origem == destino) {
		printf("Aresta nao cadastrada\n");
	} else {
		g->matrizAdj[origem][destino] = 1;
		g->matrizAdj[destino][origem] = 1;
		g->qtdArestas+=2;
	}
}

void exibirGrafo(Grafo *g) {
	if (!g) {
		printf("Grafo nao existe\n");
	} else {
		int i,j;
		for (i = 0; i < g->qtdVertices;i++) {
			printf("%d: ", i);
			for (j = 0; j < g->qtdVertices; j++) {
				if (g->matrizAdj[i][j] != 0)
					printf("%d   ", j);
			}
			printf("\n");
		}
	}
}

int main() {
	Grafo *grafo = NULL;
	Grafo *grafo1 = NULL;

	// grafo = inicializarGrafo(5); //'construtor' do grafo

	// inserirGrafo(0,1,grafo);
	// inserirGrafo(0,4,grafo);
	// inserirGrafo(1,0,grafo);
	// inserirGrafo(1,2,grafo);
	// inserirGrafo(2,3,grafo);
	// inserirGrafo(3,0,grafo);
	// inserirGrafo(4,3,grafo);
	// exibirGrafo(grafo);

	// printf("\n");

	grafo1 = inicializarGrafo(7); //'construtor' do grafo

	inserirGrafoSimetrico(1,2,grafo1);
	inserirGrafoSimetrico(1,5,grafo1);
	inserirGrafoSimetrico(2,3,grafo1);
	inserirGrafoSimetrico(2,5,grafo1);
	inserirGrafoSimetrico(3,4,grafo1);
	inserirGrafoSimetrico(4,5,grafo1);
	inserirGrafoSimetrico(4,6,grafo1);

	exibirGrafo(grafo1);

	return 1;
}













