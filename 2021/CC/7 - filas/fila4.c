#include <stdio.h> //biblioteca nativa do C dentro da pasta lib
#include <stdlib.h> //biblioteca nativa do C dentro da pasta lib
#include "lib/delay.h" //biblioteca construída pelo programador
#include "lib/fila.h" //bibliteca construída pelo programador

int main() {
    Fila filaNormal;
    Fila filaPrioritaria;

    //inicializar as filas
    filaNormal = inicializar(filaNormal);
    filaPrioritaria = inicializar(filaPrioritaria);
    int opcao;
    int senhaNormal = 100;
    int senhaPrioritaria = 500;
    int senha;
    int contaAtendimentos = 0;

    do {
        system("clear"); //system("cls");
        printf("1 - Senha Normal\n");
        printf("2 - Senha Prioritária\n");
        printf("3 - Atendimento\n");
        printf("4 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: //fila normal
                    printf("Bem vindo(a)... sua senha normal é N%d\n", senhaNormal);
                    filaNormal = inserir(senhaNormal,filaNormal);
                    senhaNormal++;
                    delay(2000);
                    break;
            case 2: //fila prioritária
                    printf("Bem vindo(a)... sua senha prioritária é P%d\n", senhaPrioritaria);
                    filaPrioritaria = inserir(senhaPrioritaria, filaPrioritaria);
                    senhaPrioritaria++;
                    delay(2000);
                    break;
            case 3: //atendimento -> para cada 3 atendimentos normais, atender um prioritário
                    if (contaAtendimentos % 3 == 0) {
                        filaPrioritaria = remover(filaPrioritaria, &senha);
                        if (senha != -27) {
                                printf("Atenção... chamando a senha P%d\n", senha); 
                                delay(2000);
                        }
                    } else {
                        filaNormal = remover(filaNormal, &senha);
                        if (senha != -27) {
                                printf("Atenção... chamando a senha N%d\n", senha); 
                                delay(2000);
                        }
                    }
                    contaAtendimentos++;
                    break;
            case 4: 
                    break;
            default : printf("Opção inválida.");
                      delay(2000);
        }
    } while(opcao != 4);

    return 1;
}

