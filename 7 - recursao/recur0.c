#include <stdio.h>
#include <stdlib.h>


void exibeFaixa(int ini, int fim) {
    for (; ini <= fim; ini++) {
        printf("%d\n", ini);
    }
}

// void exibeFaixaR(int ini, int fim) {
//     if (ini <= fim) {
//         //códigos executados no empilhamento
//         printf("%d\n",ini);
//         exibeFaixaR(ini + 1, fim);

//         //códigos executados no desempilhamento
        
//     }

// }

void exibeFaixaR(int ini, int fim) {
    if (ini <= fim) {
        //códigos executados no empilhamento
        
        exibeFaixaR(ini, fim - 1);

        //códigos executados no desempilhamento
        printf("%d\n",fim);
    }
}

int main(){
	
    //exibeFaixa(1,50);
    exibeFaixaR(1,10);

	return 1;
}
