#include <stdio.h>
#include <stdlib.h>

long double fatorialR(int valor) {
    if (valor > 1) {
        return valor * fatorialR(valor - 1);
    }
    return 1;
}

int main() {
    int valor;
    printf("Digite um valor para calcular fatorial: ");
    scanf("%d", &valor);
    printf("O fatorial de %d é %.0Lf\n", valor, fatorialR(valor));
    return 1;
}
