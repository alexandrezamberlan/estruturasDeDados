#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5
typedef struct {
    char placa[8];
    char dataEntrada[11];
    char horaEntrada[6];
    char dataSaida[11];
    char horaSaida[6];
    double taxa;
}Vaga;

void inicializarVetor(Vaga *vetor, int n);
void gerirGaragem(Vaga *vetor, int n);
int taNaGaragem(char placa[], Vaga *vetor, int n);
void entrarGaragem(char placa[], Vaga *vetor, int n);
void sairGaragem(char placa[], Vaga *vetor, int posicaoPlaca);
void exibirGaragem(Vaga *vetor, int n);
void gravarEntrada(Vaga *vetor, int n);

int main() {
    int opcao;
    Vaga vetor[TAM];
    inicializarVetor(vetor, TAM);
    do {
        printf("MENU\n");
        printf("1 - Gerir garagem\n");
        printf("2 - Listar carros em garagem\n");
        printf("3 - Listar geral\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d",&opcao);
        fflush(stdin);
        switch (opcao){
            case 1: printf("Gestao da garagem\n");
                    gerirGaragem(vetor,TAM);
                    break;
            case 2: printf("Carros em garagem\n");
                    int i;
                    exibirGaragem(vetor, TAM);
                    break;
            case 3: printf("Funcionalidade nao implementada\n");
                    break;
            case 4: printf("Sistema finalizado\n");
                    break;
            default: printf("Opcao invalida. Tente novamente\n");
        }
    } while (opcao != 4);
    //menu
    return 1;
}

void inicializarVetor(Vaga *vetor, int n) {
    int i;
    
    FILE *procurador = fopen("entrada.txt","r");
    i = 0;
    if (procurador) {
    	while (!feof(procurador)) {
    		fscanf(procurador,"%s %s %s", vetor[i].placa, vetor[i].dataEntrada, vetor[i].horaEntrada);
			i++;	
    	}
    }
    
    for (i = i - 1; i < n; i++) {
        strcpy(vetor[i].placa," ");
        strcpy(vetor[i].dataEntrada," ");
        strcpy(vetor[i].horaEntrada," ");
        strcpy(vetor[i].dataSaida," ");
        strcpy(vetor[i].horaSaida," ");
        vetor[i].taxa = 0;
    }
    if (procurador) fclose(procurador);
}

void gerirGaragem(Vaga *vetor, int n) {
    char placa[8];
    int posicaoPlaca = -1;

    printf("Placa: ");
    scanf("%s", placa);
    fflush(stdin);

    posicaoPlaca = taNaGaragem(placa, vetor, n);
    //printf("%d\n\n\n", posicaoPlaca);

    if (posicaoPlaca != -1) {
        //encontrado
        printf("Carro localizado\n");
        printf("Calculando taxas ....\n");
        sairGaragem(placa,vetor,posicaoPlaca);
    } else {
        //nao encontrado
        printf("Iniciando processo de entrada...\n");
        entrarGaragem(placa,vetor,n);
    }
}

int taNaGaragem(char placa[], Vaga *vetor, int n) {
    int i;

    for (i = 0; i < n; i++) {
        if (strcmp(vetor[i].placa, placa) == 0) {

            return i; //localizado
        }
    }
    return -1;//nao localizado
}

void entrarGaragem(char placa[], Vaga *vetor, int n) {
    int i;

    for (i = 0; i < n; i++) {
        if (strcmp(vetor[i].placa, " ") == 0) {
            //ponto de insercao da placa que entra
            strcpy(vetor[i].placa, placa);

            printf("Data entrada [dd/mm/aaaa]: ");
            scanf("%s",vetor[i].dataEntrada);
            fflush(stdin);
            printf("Hora entrada [hh:mm]: ");
            scanf("%s",vetor[i].horaEntrada);
            fflush(stdin);
            printf("Imprimindo o ticket.... e salvando em disco\n\n");
            gravarEntrada(vetor, n);
            return;
        }
    }
    printf("Desculpa. Garagem lotada....\n");
}

void sairGaragem(char placa[], Vaga *vetor, int posicaoPlaca) {
    printf("Data saida [dd/mm/aaaa]: ");
    scanf("%s",vetor[posicaoPlaca].dataSaida);
    fflush(stdin);
    printf("Hora saida [hh:mm]: ");
    scanf("%s",vetor[posicaoPlaca].horaSaida);
    fflush(stdin);
    //realizar calculo de cobranca
    //...
    printf("Valor final: %.1f\n", vetor[posicaoPlaca].taxa);
    //...
    //limpa vetor na posicaoPlaca
    int i;
    strcpy(vetor[posicaoPlaca].placa," ");
    strcpy(vetor[posicaoPlaca].dataEntrada," ");
    strcpy(vetor[posicaoPlaca].horaEntrada," ");
    strcpy(vetor[posicaoPlaca].dataSaida," ");
    strcpy(vetor[posicaoPlaca].horaSaida," ");
    vetor[posicaoPlaca].taxa = 0;
    
    //grava em arquivo entrada a saida do carro
    gravarEntrada(vetor, sizeof(vetor));
}

void exibirGaragem(Vaga *vetor, int n) {
	int i;
	for (i = 0; i < n; i++) {
    	if (strcmp(vetor[i].placa," ") != 0) {
			printf("Placa: %s - Entrada: %s - %s\n", vetor[i].placa, vetor[i].dataEntrada, vetor[i].horaEntrada);
		}
    }
}

void gravarEntrada(Vaga *vetor, int n) {
	FILE *procurador;
	int i;
	procurador = fopen("entrada.txt", "w");	
	
	for (i = 0; i < n; i++) {
    	if (strcmp(vetor[i].placa," ") != 0) {
			fprintf(procurador,"%s %s %s\n", vetor[i].placa, vetor[i].dataEntrada, vetor[i].horaEntrada);
		}
    }
	
	fclose(procurador); 
}








