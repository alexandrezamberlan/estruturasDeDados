#include <iostream>
#include <time.h>
using namespace std;

typedef struct nodo {
    int valor; // um ou mais atributos ou variávies
    //poderia ter outras variáveis
    struct nodo *prox;
} Celula;

Celula *inserirC(int valor, Celula *lista);
void exibirC(Celula *lista);
int contarElementosC(Celula *lista);
string mostrarOndeEstaC(int valor, Celula *lista) ;

int main() {
    Celula *listaC = NULL;
    int valor, qtdNumeros;

    cout << "Quantos números quer gerar para a lista? ";
    cin >> qtdNumeros; 

    srand(time(NULL));
    for (int i = 0; i < qtdNumeros; i++) {
        valor = rand() % 100;
        listaC = inserirC(valor,listaC);
    } 

    exibirC(listaC);

    cout << "A lista circular possui " << contarElementosC(listaC) << " elementos" << endl;
    
    cout << "Digite um valor para pesquisa: ";
    cin >> valor;


    string posicao = mostrarOndeEstaC(valor,listaC);
    cout << "O valor está: " << posicao << endl;

    return 1;
}

Celula *inserirC(int valor, Celula *lista) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores de parâmetro
    novo->valor = valor;

    if (!lista) {
        novo->prox = novo; //o único elemento deve apontar pra si mesmo
        return novo; //se a lista for vazia, o novo será o primeiro e único elemento nela
    }

    //percorrer toda a lista e inserir na última posição
    Celula *p, *pR;
    for (pR = NULL, p = lista; p->prox != lista ; pR = p, p = p->prox){ //percurso para parar o p no último elemento
        if (valor <= p->valor) { //encontramos a posição do valor
            break;        
        }
    }

    //existem 2 motivos para sair do for:
    //1o pq o break executou - ou o valor pode ser o primeiro ou pode estar no meio
    if (p == lista && valor <= p->valor) {
        novo->prox = lista; //novo->prox = p;
        
        for (pR = lista; pR->prox != lista; pR = pR->prox); //levar o pR pro final da lista para que aponte para o novo
        
        pR->prox = novo;
        return novo;
    }

    //2o se encontrou e é o último
    if (p->prox == lista && p->valor < valor) {
        p->prox = novo;
        novo->prox = lista;
        return lista;
    }
    //não é o primeiro e nem o último, ou seja, está no meio
    pR->prox = novo;
    novo->prox = p;
    return lista;

}

void exibirC(Celula *lista) {
    Celula *p;

    if (!lista) {
        cout << "Lista vazia!\n";
        return;
    }
    for (p = lista; p->prox != lista; p = p->prox) { //percurso clássico em listas circulares
        cout << p->valor << "\n";
    }
    cout << p->valor << "\n";
}

int contarElementosC(Celula *lista) { //lista contém o endereco do 1o elemento
   Celula *p;
   int contador = 0;

    if (!lista) {
        return contador;
    }
    for (p = lista; p->prox != lista; p = p->prox) { //percurso clássico em listas circulares
        contador++;
    } 
    
    return ++contador;
}

string mostrarOndeEstaC(int valor, Celula *lista) {
    if (!lista) return "Lista vazia";

    Celula *p;
    for (p = lista; p->prox != lista; p = p->prox) {
        if (valor == p->valor) {
            //verificar se é o primeiro
            if (p == lista) {
                return "na primeira posição";
            }
            //verificar se é o último
            if (p->prox == lista) {
                return "na última posição";
            }
            //está no meio
            return "no meio";
        }
    }
    if (valor == p->valor) {
        //verificar se é o primeiro
        if (p == lista) {
            return "na primeira posição";
        }
        //verificar se é o último
        if (p->prox == lista) {
            return "na última posição";
        }
    }
    return "ausente";
}