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


void exibirR(int *vetor, int n) { //A com o n
    if (n > 0) { //B
        //tudo que está acima do ponto de recursão é executado no empilhamento

        exibirR(vetor, n-1); //C ->ponto de recursão
        
        //tudo que está abaixo do ponto de recursão é executado no desempilhamento, ou na volta do processo
        cout << vetor[n - 1] << endl;
    }
    
}

int main() {
    int vetor[] = {10, 20, 30, 40};
    int n = 4;

    exibirR(vetor, n);

    return 1;
}