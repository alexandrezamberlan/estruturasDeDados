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

void exibirParesR(int *vetor, int n) { //A n como variavel de controle sendo inicializada na passagem do parametro
    if (n > 0) { //B teste de para usando a variavel de controle
        exibirParesR(vetor, n - 1); //C -> ponto da recursao onde a variavel de controle é transformada
        if (vetor[n-1] % 2 == 0) {
            cout << vetor[n-1] << endl;
        }
    }
}



int main() {
    int vetor[] = {1, 2, 3, 4, 5, 6};
    int n = 6;

    exibirParesR(vetor, n);

    return 1;
}