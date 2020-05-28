#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int proximo(int valor) {
    return ++valor; //ou valor + 1; //mas jamais valor++;
}

int main() {
    printf("Teste: %d\n", proximo(8));
    return 1;
}