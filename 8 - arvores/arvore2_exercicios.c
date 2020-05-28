#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAM 10

typedef struct no { //arvore binaria
	int conteudo;
	struct no *esq, *dir;
}Arvore;

Arvore *inserir(int valor, Arvore *r) { //Arvore Binaria de Pesquisa ou Ordenada
	if (r) {
		if (valor < r->conteudo) r->esq = inserir(valor, r->esq); //vai para esquerda
		else r->dir = inserir(valor, r->dir); //vai para direita
		
		return r;
	} else {
		Arvore *novo = (Arvore *)malloc(sizeof(Arvore));
		novo->conteudo = valor;
		novo->esq = NULL;
		novo->dir = NULL;
		return novo;
	}
}
//codigo do livro C Completo e Total de Robert Schild
void exibir(Arvore *r, int nivel) {
	if (r) {
		exibir(r->dir, nivel + 1);//vai para direita
		
		int i;
		for (i = 0; i < nivel; i++) {
			printf("   ");
		}
		printf("(%d)%d\n", nivel, r->conteudo);
		
		exibir(r->esq, nivel + 1);//vai para esquerda
	}
}
/*
1. Escreva uma função que receba como parâmetros: um ponteiro para a raiz de uma árvore 
binária de pesquisa; e um valor inteiro. Ao final, esse método deverá retornar quantos 
nós da árvore são múltiplos do valor inteiro passado como parâmetro.
*/
int multiplos(Arvore *r, int valor) {
	if (r) {
		if (r->conteudo % valor == 0) {
			return 1 + multiplos(r->esq, valor) + multiplos(r->dir,valor);
		}
		return 0 + multiplos(r->esq, valor) + multiplos(r->dir,valor);
	}
	return 0;
}

/*
3. Escreva um método que receba como parâmetro um ponteiro para a raiz de uma árvore 
binária de pesquisa. O método deverá retirar todos os nós folhas, ou seja, realizar a 
poda.
*/
Arvore *podar(Arvore *r) { //tem alteração na árvore
	if (r) {
		if (!r->esq && !r->dir) {
			//encontrado uma folha e será excluída
			free(r);
			return NULL;//para o pai dele
		}
		r->esq = podar(r->esq);
		r->dir = podar(r->dir);

		return r; //retorna o nodo que não é folha
	}
	return NULL;
}

/*
4. Escreva uma função que receba como parâmetros um ponteiro apontando para a raiz da 
árvore binária de pesquisa e um valor inteiro. Faça com que a função delete o valor caso 
localizado na Árvore e se estiver em nodo folha.
*/
Arvore *excluirElementoFolha(Arvore *r, int valor) {
	if (r) {
		if (valor == r->conteudo) {
			if (!r->esq && !r->dir) { //é folha
				free(r);
				return NULL;
			} 
		}
		if (valor < r->esq) r->esq = excluirElementoFolha(r->esq, valor);
		else r->dir = excluirElementoFolha(r->dir, valor);
		
		return r;
	}
	return NULL;
}

/*
5. Escreva um método que receba como parâmetro um ponteiro para a raiz de uma árvore 
binária de pesquisa. O método deverá retirar todos os nós da árvore. (destruir)
*/
Arvore *destruir(Arvore *r) {
	if (r) {
		r->esq = destruir(r->esq);//vai para esquerda
		r->dir = destruir(r->dir);//vai para direita

		free(r); //visita raiz
	}
	return NULL;
}

/*
7. Construa uma função que receba como parâmetro um ponteiro apontando para a raiz de 
uma árvore binária de pesquisa e retorne um valor indicando verdadeiro se a árvore 
existir e se os nós de maior e menor valor da árvore estiverem no mesmo nível. 
Por valor do nó, entenda-se o conteúdo armazenado no campo valor.
*/
int maiorMenorMesmoNivel(Arvore *r) {
	Arvore *p;
	int contaNivelMenor = 0, contaNivelMaior = 0;

	if (!r) return -1;

	for (p = r; p->esq; p = p->esq, contaNivelMenor++);

	for (p = r; p->dir; p = p->dir, contaNivelMaior++);

	return contaNivelMenor == contaNivelMaior;
}

/*
9. Escreva uma função que receba como parâmetro um ponteiro para a raiz de uma árvore 
binária de pesquisa e retorne um ponteiro para o nó NÃO FOLHA de maior valor.
*/
int maiorNaoFolha(Arvore *r) {
	Arvore *p, *pR;
	if (!r) return -27;

	for (pR = NULL, p = r; p->dir; pR = p, p = p->dir);

	if (!p->esq) return pR->conteudo;

	return p->conteudo;
}

/*
10. Escreva uma função que receba como parâmetros: (i) um ponteiro para a raiz de uma 
árvore binária de pesquisa; (ii) valor inteiro em n. A função deverá contar os nós da 
árvore que NÃO estão na subárvore que tem em sua raiz o valor n (se houver esse nó). 
Se esse nó não existir, devem ser contados todos os nós da árvore, e se ele for a raiz 
recebida como parâmetro, a contagem deve ser 0 (zero). O resultado da contagem deve ser 
retornado. Não use variáveis globais.
*/
int exercicio10(Arvore *r, int n) {
	if (r) {
		if (n == r->conteudo) return 0;
		return 1 + exercicio10(r->esq, n) + exercicio10(r->dir, n)
	}
	return 0;
}

/*
11. Escreva uma função que receba como parâmetros um ponteiro apontando para a raiz 
da árvore binária de pesquisa e dois valores inteiros M e N. Faça com que a função 
verifique se existe um nó com valor igual a M no caminho entre a raiz e o nó de valor 
igual a N. Se existir, a função deve retornar a diferença entre os níveis dos dois nós. 
Se N não existir na árvore, ou se M não existir no caminho até N, deve ser retornado o 
valor -1.
*/
Arvore *localizar(int valor, Arvore *r){
	if (r) {
		if (valor == r->conteudo) return r; //conteudo localizado
		if (valor < r->conteudo) return localizar(valor, r->esq); //procurar na esquerda
		/*else*/ return localizar(valor, r->dir); //procura na direita
	}
	return NULL;
}

/*
2. Escreva uma função que receba dois parâmetros: um valor inteiro e um ponteiro para o 
primeiro elemento de uma árvore binária de pesquisa. A função deverá retornar o nível 
que se encontra esse valor inteiro na árvore. Lembrando que o primeiro nível é Zero, 
segundo é Um e assim por diante. Caso o valor não esteja na árvore, retornar -1.
*/
int localizarNivel(int valor, Arvore *r) {
	if (r) {
		if (valor == r->conteudo) return 0;
		if (valor < r->conteudo)  {
			//vai para esquerda
			int nivel = localizarNivel(valor, r->esq);
			if (nivel == -1) return -1;
			else return nivel + 1;
		} else {
			//vai para direita
			int nivel = localizarNivel(valor, r->dir);
			if (nivel == -1) return -1;
			else return nivel + 1;
		}
	}
	return -1; //se chegou aqui, pq o valor não foi encontrado
}


int contarNos(Arvore *r) {
	if (r) {
		return 1 + contarNos(r->esq) + contarNos(r->dir);
	}
	return 0;
}

int contarNosFolhas(Arvore *r) {
	if (r) {
		if (!r->esq && !r->dir) {
			return 1; //+ contarNosFolhas(r->esq) + contarNosFolhas(r->dir);
		}
		return  0 + contarNosFolhas(r->esq) + contarNosFolhas(r->dir);
	}
	return 0;
}

int contarNosNaoFolhas(Arvore *r) {
	if (r) {
		if (!r->esq && !r->dir) {
			return 0; //+ contarNosFolhas(r->esq) + contarNosFolhas(r->dir);
		}
		return 1 + contarNosNaoFolhas(r->esq) + contarNosNaoFolhas(r->dir);
	}
	return 0;
}

void mostrarNosFolhas(Arvore *r) {
	if (r) {
		mostrarNosFolhas(r->esq);

		if (!r->esq && !r->dir) {
			printf("%d\t",r->conteudo);
		} 

		mostrarNosFolhas(r->dir);
	}
}

int somarNos(Arvore *r) {
	if (r) {
		return r->conteudo+ somarNos(r->esq) + somarNos(r->dir);
	}
	return 0;
}

/*
6. Construa uma função que receba como parâmetro um ponteiro apontando para a raiz de 
uma árvore binária e retorne a altura dessa árvore.
*/
int calcularAltura(Arvore *r) {
	if (r) {
		int alturaEsquerda = calcularAltura(r->esq);
		int alturaDireita = calcularAltura(r->dir);
		
		if (alturaEsquerda > alturaDireita) return 1 + alturaEsquerda;
		return 1 + alturaDireita;
	}
	return 0;
}

int main() {
	Arvore *raiz = NULL;
	int i, valor;
	srand(time(NULL));
	
	printf("Gerando numeros aleatorios para a arvore\n");
	for (i = 0; i < TAM; i++){
		valor = rand() % 100;
		//printf("%d\t", valor);
		raiz = inserir(valor, raiz);
	}
	
	printf("Exibe arvore deitada a partir do nivel 0\n");
	exibir(raiz, 0);

	printf("A altura da árvore é: %d\n", calcularAltura(raiz));
	printf("Total de nós folhas: %d\n", contarNosFolhas(raiz));
	mostrarNosFolhas(raiz);

	printf("\n\nMaior valor não folha: %d\n", maiorNaoFolha(raiz));
	// printf("\n\nMaior e menor estão no mesmo nível? %d\n", maiorMenorMesmoNivel(raiz));
	
	// printf("\nInforme um inteiro para pesquisa na arvore: ");
	// scanf("%d", &valor);

	// raiz = destruir(raiz);

	// printf("Exibe arvore deitada a partir do nivel 0\n");
	// exibir(raiz, 0);

	
	// printf("Nivel de %d na arvore: %d\n", valor, localizarNivel(valor, raiz));

	// raiz = podar(raiz);

	// printf("\n\nDepois da poda\n\n");
	// printf("Exibe arvore deitada a partir do nivel 0\n");
	// exibir(raiz, 0);

	// printf("A altura da árvore é: %d\n", calcularAltura(raiz));
	
	return 1;
}
