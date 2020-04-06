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

float calcularMedia(Celula *lista) {
    int totalElementos = contar(lista);
    if (totalElementos == 0) {
        return 0;
    }
    int soma = 0;
    Celula *p;
    for (p = lista; p ; p = p->prox) {
        soma = soma + p->conteudo;
    }
    return soma / totalElementos;
}

int menorValor(Celula *lista) {
    if (!lista) {
        return -27; //lista inexistente e não há menor valor
    }
    return lista->conteudo;
}

int maiorValor(Celula *lista) {
    if (!lista) {
        return -27; //lista inexistente e não há menor valor
    }
    Celula *p;
    for (p = lista; p->prox ; p = p->prox);

    return p->conteudo;
}

void mostrarMediana(Celula *lista) {   
    int totalElementos = contar(lista);
    Celula *p, *pR;

    if (totalElementos < 3) {
        printf("Lista com elementos insuficientes. Não há mediana.\n");
        return;
    }

    if (totalElementos % 2 != 0) { //quantidade impar, logo mostrar só o do meio
        totalElementos = totalElementos / 2;
        int i;
        
        for (i = 0, p = lista; i < totalElementos; i++, p = p->prox);

        printf("O valor mediano de uma lista de tamanho ímpar é: %d\n", p->conteudo);
    } else {
        totalElementos = totalElementos / 2;

        int i;
        
        for (i = 0, pR = NULL, p = lista; i < totalElementos; i++, pR = p, p = p->prox);

        printf("O primeiro valor mediano de uma lista de tamanho par: %d\n", pR->conteudo);
        printf("O segundo valor mediano de uma lista de tamanho par: %d\n", p->conteudo);
    }
}

int main() {
    setlocale(LC_ALL,"Portuguese");
	Celula *lista = NULL;
    
    lista = popular(lista,8);
    printf("A lista contém: %d números sorteados\n", contar(lista));
    exibir(lista);

    //calcular e mostrar a média da lista
    printf("O valor médio da lista é: %.2f\n", calcularMedia(lista));

    //mostrar o menor elemento
    printf("O menor elemento da lista é: %d\n", menorValor(lista));

    //mostrar o maior elemento
    printf("O maior elemento da lista é: %d\n", maiorValor(lista));

    //mostrar a mediana (se a lista for ímpar, mostrar o elemento do meio. 
    //se a lista for par, mostar os dois elementos do meio)
    mostrarMediana(lista);

	return 1;
}

