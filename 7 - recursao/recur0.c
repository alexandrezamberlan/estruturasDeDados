#include <stdio.h>
#include <stdlib.h>



void exibirSequencia(int valor) {
    int i;
    for (i = 0; i <= valor; i++) {
        printf("%d\t",i);
    }
    printf("\n");
}

void exibirSequenciaR(int valor) {
    if (valor >= 0){
        exibirSequenciaR(valor - 1);
        printf("%d\t",valor);
    }
}

void exibirSequenciaInvertida(int valor) {
    for (; valor >= 0; valor--) {
        printf("%d\t",valor);
    }
    printf("\n");
}

void exibirSequenciaInvertidaR(int valor) { //inicializacao da variavel de controle no parametro
    if (valor >= 0) { //teste de parada com a variável de controle
        //códigos executados no empilhamento
        printf("%d\t",valor);
        exibirSequenciaInvertidaR(valor - 1); //ponto de recursao onde a varia'vel de controle é transformada
        //códigos executados no desempilhamento
    } 
}

void exibirFaixa(int ini, int fim) {
    for (; ini <= fim; ini++) {
        printf("%d\t", ini);
    }
}

void exibirFaixaR(int ini, int fim) {
    if (ini <= fim) {
        printf("%d\t", ini);
        exibirFaixaR(ini+1, fim);
    }
}


int main(){
	int ini, fim;
    printf("Digite um valor inicial: ");
    scanf("%d",&ini);

    printf("Digite um valor final: ");
    scanf("%d",&fim);
    //exibirSequencia(ini);
    //exibirSequenciaInvertida(ini);
    //exibirSequenciaInvertidaR(ini);


    exibirFaixaR(ini,fim);
	return 1;
}
