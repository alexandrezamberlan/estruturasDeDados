#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct nodo {
	int conteudo;
	struct nodo *prox;
} Celula;

//inserindo na lista com ordenacao. Na sua posição correta: no início, no fim, ou no meio
Celula *inserir(int valor, Celula *lista) {
	Celula *novo; //para alocar nova celula
    Celula *p, *pR;

	//alocar memoria
	novo = (Celula *)malloc(sizeof(Celula));
	//depositar valor
	novo->conteudo = valor;
    novo->prox = NULL; //nao sabemos onde o novo será inserido

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
    if (!pR) { // p == lista
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
        lista = inserir((60 + rand() % 300), lista);
    }
    return lista;
}

Celula *mesclar(Celula *lista1, Celula *lista2) {
    Celula *listaResultado = NULL;
    Celula *p; //ponteiro de percurso

    for (p = lista1; p ; p = p->prox) {
        listaResultado = inserir(p->conteudo,listaResultado);
    }

    for (p = lista2; p ; p = p->prox) {
        listaResultado = inserir(p->conteudo,listaResultado);
    }

    return listaResultado;
}

Celula *localizar(int valor, Celula *lista) {
    Celula *p;
    if (lista) {
        for (p = lista; p; p = p->prox) {
            if (valor == p->conteudo) {
                return p; //achou o valor
            }
        }
    }
    return NULL; //valor não localizado
}

Celula *mesclarComControleDuplicidade(Celula *lista1, Celula *lista2) {
    Celula *listaResultado = NULL;
    Celula *p;

    for (p = lista1; p ; p = p->prox) {
        if (!localizar(p->conteudo, listaResultado)) {
            listaResultado = inserir(p->conteudo,listaResultado);
        } 
    }
    
    for (p = lista2; p ; p = p->prox) {
        if (!localizar(p->conteudo, listaResultado)) {
            listaResultado = inserir(p->conteudo,listaResultado);
        }
    }
    return listaResultado;
}

Celula *podar(Celula *lista) {
  if (!lista) return lista;
  lista = excluir(lista->conteudo,lista); //excluindo o primeiro
  Celula *p;
  if (!lista) return lista; //excluiu o primeiro e acabou a lista
  for (p = lista; p->prox; p = p->prox);
  lista = excluir(p->conteudo, lista); //exclui o último
  return lista;
}


int main() {
    setlocale(LC_ALL,"Portuguese");
	Celula *lista1 = NULL;
    
    lista1 = popular(lista1,8);
    printf("A lista1 contém: %d números sorteados\n", contar(lista1));
    exibir(lista1);

    Celula *lista2 = NULL;
    
    lista2 = popular(lista2,3);
    printf("A lista2 contém: %d números sorteados\n", contar(lista2));
    exibir(lista2);

    Celula *lista3 = NULL;

    lista3 = mesclarComControleDuplicidade(lista1,lista2);
    printf("A lista3 contém: %d números mesclados das 2 primeiras listas\n", contar(lista3));
    exibir(lista3);


	return 1;
}

