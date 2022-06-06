//Recursão é uma técnica computacional que substitui as instruções de repetição via empilhamento de métodos.
//Substitui o for(); while(); do-while()

//Ideia básica de uma repetição:
//A - inicialização da variável de controle
//B - teste de parada/continuação usando a variável de controle
//C - transformação da variável de controle

#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct no {
    int dado;
    struct no *prox;
} Celula;

//inserir na lista de forma ordenada tendo como chave o valorGlicemia
Celula *inserirListaR(int valor, Celula *lista) {
    if (lista && valor > lista->dado) {
        lista->prox = inserirListaR(valor, lista->prox);
        return lista;
    } else {
        //alocar memoria
        Celula *novo = (Celula*)malloc(sizeof(Celula));

        //depositar valores
        novo->dado = valor;
        novo->prox = NULL;
        return novo;
    }
}


void exibirLista(Celula *lista) { //A
  Celula *p;
  p = lista; //A
  while (p) { //B
    cout << p->dado << endl;
    p = p->prox; //C
  }
}

void exibirListaR(Celula *lista) { //A
  
  if (lista) { //B
    //tudo que está acima do ponto de recursão é executado no empilhamento
      
    exibirListaR(lista->prox); //C -> ponto de recursão

    //tudo que está abaixo do ponto de recursão é executado no desempilhamento, ou na volta do processo
    cout << lista->dado << endl;
  } 
}

Celula *destruirR(Celula *lista) { //A
    if (lista) { //B
        //tudo que está acima do ponto de recursão é executado no empilhamento

        lista->prox = destruirR(lista->prox); //C

        //tudo que está abaixo do ponto de recursão é executado no desempilhamento, ou na volta do processo
        free(lista);
    }
    return NULL;
}


int main() {

    Celula *lista = NULL;

    lista = inserirListaR(10, lista);
    lista = inserirListaR(20, lista);
    lista = inserirListaR(30, lista);
    lista = inserirListaR(40, lista);
  
    lista = destruirR(lista);

    cout << "Exibindo a lista \n";
    exibirListaR(lista);


    return 1;
}