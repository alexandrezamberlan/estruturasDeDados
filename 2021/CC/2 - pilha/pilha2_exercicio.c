#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int dado;
    struct no *prox; //endereço do próximo elemento
} Celula;

Celula *inserir(int valor, Celula *topo) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valor
    novo->dado = valor; //(*novo).dado = valor;

    //encadear o novo elemento na pilha
    novo->prox = topo;

    //retornar o novo topo
    return novo;
}

Celula *remover(Celula *topo) {
    Celula *lixo;
    //verifica se a pilha existe
    if (topo == NULL) {
        printf("Pilha esta vazia!\n");
    } else {
        //isola o topo a ser removido
        lixo = topo;
        //avança o topo um endereço
        topo = topo->prox; 
        //libera memoria
        printf("Valor a ser removido: %d\n", lixo->dado);
        free(lixo);
    }
    //novo topo é retornado
    return topo;
}

int main() {
    Celula *pilha = NULL;
    FILE *procuradorEntrada; //vai representar o arquivo comandos.txt
    FILE *procuradorSaida; //vai representar o arquivo saida.txt

    //abrir o arquivo de comandos.txt
    procuradorEntrada = fopen("comandos.txt","r");

    //criar o arquivo saida.txt
    procuradorSaida = fopen("saida.txt", "w");

    //percorrer o arquivo analisando a primeira coluna
    //I - inserir
    //R - remover
    char comando;
    int valor;
    do {
        fscanf(procuradorEntrada,"%c %d", &comando, &valor);
        switch (comando) {
            case 'I' : pilha = inserir(valor, pilha);
                       break;
            case 'R' : pilha = remover(pilha);
                       break;
            default : break;
        }
    } while (!feof(procuradorEntrada));

    //gravar a pilha resultante no arquivo saida.txt
    Celula *p;
    for (p = pilha; p != NULL; p = p->prox) { //rotina para percorrer uma pilha do topo até o primeiro elem.
        fprintf(procuradorSaida,"%d\n", p->dado);
        fflush(procuradorSaida);
    }

    //fechar os arquivos
    fclose(procuradorEntrada);
    fclose(procuradorSaida);

    return 1;
}