#include <stdio.h>
#include <stdlib.h>

void mostraNumeros(valor) {
	int i = 0;

	while (i <= valor)
		printf("%d\t", i++);
	printf("\n");
}

int mostraNumerosR(valor) {
	if (valor == 0) {
		printf("%d\t", valor);
		return valor;
	}
	else mostraNumerosR( valor - 1 );
	printf("%d\t", valor);
}

int main(){
	int valor;

	//system("cls");
	printf("Digite valor inteiro: ");
	scanf("%d", &valor);

	printf("Versao iterativa\n");
	mostraNumeros( valor );

	printf("Versao recursiva\n");
	mostraNumerosR( valor );

	return 0;
}
