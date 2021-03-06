#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
    int valor;
    struct no *ant;
    struct no *prox;
} CelulaD;

void gravarEmArquivoD(CelulaD *lista) {
    CelulaD *p;
    FILE *procurador;
    char nomeArquivo[100];

    if (!lista) { //lista == NULL
        printf("Lista vazia.\n");
        return;
    } 

    //garantindo que o controle da lista esteja no início
    for ( ;lista->ant != NULL; lista = lista->ant);

    printf("Nome do arquivo de saida: ");
    scanf("%s", nomeArquivo);

    procurador = fopen(nomeArquivo, "w");

    int contador = 0;
    for (p = lista; p != NULL; p = p->prox) { //percurso clássico: usado para exibir, contar, localizar, ...
        fprintf(procurador, "%d\n", p->valor);
        contador++;
    }
    fprintf(procurador,"Total de números: %d", contador);
    fclose(procurador);
}

void exibirD(CelulaD *lista) {
    CelulaD *p;

    if (!lista) { //lista == NULL
        printf("Lista vazia.\n");
        return;
    } 

    //garantindo que o controle da lista esteja no início
    for ( ;lista->ant != NULL; lista = lista->ant);


    for (p = lista; p != NULL; p = p->prox) { //percurso clássico: usado para exibir, contar, localizar, ...
        printf("%d\t", p->valor);
    }
    printf("\n");
}

int contarElementosD(CelulaD *lista) {
    if (!lista) return 0;

    //garantindo que o controle da lista esteja no início
    for ( ;lista->ant != NULL; lista = lista->ant);

    CelulaD *p;
    int contador = 0;
    for (p = lista; p  ; p = p->prox) {
        contador++;
    }

    return contador;
}

CelulaD *inserirD(int valor, CelulaD *lista) {
    CelulaD *novo;
    //alocar memória para o novo elemento
    novo = (CelulaD *)malloc(sizeof(CelulaD));

    //depositar valores do parâmetro
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = NULL;

    //se a lista for vazia, significa que o novo é o primeiro e único elemento
    if (!lista) return novo;

    //garantindo que o controle da lista esteja no início
    for ( ;lista->ant != NULL; lista = lista->ant);

    //percorrer para localizar a posição correta
    CelulaD *p, *pR;
    for (pR = NULL, p = lista; p != NULL; pR = p, p = p->prox) {
        if (valor < p->valor) {
            break;         
        }
    }
    //achamos a posição, agora precisamos descobrir se é o primeiro, último ou meio
    //se é o primeiro
    if (p == lista) {
        novo->prox = lista;
        lista->ant = novo;
        return novo;
    }

    //se é o último  
    if (!p) {
        pR->prox = novo;
        novo->ant = pR;
        return lista;
    } 
    //se chegou até aqui, pq está em alguma posição do meio
    pR->prox = novo;
    novo->ant = pR;
    pR = novo;
    novo->prox = p;
    return lista;
}

int main() {
    CelulaD *lista = NULL;
    system("clear");
    srand(time(NULL));

    int valor;
    int quantidade;
    printf("Quantos valores quer gerar? ");
    scanf("%d", &quantidade);
    do {
        valor = rand() % 15;
        lista = inserirD(valor, lista); //vamos inserir no final da lista
        quantidade--;
    } while (quantidade > 0);

    //exibirD(lista);
    gravarEmArquivoD(lista);

    // int quantidadeElementos = contarElementosD(lista);
    // printf("A lista possui %d elementos\n", quantidadeElementos);

    return 1;
}