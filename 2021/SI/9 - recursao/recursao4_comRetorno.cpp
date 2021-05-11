#include <iostream>
#define TAM 5
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

int somarElementos(int *vetor, int n) {
    int soma, i;
    for (i = 0, soma = 0; i < n; i++) {
        soma = soma + vetor[i];
    }
    return soma;
}

int somarElementosR(int *vetor, int n) {
    if (n > 0) {
        int soma = vetor[n - 1] + somarElementosR(vetor, n - 1);
        return soma; //é a volta do empilhamento levando um valor para o método de baixo
    } else {
      return 0;  //é quando a recursão atingiu o topo e o desempilhamento começa a funcionar
    }
}

int contarParesR(int *vetor, int n) {
    if (n > 0) {
        int contaPares;
        if (vetor[n - 1] % 2 == 0) contaPares = 1 + contarParesR(vetor, n - 1);
        else contaPares = 0 + contarParesR(vetor, n - 1);
        return contaPares;
    } else {
        return 0;
    }
}

int somarParesR(int *vetor, int n) {
    if (n > 0) {
        int somaPares;
        if (vetor[n - 1] % 2 == 0) somaPares = vetor[n - 1] + somarParesR(vetor, n - 1);
        else somaPares = 0 + somarParesR(vetor, n - 1);
        return somaPares;
    } else {
        return 0;
    }
}

int main() {
    int vetor[TAM];
    
    popularR(vetor, TAM);
    exibirR(vetor, TAM);
    
    cout << endl;
    cout << "A soma dos elementos do vetor é: " << somarElementosR(vetor, TAM) << endl;
    cout << endl;

    cout << "A quantidade de números pares no vetor é: " << contarParesR(vetor, TAM) << endl;
    cout << endl;

    cout << "A soma dos elementos pares no vetor é: " << somarParesR(vetor, TAM) << endl;
    cout << endl;
    
    return 1;
}
