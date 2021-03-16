#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct nodo {
    int valor; // um ou mais atributos ou variávies
    struct nodo *prox;
} Celula;

Celula *inserir(int valor, Celula *topo) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores dos parametros
    novo->valor = valor;

    //engatar
    novo->prox = topo;

    //retornar
    return novo;
}

Celula *excluir(Celula *topo) {
    //soh eh possivel excluir se a pilha nao estiver vazia
    if (!topo) {
        cout << "Pilha vazia. Remocao nao pode ser realizada" << endl;
        return topo;
    }

    Celula *lixo;
    lixo = topo;
    topo = topo->prox; //o ponteiro topo andou uma posição para frente

    free(lixo); //libera a memória ou seja, apaga o elemento

    return topo;
}


int main() {
    system("clear");//system("cls");
    //precisa abrir o arquivo de comandos.txt
    FILE *procuradorEntrada = fopen("comandos.txt", "r"); //para o arquivo de comandos.txt
    FILE *procuradorSaida = fopen("saida.txt", "w"); //para o arquivo de saida.txt

    //popular a pilha conforme os comandos existentes no arquivo
    Celula *pilha = NULL;
    char comando;
    int valor;
    do {
        fscanf(procuradorEntrada,"%c %d", &comando, &valor);
        switch (comando) {
            case 'I' : pilha = inserir(valor,pilha);
                       break;
            case 'R' : pilha = excluir(pilha);
                       break;
            default : break;
        }
    } while (!feof(procuradorEntrada));

    //gravar a pilha resultante no arquivo saida.txt
    for (Celula *p = pilha; p != NULL; p = p->prox) {
        fprintf(procuradorSaida, "%d\n", p->valor);
        fflush(procuradorSaida);
    }

    //fechar os procuradores dos arquivos
    fclose(procuradorEntrada);
    fclose(procuradorSaida);
    return 1;
}