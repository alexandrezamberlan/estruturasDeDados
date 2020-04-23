#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//tipo para a celula, como em pilhas e listas simples
typedef struct nodo {
	int conteudo;
	struct nodo *prox;
} Celula;

//tipo para armazenar os dois ponteiros da fila
typedef struct {
	Celula *cabeca; //operacao de remocao
	Celula *cauda;  //operacao de insercao
} Fila;

/*
metodo que incializa a fila
*/
void inicializar(Fila *f) {
	f->cabeca = NULL;
	f->cauda = NULL;
}

/*
metodo que insere um elemento na cauda da fila
*/
void inserir(int valor, Fila *f) {
	Celula *novo;

	novo = (Celula *)malloc(sizeof(Celula));
	novo->conteudo = valor;
	novo->prox = NULL;

	//eh a primeira vez?
	if (!f->cauda) {
		f->cauda = novo;
		f->cabeca = novo;
	} else {
		f->cauda->prox = novo;
		f->cauda = novo;
	}
}

/*
metodo que remove elemento da cabeca da fila
*/
int remover(Fila *f) {
	Celula *lixo;
    int ficha;
	//fila existe?
	if (f->cabeca) {
		ficha = f->cabeca->conteudo;
		lixo = f->cabeca;
		f->cabeca = f->cabeca->prox;
		free(lixo);

		//caso apague o ultimo elemento
		if (!f->cabeca) {
			f->cauda = NULL;
		}
		return ficha;
	} 
	return -27;
}

void menu(Fila *filaNormal, Fila *filaPrioritaria, int *contadorFichaNormal, int *contadorFichaPrioritaria) {
    int opcao;
    int contadorAtendimentos = 1; //usado para a regra do negócio

    do {
        printf("1 - Gerar Ficha Normal (1 a 999)\n");
        printf("2 - Gerar Ficha Prioritária (1000 - 1999)\n");
        printf("3 - Atender\n");
        printf("4 - Sair\n");
        printf("Opção; ");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            inserir(*contadorFichaNormal, filaNormal);
            printf("Você retirou a ficha normal: %d\n\n", *contadorFichaNormal);
            *contadorFichaNormal = *contadorFichaNormal + 1;
            break;
        case 2:
            inserir(*contadorFichaPrioritaria, filaPrioritaria);
            printf("Você retirou a ficha prioritária: %d\n\n", *contadorFichaPrioritaria);
            *contadorFichaPrioritaria = *contadorFichaPrioritaria + 1;
            break;
        case 3:
            //regra do negócio.... a cada 3 fichas normais atendidas, uma prioritária é chamada
            if (contadorAtendimentos % 3 == 0) {
                int ficha = remover(filaPrioritaria); 
                if (ficha != -27) {
                    printf("Chamando ficha prioritária: %d\n\n", ficha);
                }
            } else {
                int ficha = remover(filaNormal);
                if (ficha != -27) {
                    printf("Chamando ficha normal: %d\n\n", ficha);
                }
            }
            contadorAtendimentos++;
            break;    
        case 4:
            printf("Sistema finalizado\n");
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    } while (opcao != 4);
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    
    int contadorFichaNormal = 1;
    int contadorFichaPrioritaria = 1000;

    Fila normal, prioritaria;
    inicializar(&normal);
    inicializar(&prioritaria);
    
    menu(&normal, &prioritaria, &contadorFichaNormal, &contadorFichaPrioritaria);
    
    return 1;
}