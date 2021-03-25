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
int contarElementos(Celula *lista);
int pegarValorMeio(Celula *lista);


int main() {
    Celula *lista = NULL;
    
    int valor, qtdNumeros;

    system("clear");

    cout << "Quantos números quer gerar para a lista? ";
    cin >> qtdNumeros;

    srand(time(NULL));
    for (int i = 0; i < qtdNumeros; i++) {
        valor = rand() % 100;
        lista = inserir(valor,lista);
    } 
    cout << "Lista " << endl;
    exibir(lista);
    
    cout << "O valor do meio da lista é: " << pegarValorMeio(lista) << endl;
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


int pegarValorMeio(Celula *lista) {
    if (!lista) return -27; //código de lista vazia

    int quantidade = contarElementos(lista);

    if (quantidade == 1 || quantidade == 2) {
        return lista->valor;
    }

    quantidade = (int)quantidade / 2;

    int i;
    Celula *p;
    for (i = 0, p = lista; i < quantidade; i++, p = p->prox); //leva o p ao meio

    return p->valor;
}