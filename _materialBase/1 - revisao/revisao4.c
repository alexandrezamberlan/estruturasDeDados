/*
Fazer um sistema modularizado que cadastre alunos com matrícula
e nome.
Entretanto, o módulo responsável pelo cadastro não pode permitir
duas matrículas iguais no vetor.
O tamanho do vetor deve ser definido pelo usuário.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[200];
} Aluno;

Aluno *alocarMemoria(int n) {
    Aluno *v = malloc(sizeof(Aluno) * n);
    int i;

    //inicializei o vetor com valores nulos
    for (i = 0; i < n; i++) {
        v[i].matricula = 0;
        strcpy(v[i].nome," ");
    }

    return v;
}

void exibir(Aluno v[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("Matricula: %d\n", v[i].matricula);
        printf("Nome     : %s\n", v[i].nome);
        printf("--------------\n");
    }
}

int existeMatricula(int matriculaPesquisa, Aluno v[], int n) {
    int i;

    for (i = 0; i < n && v[i].matricula != 0; i++) {
        if (matriculaPesquisa == v[i].matricula) {
            return 1; //matricula localizada
        }
    }
    return 0; //matricula nao localizada
}

void popular(Aluno v[], int n) {
    int matriculaPesquisa;
    int i = 0;
    do {
        do {
            printf("Informe matricula para cadastro: ");
            scanf("%d", &matriculaPesquisa);
            if (!existeMatricula(matriculaPesquisa, v, n)) {
                break;
            }
            printf("Matricula ja existe\n");

        } while (1);

        //se esta aqui, por a matricula nao existe
        v[i].matricula = matriculaPesquisa;
        printf("Informe nome: ");
        scanf("%s", v[i].nome);
        i++;
    } while (i < n);
}

int main() {
    Aluno umAluno;
    Aluno *vetor;
    int tamanhoVetor;

    printf("Quantos alunos quer cadastrar? ");
    scanf("%d", &tamanhoVetor);

    vetor = alocarMemoria(tamanhoVetor);

    popular(vetor, tamanhoVetor);

    exibir(vetor, tamanhoVetor);

    free(vetor);
    return 1;
}
