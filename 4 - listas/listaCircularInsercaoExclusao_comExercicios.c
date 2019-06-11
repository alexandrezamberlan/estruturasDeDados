#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo {
	int dado;
	struct nodo *prox;
} Celula;

Celula *inserirC(int valor, Celula *l) {
	Celula *novo, *p, *pR;

	//alocar memoria
	novo = (Celula *)malloc(sizeof(Celula));
	//depositar valores
	novo->dado = valor;
	novo->prox = novo;
	//eh o primeiro
	if (!l) return novo;

	//percorrer
	for(pR = NULL, p = l; p->prox != l; pR = p, p = p->prox) {
		if (valor < p->dado) break;
	}
	//descobrir por que parou o for
	if (valor > p->dado) {//ultimo
		p->prox = novo;
		novo->prox = l;
	} else if (p == l) { //inicio
		novo->prox = l;
		for (;p->prox != l; p = p->prox);
		p->prox = novo;
		return novo;
	} else if (p->prox != l || valor < p->dado) {
		pR->prox = novo;
		novo->prox = p;
	}
	return l;
}

Celula *inserirControleDuplicadosC(int valor, Celula *l) {
	Celula *novo, *p, *pR;

	//alocar memoria
	novo = (Celula *)malloc(sizeof(Celula));
	//depositar valores
	novo->dado = valor;
	novo->prox = novo;
	//eh o primeiro
	if (!l) return novo;

	//percorrer
	for(pR = NULL, p = l; p->prox != l; pR = p, p = p->prox) {
		if (valor == p->dado) {
			free(novo);
			return l;
		}
		if (valor < p->dado) break;
	}
	if (valor == p->dado) {
			free(novo);
			return l;
	}
	//descobrir por que parou o for
	if (valor > p->dado) {//ultimo
		p->prox = novo;
		novo->prox = l;
	} else if (p == l) { //inicio
		novo->prox = l;
		for (;p->prox != l; p = p->prox);
		p->prox = novo;
		return novo;
	} else if (p->prox != l || valor < p->dado) {
		pR->prox = novo;
		novo->prox = p;
	}
	return l;
}

void exibirC(Celula *l) {
	Celula *p;
	if (!l) {
		printf("Lista Circular Vazia\n");
		return;
	}
	for (p = l; p->prox != l; p = p->prox) {
		printf("%d\t", p->dado);
	}	
	printf("%d\n", p->dado);
}

Celula *removerC(int valor, Celula *l) {
	Celula *p, *pR;
	if (!l) return NULL;

	for(pR = NULL, p = l; p->prox != l; pR = p, p = p->prox) {
		if (valor == p->dado) break;
	}
	if (valor != p->dado) return l;

	if (p == l) { //inicio
		l = l->prox;
		if (!l) {
			return NULL;
		}
		pR = p;
		for (p = l;p->prox != pR; p = p->prox);
		p->prox = l;
		free(pR);
	} else if (p->prox != l) { //meio
		pR->prox = p->prox;
		free(p);
	} else { //fim
		pR->prox  = l;
		free(p);
	}
	return l;
}


//método que recebe uma lista e retorna a quantidade de elementos 
int contaElementosC(Celula *l) {
	int quantidade = 0;
	Celula *p;
	for (p = l; p->prox != l; p = p->prox) {
		quantidade++;
	}	
	return ++quantidade;
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
void mostrarRepetidosC(Celula *l) {
	Celula *listaDuplicados = NULL;
	int valor, contador;
	Celula *p, *p2;
	
	for (p = l; p->prox != l; p = p->prox){
		valor = p->dado;
		contador = 0;
		for (p2 = l; p2->prox != l; p2 = p2->prox) {
			if (valor == p2->dado) contador++;
			if (contador == 2) {
				listaDuplicados = inserirControleDuplicadosC(valor,listaDuplicados);
				break;
			}
		}
		if (valor == p2->dado) contador++;
		if (contador == 2) {
			listaDuplicados = inserirControleDuplicadosC(valor,listaDuplicados);	
		}
	}
	valor = p->dado;
	contador = 0;
	for (p2 = l; p2->prox != l; p2 = p2->prox) {
		if (valor == p2->dado) contador++;
		if (contador == 2) {
			listaDuplicados = inserirControleDuplicadosC(valor,listaDuplicados);
			break;
		}
	}
	if (valor == p2->dado) contador++;
	if (contador == 2) {
		listaDuplicados = inserirControleDuplicadosC(valor,listaDuplicados);	
	}
	printf("Valores que aparecem repetidos na lista:\n");
	exibirC(listaDuplicados);
}
//método que recebe uma lista e remove todos os pares da lista 
Celula *removerParesC(Celula *l) {
	Celula *p;
	if (!l) return l;
	
	for (p = l; p->prox != l; ) {
		if (p->dado % 2 == 0) {
			l = removerC(p->dado, l);
			p = l;
		} else p = p->prox; //soh avanca p se for impar
	}
	if (p->dado % 2 == 0) {
		l = removerC(p->dado, l);
		p = l;
	} 
	return l;
}

int main() {
	Celula *listaC = NULL;
	int numero;
	int i;
	srand(time(NULL));
	for (i = 0; i < 10; i++) {
		numero = rand() % 15;
		//printf("%d\n",numero);
		listaC = inserirC(numero, listaC);
	}
	//exibirC(listaC);
	//printf("Informe um numero para pesquisa: ");
	//scanf("%d", &numero);
	//listaC = removerC(numero, listaC);
	exibirC(listaC);
		switch (tipoLista(listaC)) {
    	case 0 : printf("Lista vazia.\n");
    	         break;
		case 1 : printf("Lista circular.\n");
    	         break;    	         
    	case 2 : printf("Lista simples.\n");
    	         break; 
		default : printf("opsss\n");   	         
    }
	printf("A lista no final tem %d elementos\n", contaElementosC(listaC));
	mostrarRepetidosC(listaC);
	
	printf("Lista sem os numeros pares....\n");
    listaC = removerParesC(listaC);
    exibirC(listaC);
	return 1;
}
