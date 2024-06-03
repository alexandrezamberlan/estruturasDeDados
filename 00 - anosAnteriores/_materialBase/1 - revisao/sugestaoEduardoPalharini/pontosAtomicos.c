// código produzido pelo Eduardo Palharini
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float x;
    float y;
    int massa;
}Ponto;

int verificando(char arquivo[], FILE **procurador, int pontos){
	char linha[200];	
	printf("Digite nome arquivo com pontos no Plano 2D: ");
    scanf("%s", arquivo);

    *procurador = fopen(arquivo, "r");

    if(!*procurador){
        printf("Arquivo nao encontrado, vai ser criado!\n");
        *procurador = fopen(arquivo,"a");
    } else {
        printf("Arquivo localizado e pronto para gravacao...\n");
    }
    while(fgets(linha, 200, *procurador)){
        pontos++;
    }
    fclose(*procurador);
    
    printf("\nEsse arquivo tem %d ponto(s):\n", pontos);
    
    return pontos;
}

void pegandoArquivo(Ponto vetor[], FILE **procurador, char arquivo[]){
	int i = 0;
	*procurador = fopen(arquivo, "r");
	do{
        fscanf(*procurador, "%f %f %d", &vetor[i].x, &vetor[i].y, &vetor[i].massa);
        i++;
    }while(!feof(*procurador));
    
    fclose(*procurador);
}

void popula(FILE **procurador, char arquivo[]){
	float x,y;
    int massa;
    int opcao = 0;
    
	*procurador = fopen(arquivo, "a");
	do {
        printf("Pressione CRTL+C para encerrar ou informe dados no arquivo!\n");
        do{
			printf("X (-1 a 1): ");
	        scanf("%f", &x);
	    }while(x < -1 || x > 1);

	    do{
		    printf("Y (-1 a 1): ");
	        scanf("%f", &y);
		}while(y < -1 || y > 1);
        
		do{
			printf("Massa (0 - 100): ");
	        scanf("%d", &massa);
		}while(massa < 0 || massa > 100);

        fprintf(*procurador,"%.2f\t%.2f\t%d\n", x, y, massa);
        fflush(*procurador);
        
        printf("Diga qual opcao seguir(-1 para sair): ");
        scanf("%d", &opcao);
        
    } while(opcao == 0);
    
    fclose(*procurador);
}

void exibe(Ponto vetor[], int tamanho){
	int i;
	printf("------------------------------- \n");
	for(i = 0; i < tamanho; i++){
        printf("%.2f\t%.2f\t%d \n", vetor[i].x, vetor[i].y, vetor[i].massa);
    }
}

int main(){

	char nomeArquivo[200];
    FILE *procurador;
    int totalPontos = 0;	
    
    totalPontos = verificando(nomeArquivo, &procurador, totalPontos);
    Ponto *vetor = (Ponto *)malloc(sizeof(Ponto)* totalPontos);
    
	pegandoArquivo(vetor, &procurador, nomeArquivo);
	
    popula(&procurador, nomeArquivo);
	
	exibe(vetor, totalPontos);
	free(vetor);
	
    return 0;
}
