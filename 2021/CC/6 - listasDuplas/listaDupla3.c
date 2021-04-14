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

CelulaD *abrirArquivoPopularListaD(CelulaD *lista, char nomeArquivo[]) {
    FILE *procurador;
    procurador = fopen(nomeArquivo, "r");
    if (!procurador) {
        printf("Arquivo com números não existe!\n");
        return NULL;
    }
    int valor;
    while (!feof(procurador)) {
        fscanf(procurador,"%d", &valor);
        lista = inserirD(valor, lista);
    }

    return lista;
}

void localizarMostrarValorD(int valor, CelulaD *lista) {

    if (!lista) return;

    //garantindo que o controle da lista esteja no início
    for ( ;lista->ant != NULL; lista = lista->ant);

    CelulaD *p;
    int contador = 0;
    for (p = lista; p != NULL; p = p->prox) {
        if (valor == p->valor) {
            contador++;
        }
    }

    if (contador > 0) {
        printf("Valor encontrado %d vez(es)\n", contador);
    } else {
        printf("Valor não encontrado\n");
    }

}

int main() {
    CelulaD *lista = NULL;
    system("clear");
    
    char nomeArquivo[100];
    printf("Nome de arquivo com numeros: ");
    scanf("%s", nomeArquivo);

    lista = abrirArquivoPopularListaD(lista, nomeArquivo);

    if (!lista) {
        printf("Programa encerrado!\n");
        exit(0);
    }

    int valor;
    printf("Valor para pesquisa: ");
    scanf("%d", &valor);
    
    localizarMostrarValorD(valor, lista);

    return 1;
}