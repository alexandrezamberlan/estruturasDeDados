#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 5
typedef struct {
    char placa[8];
    char dataEntrada[11];
    char horaEntrada[6];
    char dataSaida[11];
    char horaSaida[6];
    float taxa;
}Vaga;

void inicializarVetor(Vaga *vetor, int n);
void gerirGaragem(Vaga *vetor, int n);
int taNaGaragem(char placa[], Vaga *vetor, int n);
void entrarGaragem(char placa[], Vaga *vetor, int n);
void sairGaragem(char placa[], Vaga *vetor, int posicaoPlaca);
void exibirGaragem(Vaga *vetor, int n);
void gravarEntrada(Vaga *vetor, int n);
void gravarSaida(Vaga vaga);
void exibirHistoricoGaragem();

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
                    exibirGaragem(vetor, TAM);
                    break;
            case 3: printf("Carros que passaram pela garagem desde seu inicio\n");
                    exibirHistoricoGaragem();
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
			if (feof(procurador)) break;
			i++;
    	}
    }
    for (; i < n; i++) {
        strcpy(vetor[i].placa," ");
        strcpy(vetor[i].dataEntrada," ");
        strcpy(vetor[i].horaEntrada," ");
        strcpy(vetor[i].dataSaida," ");
        strcpy(vetor[i].horaSaida," ");
        vetor[i].taxa = 0.00;
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
	srand(time(NULL));
    printf("Data saida [dd/mm/aaaa]: ");
    scanf("%s",vetor[posicaoPlaca].dataSaida);
    fflush(stdin);
    printf("Hora saida [hh:mm]: ");
    scanf("%s",vetor[posicaoPlaca].horaSaida);
    fflush(stdin);
    //realizar calculo de cobranca
    vetor[posicaoPlaca].taxa = rand()%100 + 10;
    //...
    printf("Valor final: %.2f\n", vetor[posicaoPlaca].taxa);
    //...gravar em arquivo de saida
    gravarSaida(vetor[posicaoPlaca]);
    
    //...
    //limpa vetor na posicaoPlaca
    strcpy(vetor[posicaoPlaca].placa," ");
    strcpy(vetor[posicaoPlaca].dataEntrada," ");
    strcpy(vetor[posicaoPlaca].horaEntrada," ");
    strcpy(vetor[posicaoPlaca].dataSaida," ");
    strcpy(vetor[posicaoPlaca].horaSaida," ");
    vetor[posicaoPlaca].taxa = 0.00;
    
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

void gravarSaida(Vaga vaga) {
	FILE *procurador;
	
	procurador = fopen("saida.txt","a");
	
	fprintf(procurador,"%s %s %s %s %s %.2f\n", vaga.placa, vaga.dataEntrada, vaga.horaEntrada, vaga.dataSaida, 
	                                            vaga.horaSaida, vaga.taxa);	
	fclose(procurador);
}

void exibirHistoricoGaragem() {
	FILE *procurador;
	float totalNaGaragem = 0;
	Vaga vaga;
	
	procurador = fopen("saida.txt","r");
	if (!procurador) {
		printf("\n\nSem hitorico de garagem...\n\n");
		return;
	}
	
	while (!feof(procurador)) {
    	fscanf(procurador,"%s %s %s %s %s %f", vaga.placa, vaga.dataEntrada, vaga.horaEntrada, 
		                                       vaga.dataSaida, vaga.horaSaida, &vaga.taxa);
		if (feof(procurador)) break;
		
	    totalNaGaragem = totalNaGaragem + vaga.taxa;
	    printf("Placa: %s - Entrada: %s %s - Saida: %s %s - Cobrado: %.2f\n", vaga.placa, vaga.dataEntrada, vaga.horaEntrada, 
                                                                              vaga.dataSaida, vaga.horaSaida, vaga.taxa);
    }
    printf("Total recebido do historico: %.2f\n\n", totalNaGaragem);
}







