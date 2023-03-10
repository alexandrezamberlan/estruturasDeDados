#include <stdio.h>
#include <stdlib.h>

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
	
	free(lixo);

	return topo;
}

int main() {
	Celula *pilha = NULL;

	pilha = inserir(10, pilha);
	pilha = inserir(15, pilha);
	pilha = inserir(20, pilha);

	pilha = remover(pilha);

	printf("O topo da lista eh %d e estah no endereco %p\n", pilha->conteudo, pilha);

	return 1;
}







