//C - gerar arquivo de texto n particulas em plano cartesiano x,y
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char nomeArquivo[200]; //todo vetor/matriz eh um ponteiro
    FILE *procurador;
    int qtdParticulas;
    int x,y;
    


    printf("Nome do arquivo de saida contendo as particulas: ");
    scanf("%s", nomeArquivo);

    procurador = fopen(nomeArquivo,"w");
    printf("Arquivo criado com sucesso!\n");

    printf("Quantas particulas quer gerar? ");
    scanf("%d", &qtdParticulas);

    srand(time(NULL));
    for (; qtdParticulas > 0; qtdParticulas--) {
        x = 100 - rand() % 200; 
        y = 100 - rand() % 200;
        //printf("%d,%d\n",x,y);              //tela
        fprintf(procurador,"%d,%d\n",x,y);  //arquivo texto - plain text   
        fflush(procurador);
    }

    fclose(procurador);
    return 1;
}