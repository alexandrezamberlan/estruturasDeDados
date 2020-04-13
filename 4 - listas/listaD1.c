#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

//Celula serve tanto para lista simples quanto para lista circular
typedef struct nodo {
	int conteudo;
	struct nodo *ant;
    struct nodo *prox;
} CelulaD;


int main() {
    setlocale(LC_ALL,"Portuguese");
    
    return 1;
}