#include <iostream>
#include <stdlib.h>
#include <string>
#include <locale> 
#include <cctype>
#include <cstdio>

using namespace std;

void receberFraseLetra(string *frase, char *letra);
int contarLetraNaFrase(string frase, char letra);

int main() {
    string frase;
    char letra;
    system("clear");

    //metodo para receber uma frase qualquer e um caracter qualquer
    receberFraseLetra(&frase, &letra);

    // cout << "Frase digitada: " << frase << endl;
    // cout << "Letra digitada: " << letra << endl;

    //metodo que receba a frase e o caracter e retorne quantas vezes o
    //caracter aparece na frase (minúsculo ou maiúsculo)
    int quantasVezes = contarLetraNaFrase(frase, letra);
    cout << "A letra aparece "  << quantasVezes << " vezes na frase " << frase << endl; 

    return 1;
}


void receberFraseLetra(string *frase, char *letra) {
    cout << "Digite uma frase: ";
    getline(cin,*frase);
    
    transform((*frase).begin(), (*frase).end(), (*frase).begin(), ::toupper); 

    cout << "Digite um caracter qualquer: ";
    cin >> *letra;    
}

int contarLetraNaFrase(string frase, char letra) {
    int conta = 0;
    for (int i = 0; i < frase.length(); i++) {
        if (frase[i] == letra) {
            conta++;
        }
    }
    return conta++;
}