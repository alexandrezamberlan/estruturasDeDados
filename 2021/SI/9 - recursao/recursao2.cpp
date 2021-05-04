#include <iostream>
#define TAM 4
using namespace std;

void imprimirCrescente(int *vetor, int n) {
    for (int i = 0; i < n; i++) {
        cout << vetor[i] << endl;
    }
}
                                    //(A) 
void imprimirCrescenteR(int *vetor, int n) {
    if (n > 0) { //(B)
        //tudo que vem antes do ponto da recursão é executado no empilhamento, ou no chamamento do método
        imprimirCrescenteR(vetor, n - 1); //ponto da recursão (C)
        //tudo que vem depois do ponto da recursão é executado no desempilhamento, ou no retorno do método
        cout << vetor[n - 1] << endl;
        
    }
}

int main() {
    int vetor[TAM];

    for (int i = 0; i < TAM; i++) {
        cout << "Informe um valor inteiro: ";
        cin >> vetor[i];
    }
    
    imprimirCrescente(vetor, TAM);
    cout << "Recursivo: " << endl;
    imprimirCrescenteR(vetor, TAM);
    return 1;
}
/*
MEMÓRIA RAM
    imprimirCrescenteR(2) cout
    imprimirCrescenteR(3) empi + cout
    imprimirCrescenteR(4) empi + cout
main
*/