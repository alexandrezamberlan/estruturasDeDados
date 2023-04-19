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
    Celula ficha;
    do {
        system("cls");
        printf("1 - Ficha normal\n");
        printf("2 - Ficha prioritaria\n");
        printf("3 - Chama ficha\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                //exibir a ficha ou imprimir a ficha
                printf("Ficha normal gerada: %d\n", contadorFilaNormal);
                inserirFila(contadorFilaNormal, &filaNormal);
                contadorFilaNormal++;
                break;
            case 2:
                //exibir a ficha ou imprimir a ficha
                printf("Ficha prioritaria gerada: %d\n", contadorFilaPrioritaria);
                inserirFila(contadorFilaPrioritaria, &filaPrioritaria);
                contadorFilaPrioritaria++;
                break;
            case 3:
                //definir qual fila atender
                if (contadorAtendimentos % 3 == 0) {
                    ficha = removerFila(&filaPrioritaria);
                    if (ficha.conteudo != -27) {
                        printf("Chamando ficha prioritaria: %d - %02d/%02d/%d %02d:%02d\n", ficha.conteudo, ficha.dataHora.tm_mday, ficha.dataHora.tm_mon + 1, ficha.dataHora.tm_year + 1900, ficha.dataHora.tm_hour, ficha.dataHora.tm_min);
                        contadorAtendimentos++;
                    } else {
                        if (filaNormal.cabeca != NULL) {
                            ficha = removerFila(&filaNormal);
                            printf("Chamando ficha normal: %d - %02d/%02d/%d %02d:%02d\n", ficha.conteudo, ficha.dataHora.tm_mday, ficha.dataHora.tm_mon + 1, ficha.dataHora.tm_year + 1900, ficha.dataHora.tm_hour, ficha.dataHora.tm_min);
                        }
                    }
                } else {
                    ficha = removerFila(&filaNormal);
                    if (ficha.conteudo != -27) {
                        printf("Chamando ficha normal: %d - %02d/%02d/%d %02d:%02d\n", ficha.conteudo, ficha.dataHora.tm_mday, ficha.dataHora.tm_mon + 1, ficha.dataHora.tm_year + 1900, ficha.dataHora.tm_hour, ficha.dataHora.tm_min);
                        contadorAtendimentos++;
                    } else {
                        if (filaPrioritaria.cabeca != NULL) {
                            ficha = removerFila(&filaPrioritaria);
                            printf("Chamando ficha prioritaria: %d - %02d/%02d/%d %02d:%02d\n", ficha.conteudo, ficha.dataHora.tm_mday, ficha.dataHora.tm_mon + 1, ficha.dataHora.tm_year + 1900, ficha.dataHora.tm_hour, ficha.dataHora.tm_min);
                        }
                    }
                }
                break;
            case 4:
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
        system("pause");
    } while (opcao != 4);

    return 1;
}