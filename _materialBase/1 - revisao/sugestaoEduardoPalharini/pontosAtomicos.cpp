// código produzido pelo Eduardo Palharini
#include <stdlib.h>
#include <iostream>
#include <iomanip>//para utilizar a precis�o decimal em cout no void exibe;

using namespace std;

typedef struct{
    float x;
    float y;
    int massa;
}Ponto;

int verificando(char arquivo[], FILE **procurador, int pontos){
	char linha[200];	
	cout << "Digite nome arquivo com pontos no Plano 2D: ";
    cin >> arquivo;

    *procurador = fopen(arquivo, "r");

    if(!*procurador){
        cout << "Arquivo nao encontrado, vai ser criado!" << endl;
        *procurador = fopen(arquivo, "a");
    } else {
        cout << "Arquivo localizado e pronto para gravacao...\n" << endl;
    }
    while(fgets(linha, 200, *procurador)){
        pontos++;
    }
    fclose(*procurador);
    
    cout << "Esse arquivo tem " << pontos << " ponto(s)!" << endl;
    
    return pontos;
}

void pegandoArquivo(Ponto vetor[], FILE *procurador, char arquivo[]){
	int i = 0;//serve apenas de indice para o procurador
	procurador = fopen(arquivo, "r");
	do{
        fscanf(procurador, "%f %f %d", &vetor[i].x, &vetor[i].y, &vetor[i].massa);
        i++;
    }while(!feof(procurador));
    
    fclose(procurador);
}

void popula(FILE **procurador, char arquivo[]){
	float x,y;
    int massa;
    int opcao = 0;
    
	*procurador = fopen(arquivo, "a");
	do {
        cout << "Pressione CRTL+C para encerrar ou informe dados no arquivo.!" << endl;
	    do{
			cout << "X (-1 a 1): ";
	        cin >> x;
		}while(x < -1 || x > 1);
	    
		do{  
			cout << "Y (-1 a 1): ";
	        cin >> y;
		}while(y < -1 || x > 1);
        
		do{
			cout << "Massa (0-100): ";
	        cin >> massa;
		}while(massa < 0 || massa > 100);

        fprintf(*procurador,"%.2f\t%.2f\t%d\n", x, y, massa);
        fflush(*procurador);//ja desepejo da memoria para o arquivo
        
        cout << "Diga qual opcao seguir(-1 para sair): ";
        cin >> opcao;
        
    } while(opcao == 0);
    fclose(*procurador);
}

void exibe(Ponto vetor[], int tamanho){
	int i;
	cout << "-------------------------------" << endl;
	for(i = 0; i < tamanho; i++){
        cout << fixed << setprecision(2);
		cout << vetor[i].x << "\t" << vetor[i].y << "\t" << vetor[i].massa << endl;
    }
}

int main(){

	char nomeArquivo[200];
    FILE *procurador;
    int totalPontos = 0;	
    
    totalPontos = verificando(nomeArquivo, &procurador, totalPontos);
    Ponto *vetor = (Ponto *)malloc(sizeof(Ponto)* totalPontos);
    
	pegandoArquivo(vetor, procurador, nomeArquivo);
	
    popula(&procurador, nomeArquivo);
	
	exibe(vetor, totalPontos);
	free(vetor);
	
    return 0;
}
