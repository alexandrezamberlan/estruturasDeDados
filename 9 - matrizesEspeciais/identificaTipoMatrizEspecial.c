#include <....>
#define TAM 100

int ehDiagonalPrincipal(int m[TAM][]) {
	int i,j;
	for (i = 0; i < TAM; i++) {
		for (j = 0; j < TAM; j++) {
			//procurando pelo erro
			if ( (i == j && m[i][j] == 0) ||
			     (i != j && m[i][j] != 0) )
				return 0; //nao eh 
		}
	}
	return 1; //se chegou aqui, pq eh
}

int ehDiagonalSecundaria(int m[TAM][]) {
	int i,j;
	for (i = 0; i < TAM; i++) {
		for (j = 0; j < TAM; j++) {
			//procurando pelo erro
			if ( ((i + j == TAM - 1) && m[i][j] == 0) ||
			     ((i + j != TAM - 1) && m[i][j] != 0) )
				return 0; //nao eh 
		}
	}
	return 1; //se chegou aqui, pq eh
}

int ehTriangularSuperiorPrincipal(int m[TAM][]) {
	int i,j;
	for (i = 0; i < TAM; i++) {
		for (j = 0; j < TAM; j++) {
			//procurando pelo erro
			if ( (j > i && m[i][j] == 0) ||
			     (j <= i && m[i][j] != 0) )
				return 0; //nao eh 
		}
	}
	return 1; //se chegou aqui, pq eh
}

int ehTriangularInferiorPrincipal(int m[TAM][]) {
	int i,j;
	for (i = 0; i < TAM; i++) {
		for (j = 0; j < TAM; j++) {
			//procurando pelo erro
			if ( (i > j && m[i][j] == 0) ||
			     (i <= j && m[i][j] != 0) )
				return 0; //nao eh 
		}
	}
	return 1; //se chegou aqui, pq eh
}

int ehTriangularSuperiorSecundaria(int m[TAM][]) {
	int i,j;
	for (i = 0; i < TAM; i++) {
		for (j = 0; j < TAM; j++) {
			//procurando pelo erro
			if ( ((i + j < TAM - 1) && m[i][j] == 0) ||
			     ((i + j >= TAM - 1) && m[i][j] != 0) )
				return 0; //nao eh 
		}
	}
	return 1; //se chegou aqui, pq eh
}

int ehTriangularInferiorSecundaria(int m[TAM][]) {
	int i,j;
	for (i = 0; i < TAM; i++) {
		for (j = 0; j < TAM; j++) {
			//procurando pelo erro
			if ( ((i + j > TAM - 1) && m[i][j] == 0) ||
			     ((i + j <= TAM - 1) && m[i][j] != 0) )
				return 0; //nao eh 
		}
	}
	return 1; //se chegou aqui, pq eh
}

int ehEsparsa(int m[TAM][]) {
	//TESTA TODAS AS POSSIBILIDADES ANTERIORES
	
	int i,j;
	int qtdNaoNulos = 0;
	for (i = 0; i < TAM; i++) {
		for (j = 0; j < TAM; j++) {
			if (m[i][j] != 0) qtdNaoNulos++;
		}
	}
	if (qtdNaoNulos > TAM * TAM / 2) return 0;//maioria eh nao nula
	return 1;//maioria das celulas eh nula/vazia
}