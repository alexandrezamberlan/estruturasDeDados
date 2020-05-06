#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 8

typedef struct no {
	int conteudo;
	struct no *prox;
} Celula;

/**
 * 
 * RECURSÃO == repetir por empilhamento (sistema operacional)
 * - chamar o mesmo método e empilhá-lo
 * - com métodos sem retorno (void) e com retorno (return)
 * 
 * - vantagem da recursão é executar códigos no desempilhamento
 * - desvantagem da recursão é o consumo de memória
 * 
 * - ter consciência que 3 pontos sejam garantidos:
 *    - Ponto A: inicialização da varia'vel de controle (fica no parâmetro)
 *    - Ponto B: teste de parada (primeiro if)
 *    - Ponto C: transformação da variável de controle sendo usada na chamda recursiva
 * 
 * */

Celula *inserirR(int valor, Celula *l) {		
	if (l && valor > l->conteudo) {
		//percorria - empilhar
		l->prox = inserirR(valor, l->prox);
		return l;
	} else { //sai da lista
		//aloca
		Celula *novo = (Celula *)malloc(sizeof(Celula));
		//deposita
		novo->conteudo = valor;
		novo->prox = l;
		
		//retorna
		return novo;
	}
}

void exibirR(Celula *lista) {
    if (lista) {
        printf("%d\t",lista->conteudo);
        exibirR(lista->prox);
    }
}

int contarR(Celula *lista) {
    if (lista) {
        return 1 + contarR(lista->prox);
    }
    return 0;
}

// int contarR(Celula *lista) {
//     if (lista) {
//         int r = contarR(lista->prox);
//         //geralmente usa-se variável para poder avaliar o que vem do empilhamento
//         return 1 + r;
//     }
//     return 0;
// }

int somarR(Celula *lista) {
    if (lista) {
        return lista->conteudo + somarR(lista->prox);
    }
    return 0;
}

// int somarR(Celula *lista) {
//     if (lista) {
//         int r = somarR(lista->prox);
//         //geralmente usa-se variável para poder avaliar o que vem do empilhamento
//         return lista->conteudo + r;
//     }
//     return 0;
// }


// A   B     C   .
//12 -> 24 -> 56 ->.
Celula *localizarR(int valor, Celula *lista) {
    if (lista) {
        if (valor == lista->conteudo) {
            return lista;
        }
        return localizarR(valor, lista->prox);
    }
    return NULL;
}



int main() {
    srand(time(NULL));
    Celula *lista = NULL;

    lista = inserirR(12,lista);
    lista = inserirR(24,lista);
    lista = inserirR(56,lista);

    exibirR(lista);

    printf("\nA lista tem %d elementos\n", contarR(lista));
    printf("A soma dos elementos da lista é: %d\n", somarR(lista));

    printf("Dado 56 está na lista? %p\n",localizarR(56,lista));

    printf("A posição lógica do 56 é: %d\n", posicaoLogicaR(56,lista));

    return 1;
}