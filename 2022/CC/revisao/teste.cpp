#include <iostream>
#include <string>
#define TAM 4

using namespace std;

typedef struct {
    int matricula;
    string nome;
} Pessoa;

void popular(Pessoa vetor[], int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        cout << "Informe nome da pessoa: ";
        cin >> vetor[i].nome;
        vetor[i].matricula = (rand() % 100) + 100;
    }
}

void exibir(Pessoa vetor[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Pessoa " << (i+1) << ": " << vetor[i].matricula << " - " << vetor[i].nome << endl;
    }
}

int main() {
    Pessoa vetor[TAM];
    
    system("clear"); //no windows system("cls")
    cout << "Revisando struct, vetor e metodos \n";
    popular(vetor, TAM);
    exibir(vetor, TAM);

    return 1;
}