#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

//Celula serve tanto para lista simples quanto para lista circular
typedef struct nodo {
	int conteudo;
	struct nodo *ant;
    struct nodo *prox;
} CelulaD;

void exibir(CelulaD *lista) {
    if (!lista) {
        printf("Lista vazia\n");
        return;
    }

    for ( ; lista->ant ; lista = lista->ant); //garante que o controle da lista dupla esteja no início

    CelulaD *p;
    for (p = lista; p ; p = p->prox) {
        printf("%d\t", p->conteudo);
    }
    printf("\n");
}

int contar(CelulaD *lista) {
    if (!lista) {
        return 0;
    }
    
    for ( ; lista->ant ; lista = lista->ant); //garante que o controle da lista dupla esteja no início

    int conta = 0;
    CelulaD *p;
    for (p = lista; p ; conta++, p = p->prox);

    return conta;
}

CelulaD *localizar(int valor, CelulaD *lista) {
    if (!lista) {
        return NULL;
    }
    CelulaD *p;

    for ( ; lista->ant ; lista = lista->ant); //garante que o controle da lista dupla esteja no início

    for (p = lista; p ; p = p->prox) {
        if (valor == p->conteudo)
            return p;
    }    
    return NULL;
}

CelulaD *destruir(CelulaD *lista) {
    CelulaD *pR, *p;

    if (!lista) return lista;

    for ( ; lista->ant ; lista = lista->ant); //garante que o controle da lista dupla esteja no início

    for (pR = lista, p = lista->prox; p ; pR = p, p = p->prox) {
        free(pR);
    }
    free(pR);

    return NULL;
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    CelulaD *listaD = NULL;
    
    srand(time(NULL));

    int i;
    for (i = 0; i < 5000; i++) {
        listaD = inserir(rand() % 100, listaD);
    }

    printf("A lista dupla tem %d elementos\n", contar(listaD));
    exibir(listaD);

    int numero;
    printf("Digite um número para excluir: ");
    scanf("%d",&numero);

    listaD = excluir(numero, listaD);

    printf("A lista dupla tem %d elementos após a exclusão\n", contar(listaD));
    exibir(listaD);

    listaD = destruir(listaD);

    exibir(listaD);

    return 1;
}