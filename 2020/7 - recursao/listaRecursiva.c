//listaRecursiva.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 8

typedef struct no {
	int conteudo;
	struct no *prox;
} Celula;

void exibirR(Celula *lista) { //inicializou a variavel de controle
	if (lista) { //teste de parada
		printf("%d\t", lista->conteudo);			
		exibirR(lista->prox); //PONTO DE RECURSAO: transformacao variavel de controle
	}
}

Celula *inserirR(int valor, Celula *lista) {		
	if (lista && valor > lista->conteudo) {
		//percorria - empilhar
		lista->prox = inserirR(valor, lista->prox);
		return lista;
	} else { //sai da lista
		//aloca
		Celula *novo = (Celula *)malloc(sizeof(Celula));
		//deposita
		novo->conteudo = valor;
		novo->prox = lista;
		
		//retorna
		return novo;
	}
}

int contarR(Celula *lista) {
	if (lista) {
		return 1 + contarR(lista->prox);
	}
	return 0;
}

Celula *removerR(int valor, Celula *lista) {
	if (lista) {
		if (valor == lista->conteudo) {
			Celula *tmp = lista->prox;
			free(lista);
			return tmp;
		}
		lista->prox = removerR(valor, lista->prox);
		return lista;
	}
	return NULL;
}

Celula* destruirR(Celula *lista) {
	if (lista){
		lista->prox = destruirR(lista->prox);
		free(lista);
	}
	return NULL;
}

Celula *localizarR(int valor, Celula *lista) { //ponto A - inicialização da variável de controle lista
    if (lista) { //ponto B - teste de parada da recursão
        if (valor == lista->conteudo) {
            return lista; //outro ponto de desempilhamento
        } 
        Celula *resposta = localizarR(valor, lista->prox);

        //inserir códigos para serem executados depois do desempilhamento

        return resposta; //ponto C - ponto de recursão com a transformação da variável de controle
    }
    return NULL; //ponto de desempilhamento
}

int main() {
	Celula *lista = NULL;
	int i;
	int valor;
	srand(time(NULL));
	printf("Valores gerados aleatoriamente:\n");
	for (i = 0; i < TAM; i++) {
		valor = rand() % 100;
		printf("Valor sorteado: %d\n", valor);
		lista = inserirR(valor, lista);		
	}
	
	printf("Valores da lista jah ordenados:\n");
	exibirR(lista);
	
	printf("\n\nTotal de elementos: %d\n", contarR(lista));
	
	printf("Digite uma valor para excluir: ");
	scanf("%d", &valor);
	lista = removerR(valor, lista);
	printf("Lista apos a remocao de valor\n");
	exibirR(lista);
	
	lista = destruirR(lista);
	
	printf("\n\nLista apos sua destruicao\n");
	exibirR(lista);
	return 1;
}
