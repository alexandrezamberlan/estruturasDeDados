//Recursão é uma técnica computacional que substitui as instruções de repetição via empilhamento de métodos.
//Substitui o for(); while(); do-while()

//Ideia básica de uma repetição:
//A - inicialização da variável de controle
//B - teste de parada/continuação usando a variável de controle
//C - transformação da variável de controle

#include <iostream>
#include <cstdlib>
using namespace std;


int main() {
    
    
    int i = 0; // A
    while (i < 10) { //B
        cout << "oi";
        i++; //C
    }

    int i = 0; // A
    do {
        cout << "oi";
        i++; //C
    } while (i < 10); //B

    for (int i = 0; i < 10; i++){

    }

    return 1;
}