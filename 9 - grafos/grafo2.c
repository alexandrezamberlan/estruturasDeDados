#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
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

int grauVertice(int vertice, Grafo *g) {
    if (!g) return 0; //grafo vazio, logo não existe
    int i;
    int conta = 0;
    for (i = 0; i < g->qtdVertices; i++) {
        if (g->matrizAdj[vertice][i] != 0) conta++;
        if (g->matrizAdj[i][vertice] != 0) conta++;
    }
    return conta;
}

int ehSimetrico(Grafo *g) {
    if (!g) return -27; //código de erro
    int i, j;

    for (i = 0; i < g->qtdVertices; i++) {
        for (j = i; j < g->qtdVertices; j++) { //analise somente a parte de cima da diagonal principal
            if (g->matrizAdj[i][j] != g->matrizAdj[j][i])
                return 0; //não é simétrico
        }
    }
    return 1; //é simétrico
}

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
	printf("grafo é simétrico? %d\n", ehSimetrico(grafo));

	
    // printf("O grau do vértice 2 é: %d\n\n", grauVertice(2,grafo));

	grafo1 = inicializarGrafo(3); //'construtor' do grafo
	inserirGrafoSimetrico(0,1,grafo1);
	inserirGrafoSimetrico(1,2,grafo1);
	inserirGrafoSimetrico(2,0,grafo1);
	printf("\n");
	exibirGrafo(grafo1);

    printf("grafo é simétrico? %d\n", ehSimetrico(grafo1));

	return 0;
}













