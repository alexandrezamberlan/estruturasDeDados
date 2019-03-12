#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int matricula;
	char nome[200];
}Aluno;

int main() {
	Aluno *vetor;
	int qtdElementos;
	
	printf("Quantos alunos pretende cadastrar? ");
	scanf("%d",&qtdElementos);
	
	vetor = malloc(sizeof(Aluno) * qtdElementos);
	
	return 1;
}
