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

void exibirR(int *vetor, int n) {
    if (n > 0) {
        exibirR(vetor, n - 1);
        printf("%d\t", vetor[n - 1]);
    }
}

int somarR(int *vetor, int n) {
    if (n > 0) {
        return vetor[n - 1] + somarR(vetor, n - 1);
    }
    return 0;
}

int maiorR(int *vetor, int n) {
    if (n > 1) {
        int oQueVemDeCima = maiorR(vetor, n - 1);
        if (oQueVemDeCima > vetor[n -1])
            return oQueVemDeCima;
        return vetor[n - 1];
    }
    return vetor[n - 1];
}


//6 * 5 * 4 * 3 * 2
double fatorialR(int numero) { //ponto A - inicialização da variável de controle
    if (numero > 1) {          //ponto B - teste de parada com a variável de controle
        return numero * fatorialR(numero - 1); //ponto C - ponto de recursão com a transformação da variável de controle
    }
    return 1;
}

void fibonacciR(int pen, int ult, int n) {
    if (n > 0) {

    }
}

int main(){
    // int vetor[4] = {5,1,450,89};
    // exibirR(vetor,4);
    // printf("A soma dos elementos do vetor é: %d\n", somarR(vetor, 4));

    // printf("Maior valor do vetor: %d\n", maiorR(vetor, 4));
    
    // int ini, fim;
    // printf("Digite um valor inicial: ");
    // scanf("%d",&ini);

    // printf("Digite um valor final: ");
    // scanf("%d",&fim);
    // //exibirSequencia(ini);
    // //exibirSequenciaInvertida(ini);
    // //exibirSequenciaInvertidaR(ini);
    // exibirFaixaR(ini,fim);

    // printf("A quantidade de elementos na faixa é: %d\n", contarFaixaR(5,9));
    // printf("A soma de elementos na faixa é: %d\n", somarFaixaR(5,9));

    int numero;
    printf("Insira número para descobrir fatorial: ");
    scanf("%d", &numero);
    printf("Fatorial de %d é %.0f\n", numero, fatorialR(numero));

    //fibonacciR(0,1,5);

    return 1;
}
