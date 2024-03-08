#include <iostream>
#include <string> 
#include <ctime>

using namespace std;

typedef struct no {
    int valor;
    struct no *prox;
} Lista;

Lista *inserir(int valor, Lista *lista) {
    //alocar memoria
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    
    //depositar conteudos do parametro
    novo->valor = valor;
    novo->prox = NULL;

    //localizar posicao na estrutura
    Lista *pR, *p;
    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) {
        
        if (novo->valor < p->valor) {
            break;
        }
    }
    //eh o primeiro
    if (p == lista) {
        novo->prox = lista;
        return novo;
    }
    //eh o ultimo
    if (!p) {
        pR->prox = novo;
        return lista;
    }
    //esta em algum lugar do meio
    pR->prox = novo;
    novo->prox = p;

    //retornar o inicio da lista
    return lista;
}

bool contido(int valor, Lista *lista) {
    if (!lista) {
        return false;
    }

    Lista *p;
    for (p = lista; p; p = p->prox) {
        if (valor == p->valor){
            return true;
        }
    }
    return false;
}

void exibir(Lista *lista) {
    if (!lista){
        return; 
    }

    Lista *p;
    for (p = lista; p; p = p->prox) {
        cout << p->valor << endl;
    }
}

int main() {
    Lista *listaNumeros = NULL;
    int valor;
    system("cls");
    while (true) {
        cout << "Digite um valor ou 0 para finalizar: ";
        cin >> valor;

        if (valor == 0) {
            break;
        }

        //testar se já cadastrado
        if (!contido(valor,listaNumeros)) {
            //inserir o nome na lista
            listaNumeros = inserir(valor,listaNumeros); //insercao com ordenação
        } else {
            cout << "Numero ja cadastrado" << endl;
        }        
    }

    exibir(listaNumeros);

    return 1;
}