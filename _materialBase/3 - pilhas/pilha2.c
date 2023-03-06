#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct no {
    int matricula;
    char nome[200];
    struct no *prox;
} Celula;

Celula *inserirPilha(int matricula, char nome[], Celula *topo) {
    //alocar
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    //depositar
    novo->matricula = matricula;
    strcpy(novo->nome,nome);
    //engatar
    novo->prox = topo;

    return novo;
}

void exibirPilha(Celula *topo) {
    Celula *p;
    if (!topo) {
        printf("Pilha vazia\n");
        return;
    }

    for (p = topo; p ; p = p->prox) {
        printf("%d - %s\n",p->matricula, p->nome);
    }
}

int main() {
    setlocale(LC_ALL,"");
    Celula *pilhaArquivo = NULL;
    /*
    pilhaArquivo = inserirPilha(100,"Lucas",pilhaArquivo);
    pilhaArquivo = inserirPilha(101,"Xandao",pilhaArquivo);
    pilhaArquivo = inserirPilha(102,"Regis",pilhaArquivo);
    pilhaArquivo = inserirPilha(103,"Vini",pilhaArquivo);
    */

    FILE *procurador;
    char nomeArquivo[200];

    printf("Informe nome do arquivo com dados de alunos: ");
    scanf("%s", nomeArquivo);

    procurador = fopen(nomeArquivo,"r");
    if (!procurador) {
        printf("Arquivo não localizado.\n");
        exit(0);
    }
    printf("Arquivo localizado e sendo trabalhado....\n");

    int matricula;
    char nome[200];

    do {
        fscanf(procurador,"%d %s",&matricula,nome);
        if (feof(procurador)){
            break;
        }

        pilhaArquivo = inserirPilha(matricula,nome,pilhaArquivo);
    } while (1);

    fclose(procurador);

    exibirPilha(pilhaArquivo);

    //RETIRANDO DOIS ELEMENTOS DO TOPO
    pilhaArquivo = removerPilha(pilhaArquivo);
    pilhaArquivo = removerPilha(pilhaArquivo);

    //ATUALIZAR O ARQUIVO COM A PILHA ALTERADA
    atualizarArquivo(nomeArquivo,pilhaArquivo);

    return 1;
}
