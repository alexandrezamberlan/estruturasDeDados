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

//inserindo na lista com ordenacao. Na sua posição correta: no início, no fim, ou no meio
CelulaD *inserir(int valor, CelulaD *lista) {
	CelulaD *novo; //para alocar nova CelulaD 
    CelulaD *pR, *p;

	//alocar memoria
	novo = (CelulaD *)malloc(sizeof(CelulaD));
	
    //depositar valor
	novo->conteudo = valor;
    novo->prox = NULL; //nao sabemos onde o novo será inserido
    novo->ant = NULL;

    if (!lista) {
        return novo;
    }

    for ( ; lista->ant ; lista = lista->ant); //garante que o controle da lista dupla esteja no início

    //percorrer a lista a procura da posicao correta
    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) {
        if (valor < p->conteudo) {
            //achamos a posicao
            break;
        }
    }
    //numero inserido como primeiro
    if (!pR) { // p == lista
        novo->prox = p; //ou novo->prox = lista;
        p->ant = novo;
        return novo;
    } else if (p == NULL) {//numero inserido na ultima posicao
        pR->prox = novo;
        novo->ant = pR;
    } else {//numero inserido no meio
        pR->prox = novo;
        novo->ant = pR;
        novo->prox = p;
        p->ant = novo;
    }	
	return lista; //retornamos o primeiro elemento
}

CelulaD *excluir(int valor, CelulaD *lista) {
    CelulaD *p, *pR;

    if (!lista) {
        return lista; //return NULL;
    }

    for ( ; lista->ant ; lista = lista->ant); //garante que o controle da lista dupla esteja no início

    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) {
        if (valor == p->conteudo) {
            printf("Valor localizado e será removido\n");
            break;
        }
    }

    if (!p) {
        printf("Valor não localizado\n");
        return lista;
    }
    //valor é o primeiro elemento
    if (!pR) { // if (p == lista)
        //código para remover o primeiro elemento
        lista = lista->prox;
        lista->ant = NULL;
    } else if (!p->prox) {
        //código para remover o último elemento
        pR->prox = NULL;
    } else {
        //código para remover o elemento que estiver no meio da lista
        pR->prox = p->prox;
        p->prox->ant = pR;
    }
    free(p);
    return lista;
}

CelulaD *excluirTodasOcorrencias(int valor, CelulaD *lista) {
    if (!lista) return lista;
    
    for ( ; lista->ant ; lista = lista->ant); //garante que o controle da lista dupla esteja no início

    CelulaD *p;
    for (p = lista; p ; p = p->prox) {
        if (valor == p->conteudo) {
            lista = excluir(valor, lista);
        }
    }
    return lista;
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

    listaD = excluirTodasOcorrencias(numero, listaD);

    printf("A lista dupla tem %d elementos após a exclusão\n", contar(listaD));
    exibir(listaD);

    listaD = destruir(listaD);

    exibir(listaD);

    return 1;
}