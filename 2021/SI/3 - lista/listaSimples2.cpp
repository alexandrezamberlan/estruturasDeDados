#include <iostream>
using namespace std;

typedef struct nodo {
    int valor; // um ou mais atributos ou variávies
    //poderia ter outras variáveis
    struct nodo *prox;
} Celula;

Celula *inserir(int valor, Celula *lista);
void exibir(Celula *lista);
int contarElementos(Celula *lista);

int main() {
    Celula *lista = NULL;
    int valor;
    system("clear");
    do {
        cout << "Informe um valor inteiro para a lista (-1 sai do programa): ";
        cin >> valor;
        if (valor == -1) break;

        lista = inserir(valor,lista);
    } while (1);

    exibir(lista);

    cout << "A lista possui " << contarElementos(lista) << " elementos" << endl;

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
    Celula *p;

    for (p = lista; p->prox != NULL; p = p->prox) {
        if (valor == p->valor) {
            cout << "valor ja inserido na lista!\n";
            free(novo); //libera a alocação pq o valor ja está na lista
            return lista;
        }
    }

    //engatar na última posição
    p->prox = novo; //ultimo elemento vai apontar agora para o novo elemento alocado

    //retornar o primeiro elemento
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