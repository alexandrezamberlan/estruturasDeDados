#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int  *popularVetor(int *v, int *qtd);
void ordenarVetor(int *v, int qtd);
void exibirVetor(int *v, int qtd);


int main() {
    int *vetor;
    int quantidade;
    srand(time(NULL));

    //metodo que recebe um vetor e qtd de números a popular o vetor
    //com números aleatórios
    //usuário que informa a quantidade de números
    vetor = popularVetor(vetor, &quantidade); //passagem de parâmetro por referência, tanto em vetor, quanto em quantidade
    
    //método para ordenar o vetor de forma crescente
    ordenarVetor(vetor, quantidade); //passagem de parâmetor por valor/cópia na variável quantidade

    //método que exibie o vetor ordenado
    exibirVetor(vetor, quantidade); //passagem de parâmetor por valor/cópia na variável quantidade

    return 1;
}

int *popularVetor(int *v, int *qtd) {
    cout << "Quantos números quer gerar? ";
    cin >> *qtd; //isso indica que estamos acessando direto a variável quantidade que está no main
    v = (int *)malloc(*qtd * sizeof(int)); //alocação dinâmica de elementos em v
    
    for (int i = 0; i < *qtd; i++) {
        v[i] = rand() % 100;
    }

    return v;
}

void ordenarVetor(int *v, int qtd) { //algoritmo da bolha - bubble sort
    bool houveTroca;
    int tmp;

    do {
        houveTroca = false;
        for (int i = 0; i < qtd - 1; i++) {
            if (v[i] > v[i+1]) {
                houveTroca = true;
                tmp = v[i];
                v[i] = v[i+1];
                v[i+1] = tmp;
            }
        }
    } while (houveTroca);
}

void exibirVetor(int *v, int qtd) {
    for (int i = 0; i < qtd; i++) {
        cout << v[i] << "  ";
    }
    cout << endl;
}


