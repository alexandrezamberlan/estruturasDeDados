#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int matricula;
	char nome[200];
}Aluno;

void popula(Aluno *vetor, int qtdElementos);
void exibe(Aluno *vetor, int qtdElementos);

int main() {
	Aluno *vetor;
	int qtdElementos;
	
	printf("Quantos alunos pretende cadastrar? ");
	scanf("%d",&qtdElementos);
	
	
	//alocacao dinamica
	vetor = malloc(sizeof(Aluno) * qtdElementos);
	
	popula(vetor, qtdElementos);
	printf("\n\n");
	exibe(vetor, qtdElementos);
	
	//desalocacao dinamicamente
	free(vetor);
	return 1;
}

void popula(Aluno *vetor, int qtdElementos) {
	srand(time(NULL));
	for (; qtdElementos > 0; qtdElementos--) {
		printf("\nDigite nome do aluno: ");
		scanf("%s", vetor[qtdElementos - 1].nome);
		
		vetor[qtdElementos-1].matricula = rand() % 1000;
		printf("Sua matricula eh %d\n", vetor[qtdElementos-1].matricula);
	}
}

void exibe(Aluno *vetor, int qtdElementos) {
	printf("Lista de alunos.....\n");
	for (; qtdElementos > 0; qtdElementos--) {
		printf("Matricula %d -> Nome: %s\n", vetor[qtdElementos-1].matricula,
		                                     vetor[qtdElementos-1].nome);		
	}
}
