#include <stdio.h>
#include <stdlib.h>

void exibirCrescente(int valor) {
    int i;
    for (i = 1; i <= valor; i++) {
        printf("%d\n", i);
    }
}

void exibirCrescenteR(int valor) {
    if (valor > 0) {
        exibirCrescenteR(valor - 1); //ponto de recursão com a transformação da variável de controle
        printf("%d\n", valor); //código executado no desempilhamento, para poder exibir crescente
    }
}

void exibirDecrescente(int valor) {
    for (; valor > 0; valor--) {
        printf("%d\n", valor);
    }
}

void exibirDecrescenteR(int valor) {
    if (valor > 0) {
        printf("%d\n", valor); //código executado no empilhamento, para poder exibir decrescente
        exibirDecrescenteR(valor - 1); //ponto de recursão com a transformação da variável de controle
    }
}

int main() {
    int valor;
    printf("Digite um inteiro: ");
    scanf("%d", &valor);

    // exibirCrescente(valor);
    exibirCrescenteR(valor);
    
    //exibirDecrescente(valor);
    //exibirDecrescenteR(valor);

    return 1;
}