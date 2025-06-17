
typedef struct {
    int **matriz;
    int qtdVertices;
    int qtdArestas;
} Grafo;

Grafo *inicializar(int vertices) { //"construtor" do grafo
	int i, j;

	Grafo *g = (Grafo *)malloc(sizeof(Grafo)); //alocando o grafo

	g->qtdVertices = vertices;
	g->qtdArestas = 0;

	g->matriz = malloc(vertices * sizeof(int *)); //alocando as linhas

	for (i = 0; i < g->qtdVertices; i++)
		g->matriz[i] = malloc(vertices * sizeof(int)); //para cada linha, as colunas sao alocadas

    //passando pela matriz adjacente e a zerando
	for (i = 0; i < g->qtdVertices; i++)
		for (j = 0; j < g->qtdVertices; j++)
			g->matriz[i][j] = 0;

	return g;
}

void inserirAresta(int origem, int destino, Grafo *g) {
    if (origem < 0 || origem >= g->qtdVertices || destino < 0 || destino >= g->qtdVertices) {
        printf("Erro: Vertices invalidos.\n");
        return; // Verifica se os vertices sao validos
    }
    if (g->matriz[origem][destino] == 0) {
        g->matriz[origem][destino] = 1; //inserindo a aresta na matriz
        g->qtdArestas++; //incrementando a quantidade de arestas
    }
}

void inserirArestaSimetrica(int origem, int destino, Grafo *g) {
    if (origem < 0 || origem >= g->qtdVertices || destino < 0 || destino >= g->qtdVertices) {
        printf("Erro: Vertices invalidos.\n");
        return; // Verifica se os vertices sao validos
    }
    if (g->matriz[origem][destino] == 0) {
        g->matriz[origem][destino] = 1; //inserindo a aresta na matriz
        g->matriz[destino][origem] = 1; //inserindo a aresta na matriz
        g->qtdArestas+=2; //incrementando a quantidade de arestas
    }
}

void exibir(Grafo *g) {
    if (!g) {
		printf("Grafo nao existe\n");
	} else {
		int i,j;
		for (i = 0; i < g->qtdVertices;i++) {
			printf("%d: ", i);
			for (j = 0; j < g->qtdVertices; j++) {
				if (g->matriz[i][j] != 0)
					printf("%d   ", j);
			}
			printf("\n");
		}
	}
    printf("Quantidade de Arestas: %d\n", g->qtdArestas);
}

