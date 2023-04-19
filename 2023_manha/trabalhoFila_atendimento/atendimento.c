#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fila.h"

int main() {
    Fila filaNormal;
    Fila filaPrioritaria;
    int contadorFilaNormal = 1;
    int contadorFilaPrioritaria = 1000;
    int contadorAtendimentos = 0;
    inicializacao(&filaNormal);
    inicializacao(&filaPrioritaria);
    int opcao;
    do {
        printf("1 - Ficha normal\n");
        printf("2 - Ficha prioritaria\n");
        printf("3 - Chama ficha\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }

    } while (opcao != 4);

    return 1;
}