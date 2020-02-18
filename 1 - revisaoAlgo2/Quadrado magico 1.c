#include <stdio.h>
#include <stdlib.h>


int main(){
    int dimensao;
    int **quadrado;
    int coluna, linha;
    int lin,col;

    printf("Digite a dimensao de 3 a 21: ");
    scanf("%d",&dimensao);
    if(dimensao < 3 || dimensao > 21 || dimensao % 2 == 0){
        printf("dimensao invalida!");
        exit(0);
    }
    for(int i=0; i< dimensao; i++){
        quadrado = (int *)malloc(sizeof(int) * dimensao);
    }

    for(int i=0; i< dimensao; i++){
        quadrado[i] = malloc(sizeof(int) * dimensao);
    }

    for (linha = 0; linha < dimensao; linha++) {
        for (coluna = 0; coluna < dimensao; coluna++) {
            quadrado[linha][coluna] = 0;
        }
    }

    linha = dimensao - 1;
    coluna = (int)dimensao / 2;
    quadrado[linha][coluna] = 1;

    for (int a = 2; a <= dimensao*dimensao; a++) {
        lin = linha;
        linha++;
        if (linha == dimensao) linha = 0;

        col = coluna;
        coluna++;
        if (coluna == dimensao) coluna = 0;

        if (quadrado[linha][coluna] == 0) {
            quadrado[linha][coluna] = a;
        } else {
            linha = lin - 1;
            coluna = col;
            quadrado[linha][coluna] = a;
        }
    }

    for (linha = 0; linha < dimensao; linha++) {
        for (coluna = 0; coluna < dimensao; coluna++) {
            printf("%d\t",quadrado[linha][coluna]);
        }
        printf("\n");
    }


    free(quadrado);
    return 1;
}
