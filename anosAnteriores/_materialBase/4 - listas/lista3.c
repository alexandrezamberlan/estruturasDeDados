#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct nodo {
	int conteudo;
	struct nodo *prox;
} Celula;

//inserindo na lista sem ordenacao, sempre na última posição
Celula *inserir(int valor, Celula *lista) {
	Celula *novo; //para alocar nova celula
    Celula *p, *pR;
	//alocar memoria
	novo = (Celula *)malloc(sizeof(Celula));
	//depositar valor
	novo->conteudo = valor;
    novo->prox = NULL;

    if (!lista) {
        return novo;
    }

    //percorrer a lista a procura da posicao correta
    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) {
        if (valor < p->conteudo) {
            //achamos a posicao
            break;
        }
    }
    //numero inserido como primeiro
    if (!pR) {
        novo->prox = p; //ou novo->prox = lista;
        return novo;
    } else if (p == NULL) {//numero inserido na ultima posicao
        pR->prox = novo;
    } else {//numero inserido no meio
        pR->prox = novo;
        novo->prox = p;
    }	
	return lista; //retornamos o primeiro elemento
}

void exibir(Celula *lista) {
    Celula *p;
    if (!lista) {
        printf("Lista vazia.\n");
        return;
    }
    for (p = lista; p; p = p->prox) {
        printf("%d\t", p->conteudo);
    }
    printf("\n");
}

int contar(Celula *lista) {
    Celula *p;
    int total = 0;
    for (p = lista; p; p = p->prox, total++);

    return total;
}

Celula *popular(Celula *lista, int quantidade) {
    srand(time(NULL));
    int i;
    for (i = 0; i < quantidade; i++ ) {
        lista = inserir(rand() % 100, lista);
    }

    return lista;
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

    if (!lista) {
        return novo;
    }

    //percorrer a lista a procura da posicao correta
    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) {
        if (valor < p->conteudo) {
            //achamos a posicao
            break;
        }
    }
    //numero inserido como primeiro
    if (!pR) {
        novo->prox = p; //ou novo->prox = lista;
        return novo;
    } else if (p == NULL) {//numero inserido na ultima posicao
        pR->prox = novo;
    } else {//numero inserido no meio
        pR->prox = novo;
        novo->prox = p;
    }	
	return lista; //retornamos o primeiro elemento
}

Celula *excluir(int valor, Celula *lista) {
    Celula *p, *pR;

    if (!lista) {
        return lista; //return NULL;
    }

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
    } else if (!p->prox) {
        //código para remover o último elemento
        pR->prox = NULL;
    } else {
        //código para remover o elemento que estiver no meio da lista
        pR->prox = p->prox;
    }
    free(p);
    return lista;
}

Celula *excluirFaixa(int ini, int fim, Celula *lista) {
    int i;
    Celula *p;

    if (!lista) {
        return lista; //return NULL;
    }

    for (i = 0, p = lista; p ; i++, p = p->prox) {
        if () {
            lista = excluir(p->conteudo,lista);
        }
    }

    return lista;
}

Celula *destruir(Celula *lista) {
    Celula *pR, *p;

    if (!lista) return lista;

    for (pR = lista, p = lista->prox; p ; pR = p, p = p->prox) {
        free(pR);
    }
    free(pR);

    return NULL;
}

int main() {
    setlocale(LC_ALL,"Portuguese");
	Celula *lista = NULL;
    
    lista = popular(lista,8);
    exibir(lista);

    int numero;
    printf("Digite um número da lista para excluir: ");
    scanf("%d", &numero);
    lista = excluir(numero, lista);

    printf("Números na lista após exclusão\n");
    exibir(lista);

    lista = excluirFaixa(2,5,lista);
    printf("Números na lista após exclusão de sequência\n");
    exibir(lista);

    lista = destruir(lista); //liberar todos os endereços de memória

    //continua código
    exibir(lista);

	return 1;
}







