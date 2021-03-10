/**
 * Programa que armazena alunos (matricula, nome e sexo) em um vetor
 */ 

#include <stdio.h> //printf, scanf, gets, getc, puts, putc
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define TAMANHO 5 //constante defina pelo programador

typedef struct {
    int matricula;
    char nome[100];
    char sexo; // M ou F
} Aluno; //tipo criado pelo programador, chamado Aluno

void paraMaiusculo(char frase[]) { //toda matriz/vetor é um ponteiro
    int i;
    for (i = 0; i < strlen(frase); i++) {
        frase[i] = toupper(frase[i]);
    }
}

void popularVetor(Aluno *vetor, int n) {
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        vetor[i].matricula = rand() % 1000;
        
        printf("Digite seu nome: ");
        gets(vetor[i].nome);
        fflush(stdin);

        paraMaiusculo(vetor[i].nome); //passagem de parametro por referencia, pois nome é um vetor e todo vetor é um ponteiro

        printf("Digite M se masculino ou F se feminino: ");
        scanf("%c", &vetor[i].sexo);
        fflush(stdin);
        vetor[i].sexo = toupper(vetor[i].sexo);
    }
}

void exibirVetor(Aluno *vetor, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d - %s - %c\n", vetor[i].matricula, vetor[i].nome, vetor[i].sexo);
    }
}

void ordenarVetor(Aluno *vetor, int n) { //método da bolha - Bubble Sort
    int houveTroca; //0 indica que não teve troca, 1 indica que teve troca
    Aluno tmp;
    int i;

    do {
        houveTroca = 0;
        for (i = 0; i < n-1; i++) {
            if (vetor[i].matricula > vetor[i+1].matricula) {
                houveTroca = 1;
                tmp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = tmp;
            }
        }
    } while (houveTroca);
}

int main() {
    Aluno vetor[TAMANHO];

    system("clear");
    popularVetor(vetor, TAMANHO);
    ordenarVetor(vetor, TAMANHO);
    exibirVetor(vetor, TAMANHO);

    return 1;
}
