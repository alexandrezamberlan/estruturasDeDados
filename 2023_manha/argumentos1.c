#include <stdio.h>
#include <stdlib.h>

int main(int qtdArgumentos, char **vetorArgumentos) {

    printf("Total de argumentos: %d\n", qtdArgumentos);
    for (int i = 1; i < qtdArgumentos; i++) {
        printf("Argumento %d: %s\n", i, vetorArgumentos[i]);
    }
    return 1;
}