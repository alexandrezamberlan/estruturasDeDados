#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
    int valor;
    struct no *prox;
} Celula;

Celula *inserirDesordenado(int valor, Celula *lista) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    
    //depositar valores que vem dos parametros
    novo->valor = valor;
    novo->prox = NULL; //como não sabemos onde o novo será inserido (inicio, meio, fim)

    if (!lista) { //caso a lista esteja vazia, na primeira inserção, a lista começa pelo novo
        return novo;
    }

    Celula *p;
    for (p = lista; p->prox != NULL; p = p->prox);
    
    //engatar
    p->prox = novo;

    //retornar
    return lista;
}

Celula *inserirOrdenado(int valor, Celula *lista) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    
    //depositar valores que vem dos parametros
    novo->valor = valor;
    novo->prox = NULL; //como não sabemos onde o novo será inserido (inicio, meio, fim)

    if (!lista) { //caso a lista esteja vazia, na primeira inserção, a lista começa pelo novo
        return novo;
    }

    Celula *p, *pR; //pR sempre estará uma posição atrás do p
    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) { 
       if (valor < p->valor) {
           break;
       }
    }
    //2 situações que saimos do for
    //1o porque chegamos no final (p é null). Isso significa que o valor a ser inserido será o último
    if (!p) {
        pR->prox = novo;
        return lista;
    }
    //2o porque saimos com o break. Isso significa que o valor vai ser inserido na primeira posição
    if (p == lista) {
        novo->prox = lista;
        return novo; //novo se torna o primeiro elemento da lista
    }
    //se não for o último e nem o primeiro, só pode estar no meio
    pR->prox = novo;
    novo->prox = p;
    return lista;
}

int main() {
    Celula *listaOriginalGlicemia = NULL;
    Celula *listaOrdenadaGlicemia = NULL;
    Celula *listaOriginalCarboidratos = NULL;
    Celula *listaOrdenadaCarboidratos = NULL;

    FILE *procuradorEntrada;
    FILE *procuradorSaida;


    //abertura de arquivo de entrada, ou seja, dados de glicemia

    //percorrer o arquivo e popular as 4 listas:

    //abertura de arquivo de saida

    //calcular e gravar a media glicemia

    //calcular e gravar a mediana glicemia

    //calcular e gravar moda glicemia

    //calcular e gravar a media carboidratos

    //calcular e gravar a mediana carboidratos

    //calcular e gravar moda carboidratos

    //fechar arquivo entrada

    //fechar arquivo saida

    return 1;
}