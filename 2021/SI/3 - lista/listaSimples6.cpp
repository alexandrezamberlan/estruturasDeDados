#include <iostream>
#include <string>
#include <time.h>
using namespace std;

typedef struct nodo {
    int valor; // um ou mais atributos ou variávies
    //poderia ter outras variáveis
    struct nodo *prox;
} Celula;

//relação de protótipos
Celula *inserir(int valor, Celula *lista);
void exibir(Celula *lista);
void mostrarConjuncao(Celula *listaA, Celula *listaB);


int main() {
    Celula *listaA = NULL;
    Celula *listaB = NULL;
    int valor, qtdNumeros;

    system("clear");

    cout << "Quantos números quer gerar para a lista? ";
    cin >> qtdNumeros;

    srand(time(NULL));
    for (int i = 0; i < qtdNumeros; i++) {
        valor = rand() % 100;
        listaA = inserir(valor,listaA);
    } 
    cout << "Lista A " << endl;
    exibir(listaA);
    

    for (int i = 0; i < qtdNumeros; i++) {
        valor = rand() % 100;
        listaB = inserir(valor,listaB);
    } 
    cout << "Lista B " << endl;
    exibir(listaB);

    mostrarConjuncao(listaA, listaB);

    return 1;
}

Celula *inserir(int valor, Celula *lista) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores de parâmetro
    novo->valor = valor;
    novo->prox = NULL;

    if (!lista) return novo; //se a lista for vazia, o novo será o primeiro elemento nela

    //percorrer toda a lista e inserir na última posição
    Celula *p, *pR;
    for (pR = NULL, p = lista; p != NULL; pR = p, p = p->prox) {
        if (valor == p->valor) {
            free(novo);
            cout << valor << " há inserido na lista" << endl;
            return lista;
        }
        if (valor <= p->valor) { //encontramos a posição do valor
            break;  //sai do for      
        }
    }
    //existem 2 motivos para sair do for:
    //1o pq o p chegou no final da lista - sabe-se então que o valor será o último elemento
    if (!p) {
        pR->prox = novo;
        return lista;
    }
    //2o pq o break executou - ou o valor pode ser o primeiro ou pode estar no meio
    if (p == lista) {
        novo->prox = lista; //novo->prox = p;
        return novo;
    }
    //não é o primeiro e nem o último, ou seja, está no meio
    pR->prox = novo;
    novo->prox = p;
    return lista;

}

void exibir(Celula *lista) {
    Celula *p;

    if (!lista) {
        cout << "Lista vazia!\n";
        return;
    }
    for (p = lista; p != NULL; p = p->prox) { //percurso clássico em listas
        cout << p->valor << "\n";
    }
    cout << endl;
}

string mostrarOndeEsta(int valor, Celula *lista) {
    if (!lista) return "Lista vazia";

    Celula *p;
    for (p = lista; p != NULL; p = p->prox) {
        if (valor == p->valor) {
            //verificar se é o primeiro
            if (p == lista) {
                return "na primeira posição";
            }
            //verificar se é o último
            if (p->prox == NULL) {
                return "na última posição";
            }
            //está no meio
            return "no meio";
        }
    }
    return "ausente";
}

int contarElementos(Celula *lista) {
   Celula *p;
   int contador = 0;

    if (!lista) {
        return contador;
    }
    for (p = lista; p != NULL; p = p->prox) { //percurso clássico em listas
        contador++;
    } 
    return contador;
}

int somarElementos(Celula *lista) {
   Celula *p;
   int soma = 0;

    if (!lista) {
        return soma;
    }
    for (p = lista; p != NULL; p = p->prox) { //percurso clássico em listas
        soma = soma + p->valor;
    } 
    return soma;
}

void mostrarConjuncao(Celula *listaA, Celula *listaB) {
    Celula *p1, *p2;

    for (p1 = listaA; p1 != NULL; p1 = p1->prox) {
        for (p2 = listaB; p2 != NULL; p2 = p2->prox) {
            if (p1->valor == p2->valor) {
                cout << p1->valor << " aparece nas duas listas" << endl;
            }
        }
    }
} 
