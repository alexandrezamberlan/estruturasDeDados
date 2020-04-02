#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct nodo {
	int conteudo;
	struct nodo *prox;
} Celula;

void exibir(Celula *lista) {
    Celula *p;
    if (!lista) {
        printf("Lista vazia.\n");
        return;
    }
    for (p = lista; p->prox != lista; p = p->prox) {
        printf("%d\t", p->conteudo);
    }
    printf("%d\n", p->conteudo);
}

int contar(Celula *lista) {
    Celula *p;
    int total = 0;
    if (!lista) return 0;
    
    for (p = lista; p->prox != lista; p = p->prox){
        total++;
    }
    total++;

    return total;
}

Celula *localizar(int valor, Celula *lista) {
    Celula *p;
    if (lista) {
        for (p = lista; p->prox != lista; p = p->prox) {
            if (valor == p->conteudo) {
                return p; //achou o valor
            }
        }
        if (valor == p->conteudo) {
            return p; //achou o valor
        }
    }
    return NULL; //valor não localizado
}

//inserindo na lista sem ordenacao, sempre na última posição
Celula *inserir(int valor, Celula *lista) {
	Celula *novo; //para alocar nova celula
    Celula *p, *pR;
	//alocar memoria
	novo = (Celula *)malloc(sizeof(Celula));
	//depositar valor
	novo->conteudo = valor;
    novo->prox = NULL;

    //percorrer a lista a procura da posicao correta
    for (pR = NULL, p = lista; p->prox != lista ; pR = p, p = p->prox) {
        if (valor < p->conteudo) {
            //achamos a posicao
            break;
        }
    }
    //será que é o último
    if (p->prox == lista && valor < p->conteudo) {
        p->prox = novo;
        novo->prox = lista;
        return lista;
    }
    //numero inserido como primeiro
    if (!pR) {
        novo->prox = lista; 
        
        for (; p->prox != lista; p = p->prox);

        p->prox = novo;

        return novo;
    } else {//numero inserido no meio
        pR->prox = novo;
        novo->prox = p;
    }	
	return lista; //retornamos o primeiro elemento
}

Celula *popular(Celula *lista, int quantidade) {
    srand(time(NULL));
    int i;
    for (i = 0; i < quantidade; i++ ) {
        lista = inserir(rand() % 100, lista);
    }

    return lista;
}

int main() {
    setlocale(LC_ALL,"Portuguese");
	Celula *listaC = NULL;
    
    listaC = popular(listaC,8);
    printf("Lista circular com %d elementos\n", contar(listaC));
    exibir(listaC);
    return 1;
}
