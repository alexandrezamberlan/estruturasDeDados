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
int contarElementos(Celula *lista);
string mostrarOndeEsta(int valor, Celula *lista);

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

    cout << "A lista possui " << contarElementos(lista) << " elementos" << endl;

    //rotina para pesquisar um valor e informar onde está na lista: primeiro, último, meio (alguma porção do meio)
    cout << "Digite um valor para pesquisar: ";
    cin >> valor;

    string posicao = mostrarOndeEsta(valor,lista);
    cout << "O valor está: " << posicao << endl;

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
    for (p = lista; p->prox != NULL; p = p->prox);

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