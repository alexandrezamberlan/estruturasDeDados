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

Celula *popular(Celula *lista, int quantidade) {
    srand(time(NULL));
    int i;
    for (i = 0; i < quantidade; i++ ) {
        lista = inserir(rand() % 100, lista);
    }

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

void exibirR(Celula *lista) { //inicialização da variável de controle
    if (lista) { //teste de parada
        printf("%d\t", lista->conteudo); //código do empilhamento
        exibirR(lista->prox); //ponto de recursão com a transformação da variável de controle
    }
}

void exibirParesImparesR(Celula *lista) { //inicialização variável de controle
    if (lista) { //teste de parada usando a variável de controle
        //no empilhamento
        if (lista->conteudo % 2 == 0){
            printf("%d\t", lista->conteudo);
        }

        exibirParesImparesR(lista->prox); //ponto de recursão com a transformação da variável de controle

        //no desempilhamento
        if (lista->conteudo % 2 != 0) {
            printf("%d\t", lista->conteudo);
        }
    }
}

int contar(Celula *lista) {
    Celula *p;
    int conta = 0;
    for (p = lista; p; p = p->prox, conta++);

    return conta;
}


int contarR(Celula *lista) { //inicialização da variável de controle no parâmetro
    if (lista) { //teste de parada usando a variável de controle
        int c = contarR(lista->prox); //para o método que me chamou
        return 1 + c;
    }
    return 0; //para o método que me chamou ... ponto de descida
}

int somarR(Celula *lista) { //inicialização da variável de controle no parâmetro
    if (lista) { //teste de parada usando a variável de controle
        return lista->conteudo + somarR(lista->prox); //para o método que me chamou
    }
    return 0; //para o método que me chamou ... ponto de descida
}

int maiorR(Celula *lista) {
    if (lista->prox) {
        int oQueVemDeCima = maiorR(lista->prox);
        if (oQueVemDeCima > lista->conteudo)
            return oQueVemDeCima;
        return lista->conteudo;
    }
    return lista->conteudo;
}

// A              
 
Celula *destruirR(Celula *lista) {
    if (lista) {    
        lista->prox = destruirR(lista->prox);
        free(lista);
        return NULL;
    }
    return NULL;
}

int main() {
    setlocale(LC_ALL,"Portuguese");
	Celula *lista = NULL;
    
    lista = popular(lista,10);
    printf("A lista contém: %d números sorteados\n", contarR(lista));
    exibirR(lista);
    printf("A soma dos elementos da lista é: %d\n", somarR(lista));
    printf("O maior elemento da lista é: %d\n", maiorR(lista)); //supondo que a lista não está ordenada

    lista = destruirR(lista);

	return 1;
}








