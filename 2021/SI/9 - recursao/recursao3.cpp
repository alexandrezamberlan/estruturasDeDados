#include <iostream>
#define TAM 10
using namespace std;

void popularR(int *vetor, int n) {
    if (n > 0) {
        cout << "Informe um valor inteiro: ";
        cin >> vetor[n - 1];

        popularR(vetor, n - 1);
        
        //volta do empilhamento
    }
    //código para o desempilhamento
}

void exibirR(int *vetor, int n) {
    if (n > 0) {
        
        cout << vetor[n - 1] << "\t";
        exibirR(vetor, n - 1);

        
         //volta do empilhamento
    }
    //código para o desempilhamento
}

void exibirParesNaSubidaImparesNaDescidaR(int *vetor, int n) {
    if (n > 0) {
        
        if (vetor[n - 1] % 2 == 0) {
            cout << vetor[n - 1] << "\t";
        }

        exibirParesNaSubidaImparesNaDescidaR(vetor, n - 1);
        
        if (vetor[n - 1] % 2 != 0) {
            cout << vetor[n - 1] << "\t";
        }
        
         //volta do empilhamento
    }
    //código para o desempilhamento
}


int main() {
    int vetor[TAM];
    
    popularR(vetor, TAM);
    exibirR(vetor, TAM);
    
    cout << endl;
    exibirParesNaSubidaImparesNaDescidaR(vetor,TAM);
    cout << endl;
    
    return 1;
}
/*
MEMÓRIA RAM
    imprimirCrescenteR(2) cout
    imprimirCrescenteR(3) empi + cout
    imprimirCrescenteR(4) empi + cout
main
*/