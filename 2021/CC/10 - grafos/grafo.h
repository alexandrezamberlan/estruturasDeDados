#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fila.h" 

typedef struct {
	int **matrizAdj;
	int qtdVertices; //qtdNos ou qtdNodos
	int qtdArestas;
} Grafo;

Grafo *inicializarGrafo(int vertices) { //"construtor" do grafo
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

void inserirGrafoSimetricoValorado(int origem, int destino, Grafo *g, int valor) {
	if (origem < 0 || origem >= g->qtdVertices || destino < 0 ||
		destino >= g->qtdVertices || g->matrizAdj[origem][destino] != 0 ||
		origem == destino) {
		printf("Aresta nao cadastrada\n");
	} else {
		g->matrizAdj[origem][destino] = valor;
		g->matrizAdj[destino][origem] = valor;
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
    if (!g) return 0;
    int i;
    int conta = 0;
    for (i = 0; i < g->qtdVertices; i++) {
        if (g->matrizAdj[vertice][i] != 0) conta++;
        if (g->matrizAdj[i][vertice] != 0) conta++;
    }
    return conta;
}

int ehSimetrico(Grafo *g) {
    if (!g) return -27;
    int i, j;

    for (i = 0; i < g->qtdVertices; i++) {
        for (j = i; j < g->qtdVertices; j++) {
            if (g->matrizAdj[i][j] != g->matrizAdj[j][i])
                return 0;
        }
    }
    return 1;
}

int temCaminhoAmplitude(Grafo *g, int origem, int destino) {
	int i, no;
	Fila fila;
	inicializarFila(&fila);

	int *visitados;
	visitados = malloc(sizeof(int) * g->qtdVertices);
	for (i = 0; i < g->qtdVertices; i++){
		visitados[i] = 0;
	}
	int conta = 0;
	visitados[origem] = 1;
	no = origem;
	do {
		//usar o vertice - print, if, cont, ...
		conta++;
		printf("%d\t", no);
		if (no == destino) return 1;

		for (i = 0; i < g->qtdVertices; i++) {
			if (g->matrizAdj[no][i] != 0 && !visitados[i]) {
				visitados[i] = 1;
				inserirFila(i, &fila);
			}
		}
		no = removerFila(&fila);

	} while (no != -1);
	printf("\nTotal de vértices visitados: %d\n\n", conta);
	return 0; //nao tem caminho
}

void percorreAmplitude(Grafo *g, int origem) {
	int i, no;
	Fila fila;
	inicializarFila(&fila);

	int *visitados;
	visitados = malloc(sizeof(int) * g->qtdVertices);
	for (i = 0; i < g->qtdVertices; i++){
		visitados[i] = 0;
	}
	int conta = 0;
	visitados[origem] = 1;
	no = origem;
	do {
		//usar o vertice - print, if, cont, ...
		conta++;
		printf("%d\t", no);

		for (i = 0; i < g->qtdVertices; i++) {
			if (g->matrizAdj[no][i] != 0 && !visitados[i]) {
				visitados[i] = 1;
				inserirFila(i, &fila);
			}
		}
		no = removerFila(&fila);

	} while (no != -1);
	printf("\nTotal de vértices visitados: %d\n\n", conta);
}

void profundidadeR(Grafo *g, int no, int *visitados) {
	int i;
	//usar o vértice no - printf, if, cont
	printf("%d\t", no);
	for (i = 0; i < g->qtdVertices; i++) {
		if (g->matrizAdj[no][i] != 0 && !visitados[i]) {
			visitados[i] = 1;
			profundidadeR(g, i, visitados); //chamada recursiva, ou seja é aqui que o nodo visitado é inserido na pilha
		}
	}
}

void percorreProfundidade(Grafo *g, int origem) {
	int i, no;
	
	int *visitados;
	visitados = malloc(sizeof(int) * g->qtdVertices);
	for (i = 0; i < g->qtdVertices; i++){
		visitados[i] = 0;
	}
	no = origem;
	visitados[no] = 1;
	profundidadeR(g, no, visitados); //chama a pilha recursiva do SO
	printf("\n");
}

int profundidadeR2(Grafo *g, int no, int destino, int *visitados) {
	int i;
	//usar o vértice no - printf, if, cont
	printf("%d\t", no);
	if (no == destino) return 1; //localizei um caminho
	
	for (i = 0; i < g->qtdVertices; i++) {
		if (g->matrizAdj[no][i] != 0 && !visitados[i]) {
			visitados[i] = 1;
			return profundidadeR2(g, i, destino, visitados); //chamada recursiva, ou seja é aqui que o nodo visitado é inserido na pilha
		}
	}
	return 0; //destino não encontrado
}

int temCaminhoProfundidade(Grafo *g, int origem, int destino) {
	int i, no;
	
	int *visitados;
	visitados = malloc(sizeof(int) * g->qtdVertices);
	for (i = 0; i < g->qtdVertices; i++){
		visitados[i] = 0;
	}
	no = origem;
	visitados[no] = 1;
	return profundidadeR2(g, origem, destino, visitados); //chama a pilha recursiva do SO
} 