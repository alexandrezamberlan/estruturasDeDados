#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct nodo {
	int conteudo;
	struct nodo *prox;
} Celula;

Celula *inserir(int valor, Celula *topo) {
	Celula *novo; //para alocar nova celula

	//alocar memoria
	novo = (Celula *)malloc(sizeof(Celula));

	//depositar valor
	novo->conteudo = valor;

	//engatar
	novo->prox = topo; //o novo elemento conhece o topo
	
	return novo; //novo topo eh retornado
}

Celula *remover(Celula *topo) {
	Celula *lixo;

	if (!topo) {
		printf("Pilha vazia\n");
		return topo;
	}

	lixo = topo;
	topo = topo->prox; 

	return topo;
}

void exibir(Celula *topo) {
    Celula *p;
    if (!topo) {
        printf("Pilha vazia.\n");
        return;
    }
    for (p = topo; p; p = p->prox) {
        printf("%d\t", p->conteudo);
    }
    printf("\n");
}

Celula *localizar(int valor, Celula *topo) {
    Celula *p;
    if (topo) {
        for (p = topo; p; p = p->prox) {
            if (valor == p->conteudo) {
                return p; //achou o valor
            }
        }
    }
    return NULL; //valor não localizado
}

int main() {
    setlocale(LC_ALL,"Portuguese");
	Celula *pilha = NULL;
    int TAM = 5;
    int i;
    int valor;
    for (i = 0; i < TAM; i++ ) {
        printf("Digite um valor para inserir na estrutura encadeada: ");
        scanf("%d", &valor);
        if (!localizar(valor,pilha)) {
            pilha = inserir(valor, pilha);
        } else {
            printf("%d já existe na estrutura.\n", valor);
            i--;
        }
    }
	
	exibir(pilha);

	return 1;
}







