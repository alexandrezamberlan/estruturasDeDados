#include <stdio.h>
#include <stdlib.h>

typedef struct  {
	int **matrizAdj;
	int qtdVertices;
	int qtdArcos;
} Grafo;

/**
 * Definicao do tipo para celula/no/nodo/elemento da fila
 */
typedef struct cel {
  int conteudo;
  struct cel *prox;
} Celula;

/**
 * Definicao do tipo para fila com dois ponteiros (inicio e fim)
 */
typedef struct estruturaFila {
  Celula *inicio;
  Celula *fim;
} Fila;

/*
 * procedimento que recebe o endereco de uma fila e inicializa inicio (cabeca) e fim (cauda)
 **/
void inicializarFila(Fila *fila) {
  fila->inicio = NULL;
  fila->fim = NULL;
}

/**
 * procedimento que recebe o endereco de uma fila e um nome
 * insere o nome na referencia da fila passada como parametro
 */
void incluirFila(int no, Fila *fila) {
  Celula *nova;
  nova = (Celula *) malloc (sizeof (Celula)); //aloca dinamicamente
  nova->conteudo = no;
  nova->prox = NULL;

  //verifica se fila vazia
  if (fila->inicio == NULL) { //ou if (!fila->inicio) {}
    //tanto inicio (cabeca) e fim (cauda) da fila apontam para a nova celula
    fila->inicio = nova;
    fila->fim = nova;
  } else {
    //fila nao vazia
    fila->fim->prox = nova;
    fila->fim = nova;
  }
}

/**
 * funcao que recebe o endereco de uma fila
 * e remove o elemento mais antigo, ou seja no inicio, retornando o elemento do
 * inicio
 */
int excluirFila(Fila *fila) {
  Celula *lixo;
  int no;

  if (fila->inicio) {
    no = fila->inicio->conteudo;
		//verifica se hah mais de um elemento na fila
		if (fila->inicio->prox != NULL) { //ou if (fila->inicio->prox) {}
			lixo = fila->inicio;
			fila->inicio = fila->inicio->prox;
			free(lixo);
		} else {
			//somente um elemento
			fila->inicio = NULL;
			fila->fim = NULL;
		}
		return no;
	} else return -1;
}

int percorreR(Grafo *g, int no, int nodoDestino, int visitados[]) {
  int i;
  visitados[no] = 1;
  for (i = 0; i < g->qtdVertices; i++) {
    if (g->matrizAdj[no][i] && !visitados[i]) {
        if (i == nodoDestino) return 1;//printf("%d ", i); //usar o nodo
        return percorreR(g, i, nodoDestino, visitados);
    }
  }
  return 0;
}

int temCaminhoProfundidade(Grafo *g, int nodoOrigem, int nodoDestino) {
  int visitados[g->qtdVertices], no;
  if (nodoOrigem < 0 || nodoOrigem >= g->qtdVertices) {
    printf("\nNodo de partida invalido!!\n");
    return 0;
  }
  if (nodoDestino < 0 || nodoDestino >= g->qtdVertices) {
    printf("\nNodo de chegada invalido!!\n");
    return 0;
  }

  for (no = 0; no < g->qtdVertices; no++)
	  visitados[no] = 0;

  return percorreR(g, nodoOrigem, nodoDestino, visitados);
}


int temCaminhoAmplitude(Grafo *g, int nodoOrigem, int nodoDestino) {
  int no, i;
  Fila f;
  int visitados[g->qtdVertices];

  if (nodoOrigem < 0 || nodoOrigem >= g->qtdVertices) {
    printf("\nNodo de partida invalido!!\n");
    return 0;
  }
  if (nodoDestino < 0 || nodoDestino >= g->qtdVertices) {
    printf("\nNodo de chegada invalido!!\n");
    return 0;
  }
  inicializarFila(&f);
  for (no = 0; no < g->qtdVertices; no++)
	  visitados[no] = 0;
  no = nodoOrigem;
  visitados[no] = 1; //marca nodo como visitado

  while (no != -1) { //enquanto houver nodo na fila
  	if (no == nodoDestino) return 1;//printf("%d ", no); //usa nodo
    for (i = 0; i < g->qtdVertices; i++) {
      if (g->matrizAdj[no][i] && !visitados[i]) {
        visitados[i] = 1; //marca nodo como visitado
        incluirFila(i, &f);
      }
  	}
	no = excluirFila(&f);	
  }
  return 0;
}


int contaPercursoAmplitude(Grafo *g, int nodoOrigem) {
  int no, i, cont = 0;
  Fila f;
  int visitados[g->qtdVertices];

  if (nodoOrigem < 0 || nodoOrigem >= g->qtdVertices) {
    printf("\nNodo de partida invalido!!\n");
    return 0;
  }
  inicializarFila(&f);
  for (no = 0; no < g->qtdVertices; no++)
    visitados[no] = 0;

  no = nodoOrigem;
  visitados[no] = 1; //marca nodo como visitado
  

  while (no != -1) { //enquanto houver nodo na fila
    printf("%d ", no); 
    cont++;//usa nodo
    for (i = 0; i < g->qtdVertices; i++) {
      if (g->matrizAdj[no][i] && !visitados[i]) {
        visitados[i] = 1; //marca nodo como visitado
        incluirFila(i, &f);
      }
    }
  no = excluirFila(&f); 
  }
  return cont;
}

void percursoAmplitude(Grafo *g, int nodoOrigem) {
  int no, i;
  Fila f;
  int visitados[g->qtdVertices];

  if (nodoOrigem < 0 || nodoOrigem >= g->qtdVertices) {
    printf("\nNodo de partida invalido!!\n");
    return;
  }
  inicializarFila(&f);
  for (no = 0; no < g->qtdVertices; no++)
	  visitados[no] = 0;

  no = nodoOrigem;
  visitados[no] = 1; //marca nodo como visitado
  

  while (no != -1) { //enquanto houver nodo na fila
  	printf("%d ", no); //usa nodo
    for (i = 0; i < g->qtdVertices; i++) {
      if (g->matrizAdj[no][i] && !visitados[i]) {
        visitados[i] = 1; //marca nodo como visitado
        incluirFila(i, &f);
      }
  	}
	no = excluirFila(&f);	
  }
}

void caminhoR(Grafo *g, int no, int visitados[]) {
  int i;
  visitados[no] = 1;
  for (i = 0; i < g->qtdVertices; i++) {
    if (g->matrizAdj[no][i] && !visitados[i]) {
        printf("%d ", i); //usar o nodo
        caminhoR(g, i, visitados);
    }
   }
}

void percursoProfundidade(Grafo *g, int nodoOrigem) {
  int visitados[g->qtdVertices], no;
  if (nodoOrigem < 0 || nodoOrigem >= g->qtdVertices) {
    printf("\nNodo de partida invalido!!\n");
    return;
  }
  for (no = 0; no < g->qtdVertices; no++)
	  visitados[no] = 0;
  printf("%d ", nodoOrigem);
  caminhoR(g, nodoOrigem, visitados);
}

/**
  * metodo que cria dinamicamente uma matriz de inteiros
  * recebe o total de vertices e cria a quantidade de linhas e
  * colunas conforme o total de vertices
  * ao final, retorna o endereco da matriz construida
	*/
int **criaMatriz(int totalVertices, int valorInicial) {
	int **m;
	int i,j;

	m = malloc(totalVertices * sizeof(int *));
	for (i = 0; i < totalVertices; i++)
		m[i] = malloc(totalVertices * sizeof(int));

	for (i = 0; i < totalVertices; i++)
		for (j = 0; j < totalVertices; j++)
			m[i][j] = valorInicial;

	return m;
}

/**
  * metodo que inicializa um grafo.
  * recebe o total de vertices para criar a matrizAdj
  * recebe o valor inicial da matrizAdj
  */
Grafo *inicializaGrafo(int totalVertices, int valorInicial) {
	Grafo *g = (Grafo *)malloc(sizeof(Grafo));

	//criar dinamicamente a matrizAdj
	g->matrizAdj = criaMatriz(totalVertices, valorInicial);

	g->qtdVertices = totalVertices;
	g->qtdArcos = 0;

	return g;
}

/**
  * metodo que exibe a matrizAdj de um grafo
  * recebe um grafo como parametro
  */
void exibeGrafo(Grafo *g) {
	int i, j;

	for (i = 0; i < g->qtdVertices; i++) {
		printf("%d: ",i);
		for (j = 0; j < g->qtdVertices; j++)
			if (g->matrizAdj[i][j])
			  printf("%d  ", j);

		printf("\n");
	}
}
/**
  * metodo que recebe um vertice de origem, vertice de destino
  * e o grafo em que o arco sera criado
  * fazendo a conexao na matrizAdj da origem com destino
  */
void insereArcoGrafo(int origem, int destino, Grafo *g) {
	if (origem != destino && !g->matrizAdj[origem][destino]) {
		g->matrizAdj[origem][destino] = 1;
		g->qtdArcos++;
	}
}

/**
  * metodo que recebe um vertice de origem, vertice de destino
  * e o grafo em que o arco sera criado
  * fazendo a conexao da origem com destino e vice-versa
  */
void insereArcoGrafoSimetrico(int origem, int destino, Grafo *g) {
	if (!g->matrizAdj[origem][destino]) {
		g->matrizAdj[origem][destino] = 1;
		g->qtdArcos++;

		g->matrizAdj[destino][origem] = 1;
		g->qtdArcos++;
	}
}

int ehSimetrico(Grafo *g) {
	int i, j;

	for (i = 0; i < g->qtdVertices; i++)
		for (j= 0; j < g->qtdVertices; j++)
			if (g->matrizAdj[i][j] && !g->matrizAdj[j][i])
				return 0; //nao eh simetrico

	return 1; //eh simetrico
}

int main(){
	int nodoOrigem, nodoDestino;
	Grafo *grafo = NULL;
	int totalVertices = 5;

	grafo = inicializaGrafo(totalVertices, 0);

	insereArcoGrafo(0,1,grafo);
	insereArcoGrafo(0,3,grafo);
	insereArcoGrafo(1,4,grafo);
	insereArcoGrafo(2,3,grafo);
	insereArcoGrafo(4,0,grafo);
	insereArcoGrafo(4,3,grafo);
	
	exibeGrafo(grafo);

/*	if (ehSimetrico(grafo))
		printf("\nO grafo eh simetrico\n");
	else printf("\nO grafo NAO eh simetrico\n");
*/
	printf("Caminho AMPLITUDE no grafo a partir do nodo 0: ");
	printf("\n%d\n",contaPercursoAmplitude(grafo, 0));

  printf("\n");

	printf("Caminho PROFUNDIDADE no grafo a partir do nodo 0: ");
	percursoProfundidade(grafo, 0);
	printf("\n\n");

	printf("Informe no de origem: ");
	scanf("%d", &nodoOrigem);
	printf("Informe no de destino: ");
	scanf("%d", &nodoDestino);
	if (temCaminhoAmplitude(grafo,nodoOrigem,nodoDestino)) {
		printf("Tem caminho AMPLITUDE entre %d e %d\n", nodoOrigem, nodoDestino);
	} else printf("Nao tem caminho AMPLITUDE entre %d e %d\n", nodoOrigem, nodoDestino);

	printf("\n");

	printf("Informe no de origem: ");
	scanf("%d", &nodoOrigem);
	printf("Informe no de destino: ");
	scanf("%d", &nodoDestino);
	if (temCaminhoProfundidade(grafo,nodoOrigem,nodoDestino)) {
		printf("Tem caminho PROFUNDIDADE entre %d e %d\n", nodoOrigem, nodoDestino);
	} else printf("Nao tem caminho PROFUNDIDADE entre %d e %d\n", nodoOrigem, nodoDestino);

	printf("\n");

  return 0;
}

