#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
    int dado;
    struct no *prox;
}Celula;

void exibir(Celula *l) {
    Celula *p;
    int i;
    for (i = 0,p = l; p; p = p->prox, i++) {
        printf("%d\t", p->dado);
    }
    printf("\n");
}

Celula *inserir(int valor, Celula *l) {
    Celula *p, *pR, *novo = (Celula *)malloc(sizeof(Celula));
    novo->dado = valor;
    novo->prox = NULL;

    if (!l) return novo;

    for (pR = NULL, p = l; p; pR = p, p = p->prox) {
		if (valor < p->dado) break;
	}
    if (p == l) { //inicio
        novo->prox = l;
        return novo;
    }
    pR->prox = novo; //ultimo
    if (p) {
        novo->prox = p; //meio
    }
    return l;
}

Celula *inserirControleDuplicados(int valor, Celula *l) {
    Celula *p, *pR, *novo = (Celula *)malloc(sizeof(Celula));
    novo->dado = valor;
    novo->prox = NULL;

    if (!l) return novo;

    for (pR = NULL, p = l; p; pR = p, p = p->prox) {
    	if (valor == p->dado) {
    		free(novo);
    		return l;
    	}
    	
		if (valor < p->dado) break;
	}
    if (p == l) { //inicio
        novo->prox = l;
        return novo;
    }
    pR->prox = novo; //ultimo
    if (p) {
        novo->prox = p; //meio
    }
    return l;
}


Celula *excluir(int valor, Celula *l) {
    Celula *pR, *p;
    if (!l) return l;
    for (pR = NULL, p = l; p; pR = p, p = p->prox) {
        if (valor == p->dado) break;
    }
    if (!p) return l; //nao localizado
    if (p == l) { //localizado no inicio
        l = l->prox;
        free(p);
        return l;
    }
    if (!p->prox) { //encontrado na ultima posicao
        free(p);
        pR->prox = NULL;
        return l;
    }
    pR->prox = p->prox; //no meio
    free(p);

    return l;
}

//método que recebe uma lista e retorna a quantidade de elementos 
int contaElementos(Celula *l) {
	int quantidade = 0;
	Celula *p;
	for (p = l; p; p = p->prox) {
		quantidade++;
	}
	return quantidade;
}
//método que recebe uma lista e retorna 
// 0 se for vazia; 1 se for circular; 2 se for simples.
int tipoLista(Celula *l) {
	Celula *p;
	if (!l) return 0;
	
	for (p = l; p->prox != l; p = p->prox) {
		if (p->prox == NULL) {			
			return 2;
		}
	}
	return 1;
}

//método que recebe uma lista e exibe todos os elementos 
//que aparecem mais de uma vez
void mostrarRepetidos(Celula *l) {
	Celula *listaDuplicados = NULL;
	int valor, contador;
	Celula *p, *p2;
	
	for (p = l; p; p = p->prox){
		valor = p->dado;
		contador = 0;
		for (p2 = l; p2; p2 = p2->prox) {
			if (valor == p2->dado) contador++;
			if (contador == 2) {
				listaDuplicados = inserirControleDuplicados(valor,listaDuplicados);
				break;
			}
		}
	}
	printf("Valores que aparecem repetidos na lista:\n");
	exibir(listaDuplicados);
}

//método que recebe uma lista e remove todos os pares da lista 
Celula *removerPares(Celula *l) {
	Celula *p;
	if (!l) return l;
	
	for (p = l; p; ) {
		if (p->dado % 2 == 0) {
			l = excluir(p->dado, l);
			p = l;
		} else p = p->prox; //soh avanca p se for impar
	}
	return l;
}

int main() {
    Celula *lista = NULL;
    
    srand(time(NULL));
    int i;//rand() % 20;

    for (i = 10; i > 0; i--) {
        lista = inserir(rand() % 15, lista);
    }
    exibir(lista);

    //int numero;
    //printf("Informe um numero para exclusao: ");
    //scanf("%d", &numero);
    //lista = excluir(numero, lista);

    //exibir(lista);
    
	switch (tipoLista(lista)) {
    	case 0 : printf("Lista vazia.\n");
    	         break;
		case 1 : printf("Lista circular.\n");
    	         break;    	         
    	case 2 : printf("Lista simples.\n");
    	         break; 
		default : printf("opsss\n");   	         
    }
    printf("A lista no final tem %d elementos\n", contaElementos(lista));
    mostrarRepetidos(lista);
    
    printf("Lista sem os numeros pares....\n");
    lista = removerPares(lista);
    exibir(lista);
    return 1;
}
