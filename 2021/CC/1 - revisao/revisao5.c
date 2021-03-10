/**
 * Programa que armazena alunos (matricula, nome e sexo) em um vetor
 */ 

#include <stdio.h> //printf, scanf, gets, getc, puts, putc
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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

int main() {
    Aluno vetor[TAMANHO];
    Aluno umAluno;
    int mat;


    printf("Digite matricula: ");
    scanf("%d", &umAluno.matricula);
    fflush(stdin);
    
    printf("Digite seu nome: ");
    gets(umAluno.nome);
    fflush(stdin);

    paraMaiusculo(umAluno.nome); //passagem de parametro por referencia, pois nome é um vetor e todo vetor é um ponteiro

    printf("Digite M se masculino ou F se feminino: ");
    scanf("%c", &umAluno.sexo);
    fflush(stdin);
    umAluno.sexo = toupper(umAluno.sexo);

    printf("%d - %s - %c\n", umAluno.matricula, umAluno.nome, umAluno.sexo);

    return 1;
}
