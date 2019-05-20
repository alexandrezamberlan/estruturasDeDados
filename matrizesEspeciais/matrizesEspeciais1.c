#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * metodo que recebe ponteiro de ponteiro de inteiro, quantidade de linhas e quantidade de colunas
 * e monta dinamicamente uma matriz baseada nessas quantidade de linhas e colunas
 * ao final, a matriz gerada eh retornada
 */
int *montarDinamicamenteMatriz(int **m, int linhas, int colunas) {
	int i;

	m = malloc(linhas * sizeof(int *));
	for (i = 0; i < linhas; i++)
		m[i] = malloc(colunas * sizeof(int));

	return m;
}

/**
 * metodo que recebe uma matriz de inteiros, quantidade de linhas e colunas
 * e popula essa matriz com zeros
 */
void zerarMatriz(int **m, int linhas, int colunas) {
	int i,j;
	for (i = 0; i < linhas; i++)
		for (j = 0; j < colunas; j++)
			m[i][j] = 0;

}

/**
 * metodo que recebe uma matriz de inteiros, quantidade de linhas e colunas
 * e exibe o conteudo dessa matriz linha por coluna
 */
void exibirMatriz(int **m, int linhas, int colunas) {
	int i,j;

	for (i = 0; i < linhas; i++) {
		for (j = 0; j < colunas; j++)
			printf("%d\t", m[i][j]);
		printf("\n");
	}
	printf("\n\n");
}

void gerarDiagonalPrincipal(int **m, int linhas) {
	int i;

	srand(time(NULL));
	for (i = 0; i < linhas; i++)
		m[i][i] = rand() % 100;
}

void gerarDiagonalSecundaria(int **m, int linhas, int colunas) {
	int i, j;

	srand(time(NULL));
	for (i = 0, j = colunas - 1; i < linhas; i++, j--)
		m[i][j] = rand() % 100;
}

void gerarTriangularSuperiorPrincipal(int **m, int linhas, int colunas) {
	int i, j;

	srand(time(NULL));
	for (i = 0; i < linhas; i++)
		for (j = i+1; j < colunas; j++)
			m[i][j] = rand() % 100;
}

void gerarTriangularSuperiorSecundaria(int **m, int linhas, int colunas) {
	int i, j;

	srand(time(NULL));
	for (i = 0; i < linhas - 1; i++)
		for (j = 0; j < colunas - 1 - i; j++)
			m[i][j] = rand() % 100;
}

void gerarTriangularInferiorPrincipal(int **m, int linhas, int colunas) {
	int i, j;

	srand(time(NULL));
	for (i = 1; i < linhas; i++)
		for (j = 0; j < i; j++)
			m[i][j] = rand() % 100;
}

void gerarTriangularInferiorSecundaria(int **m, int linhas, int colunas) {
	int i, j;

	srand(time(NULL));
	for (i = 1; i < linhas; i++)
		for (j = colunas - i; j < colunas; j++)
			m[i][j] = rand() % 100;
}

int main() {
	int **matriz;
	int qtdLinhas, qtdColunas, i;

	printf("Qual dimensao da matriz: ");
	scanf("%d", &qtdLinhas);
	qtdColunas = qtdLinhas;

	matriz = montarDinamicamenteMatriz(matriz, qtdLinhas, qtdColunas);
	zerarMatriz(matriz, qtdLinhas, qtdColunas);
	exibirMatriz(matriz, qtdLinhas, qtdColunas);

	gerarDiagonalPrincipal(matriz, qtdLinhas);
	exibirMatriz(matriz, qtdLinhas, qtdColunas);

	zerarMatriz(matriz, qtdLinhas, qtdColunas);
	gerarDiagonalSecundaria(matriz, qtdLinhas, qtdColunas);
	exibirMatriz(matriz, qtdLinhas, qtdColunas);

	zerarMatriz(matriz, qtdLinhas, qtdColunas);
	gerarTriangularSuperiorPrincipal(matriz, qtdLinhas, qtdColunas);
	exibirMatriz(matriz, qtdLinhas, qtdColunas);

	zerarMatriz(matriz, qtdLinhas, qtdColunas);
	gerarTriangularSuperiorSecundaria(matriz, qtdLinhas, qtdColunas);
	exibirMatriz(matriz, qtdLinhas, qtdColunas);

	zerarMatriz(matriz, qtdLinhas, qtdColunas);
	gerarTriangularInferiorPrincipal(matriz, qtdLinhas, qtdColunas);
	exibirMatriz(matriz, qtdLinhas, qtdColunas);

	zerarMatriz(matriz, qtdLinhas, qtdColunas);
	gerarTriangularInferiorSecundaria(matriz, qtdLinhas, qtdColunas);
	exibirMatriz(matriz, qtdLinhas, qtdColunas);

	return 1;
}
