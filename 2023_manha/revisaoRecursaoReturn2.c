#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 3

void inicializarR(int *v, int n, int valor) {
    if (n > 0) {
        //codigo no empilhamento

        inicializarR(v, n - 1, valor);
        
        //codigo no desempilhamento
        v[n - 1] = valor;
    }
}

void exibirR(int *v, int n) {
    if (n > 0) {
        //codigo no empilhamento

        exibirR(v, n - 1);
        
        //codigo no desempilhamento
        printf("[%d]:%d\n",n - 1, v[n - 1]);
    }
}

void popularR(int *v, int n, int valor) {
    if (n > 0) {
        //codigo no empilhamento
       
        popularR(v, n - 1, valor);
        
        //codigo no desempilhamento
        v[n - 1] = rand() % valor;
    }
}

int somarR(int *v, int n) {    
    if (n > 0) {
        int resposta = v[n - 1] + somarR(v, n - 1);
        return resposta;
    } else {
        return 0; //ponto da volta da recursão
    }
}

int somarParesR(int *v, int n) {    
    if (n > 0) {
        int resposta;
        if (v[n - 1] % 2 == 0) {
           resposta = v[n - 1] + somarParesR(v, n - 1);
        } else {
            resposta = 0 + somarParesR(v, n - 1);
        }
        return resposta;
    } else {
        return 0; //ponto da volta da recursão
    }
}

int localizarR(int *v, int n, int valor) {
    if (n > 0) {
        if (v[n - 1] == valor) {
            return n - 1; //valor localizado, retorna a posicao, começa a desempilhar
        } 
        return localizarR(v, n - 1, valor);        
    }
    return -1; //passou por toda a estrutura e nao localizou o valor... ponto desempilhamento
}


int main() {
    int vetor[TAM];

    srand(time(NULL));
    inicializarR(vetor, TAM, 0);
    popularR(vetor, TAM, 50);
    exibirR(vetor, TAM);


    printf("A soma dos elementos do vetor: %d\n", somarR(vetor, TAM));
    printf("A soma dos elementos pares do vetor: %d\n", somarParesR(vetor, TAM));

    int valor;
    printf("Digite valor para pesquisa: ");
    scanf("%d", &valor);
    int posicao = localizarR(vetor, TAM, valor);
    if (posicao != -1) {
        printf("Localizado na posicao: %d\n", posicao);
    } else {
        printf("Nao localizado\n");
    }


    return 1;
}