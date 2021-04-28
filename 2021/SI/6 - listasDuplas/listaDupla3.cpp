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
string localizarValorD(int valor, CelulaD *lista);
int maiorElemento(CelulaD *lista);

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

    cout << localizarValorD(valor, lista) << endl;

    cout << "O maior elemento da lista é: " << maiorElemento(lista) << endl;

    return 1;
}

int maiorElemento(CelulaD *lista) {
    if (!lista) return -27;

    CelulaD *p;
    for (p = lista->prox; p; p = p->prox);
    
    return p->valor;    
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
    CelulaD *p, *pR;
    for (pR = NULL, p = lista; p != NULL; pR = p, p = p->prox){ 
        if (valor < p->valor) {
            break;
        }
    }
    //primeiro
    if (p == lista) {
        novo->prox = lista;
        lista->ant = novo;
        return novo;
    }
    //ultimo
    if (!p) {
        pR->prox = novo;
        novo->ant = pR;
        return lista;
    }
    //entao so pode estar no meio

    pR->prox = novo;
    novo->ant = pR;
    novo->prox = p;
    p->ant = novo;

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

string localizarValorD(int valor, CelulaD *lista) {
    if (!lista) {
        return "Lista vazia!";
    }

    //listas duplas, sempre que usarmos, precisamos garantir que o controle esteja no início
    for ( ; lista->ant; lista = lista->ant);

    CelulaD *p;
    bool encontrou = false;
    for (p = lista; p != NULL; p = p->prox) { //percurso clássico em listas
        if (valor == p->valor) {
            encontrou = true;
            break;
        }
    } 
    if (!encontrou) return "Valor não localizado na lista";

    //se é o primeiro
    if (p == lista) {
        return "Valor localizado na primeira posição";
    }
    //se é o último
    if (p->prox == NULL) {
        return "Valor localizado na última posição";
    }
    //se não é o primeiro e nem o último, só pode estar no meio
    return "Valor localizado em alguma posição do meio da lista";
}