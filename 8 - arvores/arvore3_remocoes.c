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

Arvore *localizar(int valor, Arvore *r){
	if (r) {
		if (valor == r->conteudo) return r; //conteudo localizado
		if (valor < r->conteudo) return localizar(valor, r->esq); //procurar na esquerda
		/*else*/ return localizar(valor, r->dir);
	}
	return NULL;
}

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

int calcularAltura(Arvore *r) {
	if (r) {
		int alturaEsquerda = calcularAltura(r->esq);
		int alturaDireita = calcularAltura(r->dir);
		
		if (alturaEsquerda > alturaDireita) return 1 + alturaEsquerda;
		return 1 + alturaDireita;
	}
	return 0;
}

Arvore *excluir(int valor, Arvore *r) {
	if (r) {
		if (valor == r->conteudo) { //valor encontrado
			//excluir
			//1o pergunta: é folha?
			if (!r->esq && !r->dir) {
				free(r);
				return NULL;
			} 
			//2o pergunta: tem só um filho
			if ((r->esq && !r->dir) || (!r->esq && r->dir)) {
				Arvore *novoPai;
				if (r->esq) novoPai = r->esq;
				else novoPai = r->dir;
				free(r);
				return novoPai;
			} else {
				//Se estamos aqui, é porque o valor a ser excluído está em nodo com 2 filhos
				Arvore *novoPai = r->esq;
				Arvore *temp = novoPai->dir;
				Arvore *p;
				novoPai->dir = r->dir;
				
				free(r);
				if (temp) {
					for (p = novoPai; p->esq; p = p->esq);
					p->esq = temp;
				}
				return novoPai;
			}
		}
		if (valor < r->conteudo) {
			//ir para esquerda
			r->esq = excluir(valor, r->esq);
		} else {
			//ir para direita
			r->dir = excluir(valor, r->dir);
		}
		return r;
	}
	return NULL; //valor não será excluído, pq não foi localizado
}

//excluir todas as ocorrencias
Arvore *excluirTodasAsOcorrencias(int valor, Arvore *r) {
	//????
}

int main() {
	Arvore *raiz = NULL;
	int i, valor;
	srand(time(NULL));
	
	printf("Gerando numeros aleatorios para a arvore\n");
	for (i = 0; i < TAM; i++){
		valor = rand() % 10;
		//printf("%d\t", valor);
		raiz = inserir(valor, raiz);
	}
	
	printf("Exibe arvore deitada a partir do nivel 0\n");
	exibir(raiz, 0);

	printf("A altura da árvore é: %d\n", calcularAltura(raiz));
	printf("Total de nós folhas: %d\n", contarNosFolhas(raiz));
	
	printf("\nInforme um inteiro para pesquisa na arvore: ");
	scanf("%d", &valor);
	
	printf("Nivel de %d na arvore: %d\n", valor, localizarNivel(valor, raiz));

	raiz = excluirTodasAsOcorrencias(valor,raiz);
	printf("Exibe arvore após tentativa de exclusão\n");
	exibir(raiz, 0);
	
	return 1;
}
