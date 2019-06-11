#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;
} Celula;

Celula *abrirArquivoPopularPilha(Celula *topo);
Celula *inserir(int valor, Celula *topo);
int contarPilha(Celula *topo);
void exibir(Celula *topo);
double calcularMedia(Celula *topo);
void mostrarModa(Celula *topo);

int main() {
    Celula *pilha = NULL;

    pilha = abrirArquivoPopularPilha(pilha);
    
	if (!pilha) exit(0);
    
	printf("Dados glicemicos: \n");
    exibir(pilha);
    printf("Ha %d dados de glicemia no arquivo\n", contarPilha(pilha));
    printf("A media de dados glicemicos eh %.2f\n", calcularMedia(pilha));
    mostrarModa(pilha);

    return 1;
}

Celula *abrirArquivoPopularPilha(Celula *topo) {
    FILE *procurador;
    char nomeArquivo[200];
    int glicemia;

    printf("Informe nome arquivo com dados glicemicos: ");
    scanf("%s", nomeArquivo);
    fflush(stdin);

    procurador = fopen(nomeArquivo,"r");
    if (!procurador) {
        printf("Arquivo nao encontrado ou invalido\n");
        return topo;
    }

    for (;1;) {
        fscanf(procurador,"%d",&glicemia);
        if (feof(procurador)) {
            break;
        }
        topo = inserir(glicemia,topo);
    }
    fclose(procurador);
    return topo;
}

Celula *inserir(int valor, Celula *topo){
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    novo->dado = valor;
    novo->prox = topo;

    return novo;
}

int contarPilha(Celula *topo) {
    Celula *p;
    int conta = 0;

    for (p = topo; p; p = p->prox, conta++);

    return conta;
}

void exibir(Celula *topo) {
    Celula *p;

	if (!topo) printf("Pilha vazia");

    for (p = topo; p; p = p->prox) {
        printf("%d\n", p->dado);
    }
}

double calcularMedia(Celula *topo) {
    Celula *p;
    int soma = 0; 
	int conta = 0;
	
	if (!topo) return 0.0;
	
    for (p = topo; p; p = p->prox) {
    	soma = soma + p->dado;
    	conta++;
    }

    return soma/conta;
}

void mostrarModa(Celula *topo){
	Celula *p;
	Celula *pControleGeral = topo;
	int valorAnalisado;
	int qtdVezesAparece;
	
	int valorModa = 0;
	int qtdValorModa = 0;
	
	if (!topo || (contarPilha(topo) < 3)) {
		printf("Pilha vazia ou dados insuficientes para a moda");
		return;	
	}

	for (pControleGeral = topo; pControleGeral; pControleGeral = pControleGeral->prox) {
		
		valorAnalisado = pControleGeral->dado;
		qtdVezesAparece = 0;
		
	    for (p = topo; p; p = p->prox) {
	        if (p->dado == valorAnalisado) qtdVezesAparece++;
	    }
	    
	    if (qtdVezesAparece > 1) {
	    	if (qtdVezesAparece >= qtdValorModa) {
				valorModa = valorAnalisado;
	    		qtdValorModa = qtdVezesAparece;
	    	}	
	    } 
	}
	
	printf("O %d eh o valor que aparece %d vezez\n", valorModa, qtdValorModa);
}

