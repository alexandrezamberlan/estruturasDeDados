#include <iostream>
using namespace std;

void imprimirCrescente(int n) {
    for (int i = 0; i < n; i++) {
        cout << i << endl;
    }
}
                          //(A) 
void imprimirCrescenteR(int n) {
    if (n >= 0) { //(B)
        //tudo que vem antes do ponto da recursão é executado no empilhamento, ou no chamamento do método
        imprimirCrescenteR(n - 1); //ponto da recursão (C)
        //tudo que vem depois do ponto da recursão é executado no desempilhamento, ou no retorno do método
        cout << n << endl;
    }
}

int main() {
    int valor;
    cout << "Informe um valor inteiro: ";
    cin >> valor;
    imprimirCrescente(valor);
    cout << "Recursivo: " << endl;
    imprimirCrescenteR(valor);
    return 1;
}
/*
MEMÓRIA RAM
    imprimirCrescenteR(2) cout
    imprimirCrescenteR(3) empi + cout
    imprimirCrescenteR(4) empi + cout
main
*/