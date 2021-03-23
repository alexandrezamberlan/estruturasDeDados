#include <iostream>
#include <string>
using namespace std;

typedef struct nodo {
    int valor; // um ou mais atributos ou variávies
    //poderia ter outras variáveis
    struct nodo *prox;
} Celula;

//relação de protótipos
Celula *inserir(int valor, Celula *lista);
void exibir(Celula *lista);

int main() {
    Celula *lista = NULL;
    int valor;

    do {
        cout << "Informe um valor inteiro para a lista (-1 sai do programa): ";
        cin >> valor;
        if (valor == -1) break;

        lista = inserir(valor,lista);
    } while (1);

    exibir(lista);

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
        if (valor <= p->valor) { //encontramos a posição do valor
            break;        
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
        cout << p->valor << "\t";
    }
    cout << endl;
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