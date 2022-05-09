//Recursão é uma técnica computacional que substitui as instruções de repetição via empilhamento de métodos.
//Substitui o for(); while(); do-while()

//Ideia básica de uma repetição:
//A - inicialização da variável de controle
//B - teste de parada/continuação usando a variável de controle
//C - transformação da variável de controle

//No universo de recursão (empilhamento de processos), há duas categorias:
//1 - métodos recursivos sem retorno (void)
//2 - métodos recursivos com retorno no ponto onde a recursão foi chamada (return)


// Recursão é o autochamamento de um método. Ou seja, um método se chama e empilha a si mesmo.

#include <iostream>
#include <cstdlib>
using namespace std;

void escreverDecrescente(int valor) { //A

    while (valor > 0) { //B
        cout << valor << endl;
        valor--; //C
    }
}

void escreverDecrescenteR(int valor) { //A
    if (valor > 0) { //B

        //tudo que está acima do ponto de recursão é executado no empilhamento
        cout << valor << endl;

        escreverDecrescenteR(valor - 1); //C ->ponto de recursão

        //tudo que está abaixo do ponto de recursão é executado no desempilhamento, ou na volta do processo
    }
}

void escreverCrescenteR(int valor) { //A
    if (valor > 0) { //B

        //tudo que está acima do ponto de recursão é executado no empilhamento

        escreverCrescenteR(valor - 1); //C ->ponto de recursão

        //tudo que está abaixo do ponto de recursão é executado no desempilhamento, ou na volta do processo
        cout << valor << endl;
    }
}

int main() {
    cout << "decrescente\n";
    escreverDecrescenteR(9);

    cout << "crescente\n";
    escreverCrescenteR(9);

    return 1;
}