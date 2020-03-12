#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct nodo {
	int conteudo;
	struct nodo *prox;
} Celula;

Celula *inserir(int valor, Celula *lista) {
	Celula *novo; //para alocar nova celula

	//alocar memoria
	novo = (Celula *)malloc(sizeof(Celula));

	//depositar valor
	novo->conteudo = valor;

	//engatar
	novo->prox = lista; //o novo elemento conhece o lista
	
	return novo; //novo eh retornado
}

//inserindo na lista sem ordenacao, sempre na última posição
Celula *remover(Celula *lista) {
	Celula *lixo;

	if (!lista) {
		printf("Lista vazia\n");
		return lista;
	}

	lixo = lista;
	lista = lista->prox; 

	return lista;
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

int contar(Celula *lista) {
    Celula *p;
    int total = 0;
    for (p = lista; p; p = p->prox, total++);

    return total;
}

void exibirElementosMeio(Celula *lista) {
    Celula *p; 

    if (!lista) {
        printf("Lista vazia, logo não há meio\n");
        return ;
    }
    int totalElementos = contar(lista);    

    if (totalElementos % 2 != 0) { //estrutura impar
        totalElementos = totalElementos / 2;
        for (p = lista; totalElementos > 0; totalElementos--, p = p->prox);

        printf("Elemento do meio: %p->%d\n",p,p->conteudo);

    } else { //estrutura par
        printf("É preciso fazer......\n");
    }
}

int main() {
    setlocale(LC_ALL,"Portuguese");
	Celula *lista = NULL;
    int TAM = 5;
    int i;
    int valor;
    for (i = 0; i < TAM; i++ ) {
        printf("Digite um valor para inserir na estrutura encadeada: ");
        scanf("%d", &valor);
        if (!localizar(valor,lista)) {
            lista = inserir(valor, lista);
        } else {
            printf("%d já existe na estrutura.\n", valor);
            i--;
        }
    }
	
	exibir(lista);
    
    exibirElementosMeio(lista);

	return 1;
}







