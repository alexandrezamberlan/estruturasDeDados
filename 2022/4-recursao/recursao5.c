#include <stdio.h>
#include <stdlib.h>

void exibirAntesEmpilhamentoDepoisEmpilhamento(int valor) {
    if (valor > 0) {
        printf("antes.... %d\n", valor);
        exibirAntesEmpilhamentoDepoisEmpilhamento(valor - 1);
        printf("depois.... %d\n", valor);
    }
}
int main() {
    exibirAntesEmpilhamentoDepoisEmpilhamento(5);
    return 1;
}
