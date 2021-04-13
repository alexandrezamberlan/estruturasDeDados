#include <iostream>
using namespace std;

typedef struct nodo {
    int valor; // um ou mais atributos ou variávies
    struct nodo *ant; //guarda o endereço do elemento anterior
    struct nodo *prox;//guardo o endereço do próximo elemento
} CelulaD;

CelulaD *inserirD(int valor, CelulaD *lista);
void exibirD(CelulaD *lista);
int contarElementosD(CelulaD *lista);
int somarElementosD(CelulaD *lista);
CelulaD *localizarValorD(int valor, CelulaD *lista);

int main() {
    CelulaD *lista = NULL;
    int valor;
    system("clear");

    do {
        cout << "Informe um valor inteiro para a lista (-1 sai do programa): ";
        cin >> valor;
        if (valor == -1) break;

        lista = inserirD(valor,lista);
    } while (1);

    exibirD(lista);
    cout << "A lista possui " << contarElementosD(lista) << " elementos" << endl;

    cout << "Informe um valor para pesquisa: ";
    cin >> valor;

    cout << "O valor encontra-se na lista na posição: " << localizarValorD(valor, lista) << endl;

    return 1;
}

CelulaD *inserirD(int valor, CelulaD *lista) {
    //alocar memória
    CelulaD *novo = (CelulaD *)malloc(sizeof(CelulaD));

    //depositar valores de parâmetro
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = NULL;

    if (!lista) return novo; //se a lista for vazia, o novo será o primeiro e único elemento nela

    //listas duplas, sempre que usarmos, precisamos garantir que o controle esteja no início
    for ( ; lista->ant; lista = lista->ant);

    //percorrer toda a lista e inserir na última posição
    CelulaD *p;
    for (p = lista; p->prox != NULL; p = p->prox){ //percurso para parar o p no último elemento
        if (valor == p->valor) {
            free(novo);
            return lista;
        }
    }
    if (valor == p->valor) {
        free(novo);
        return lista;
    }
    //engatar na última posição
    p->prox = novo; //ultimo elemento vai apontar agora para o novo elemento alocado
    novo->ant = p; //novo elemento alocado aponta para o último elemento

    //retornar o primeiro elemento
    return lista;
}

void exibirD(CelulaD *lista) {
    CelulaD *p;

    if (!lista) {
        cout << "Lista vazia!\n";
        return;
    }
    //listas duplas, sempre que usarmos, precisamos garantir que o controle esteja no início
    for ( ; lista->ant; lista = lista->ant);
    
    for (p = lista; p != NULL; p = p->prox) { //percurso clássico em listas
        cout << p->valor << "\t";
    }
    cout << endl;
}

int contarElementosD(CelulaD *lista) { //lista contém o endereco do 1o elemento
   CelulaD *p;
   int contador = 0;

    if (!lista) {
        return contador;
    }

    //listas duplas, sempre que usarmos, precisamos garantir que o controle esteja no início
    for ( ; lista->ant; lista = lista->ant);

    for (p = lista; p != NULL; p = p->prox) { //percurso clássico em listas
        contador++;
    } 
    return contador;
}

CelulaD *localizarValorD(int valor, CelulaD *lista) {
    if (!lista) {
        cout << "Lista vazia!" << endl;
        return lista;
    }

    //listas duplas, sempre que usarmos, precisamos garantir que o controle esteja no início
    for ( ; lista->ant; lista = lista->ant);

    CelulaD *p;
    for (p = lista; p != NULL; p = p->prox) { //percurso clássico em listas
        if (valor == p->valor) {
            return p;
        }
    } 
    return NULL;
}