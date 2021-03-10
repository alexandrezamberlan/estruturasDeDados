#include <stdio.h>
#include <stdlib.h>

//método iterativo
void mostraNumeros(valor) { 

	for (int i = 0; i <= valor; i++){
		printf("%d\t", i); 
	}
	printf("\n");
}


//método recursivo
void mostraNumerosR(valor) { //Ponto A - inicialização da variável se dá no parâmetro
	if (valor >= 0) { //ponto B
		//códigos executados no empilhamento
		mostraNumerosR( valor - 1 ); //ponto de recursão com o Ponto C - transformação da var. de controle
		//códigos executados no desempilhamento
		printf("%d\t", valor);
	}
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
